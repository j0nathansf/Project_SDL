#include "Shepherd.h"
#include "Ground.h"
#include "Sheep.h"
#include "Wolf.h"
#include "constants.h"
#include <cstdio>

Ground::Ground(SDL_Renderer *renderer)
{
    this->frameRate = 60;
    this->animals = std::vector<Entity *>();
    this->player = new Shepherd(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, renderer);
    this->renderer = renderer;
    this->init();
}

Ground::~Ground()
{
}

void Ground::init()
{
    for (int i = 0; i < 3; i++)
    {
        this->animals.push_back(new Sheep(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, this->renderer));
    }

    for (int i = 0; i < 3; i++)
    {
        this->animals.push_back(new Wolf(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, this->renderer));
    }
}

void Ground::loop()
{

    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_a:
                case SDLK_LEFT:
                    this->player->move(LEFT);
                    break;
                case SDLK_d:
                case SDLK_RIGHT:
                    this->player->move(RIGHT);
                    break;
                case SDLK_w:
                case SDLK_UP:
                    this->player->move(UP);
                    break;
                case SDLK_s:
                case SDLK_DOWN:
                    this->player->move(DOWN);
                    break;
                default:
                    break;
                }
            }
            else if (event.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
        }

        if (SDL_GetTicks() >= 10000)
        {
            quit = true;
            break;
        }

        SDL_RenderClear(renderer);

        this->player->draw();

        for (size_t i = 0; i < this->animals.size(); i++)
        {
            enum Direction random_direction = static_cast<Direction>(rand() % DOWN);
            this->animals[i]->move(random_direction);
            this->animals[i]->draw();
        }

        SDL_Delay(1000 / this->frameRate);
    }
}