#include "Player.h"
#include "Ground.h"
#include "Sheep.h"
#include "Wolf.h"
#include "constants.h"
#include <cstdio>

Ground::Ground(SDL_Renderer *renderer)
{
    this->frameRate = 60;
    this->animals = std::vector<Entity *>();
    this->player = new Player(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, renderer);
    this->renderer = renderer;
    this->init();
}

Ground::~Ground()
{
    printf("Ground destroyed\n");
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
                case SDLK_LEFT:
                    this->player->move();
                    break;
                case SDLK_RIGHT:
                    this->player->move();
                    break;
                case SDLK_UP:
                    this->player->move();
                    break;
                case SDLK_DOWN:
                    this->player->move();
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
        }

        SDL_RenderClear(renderer);

        this->player->draw();

        for (size_t i = 0; i < this->animals.size(); i++)
        {
            this->animals[i]->move();
            this->animals[i]->draw();

            // if animal is dead, remove it from the vector and create a new one
            if (!this->animals[i]->isAlive())
            {
                this->animals.erase(this->animals.begin() + i);

                // 50% chance to create a sheep, 50% chance to create a wolf
                if (rand() % 2 == 0)
                {
                    this->animals.push_back(new Sheep(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, this->renderer));
                }
                else
                {
                    this->animals.push_back(new Wolf(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, this->renderer));
                }
            }
        }

        SDL_Delay(1000 / this->frameRate);
    }
}