#include "Shepherd.h"
#include "Ground.h"
#include "Sheep.h"
#include "Wolf.h"
#include "constants.h"
#include <cstdio>

Ground::Ground(SDL_Surface *surface_ptr, SDL_Window *window_ptr)
{
    this->frameRate = 60;
    this->animals = std::vector<Entity *>();
    this->player = new Shepherd(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, surface_ptr);
    this->surface = surface_ptr;
    this->window = window_ptr;
    this->init();
}

Ground::~Ground()
{
}

void Ground::init()
{
    for (int i = 0; i < 3; i++)
    {
        this->animals.push_back(new Sheep(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, this->surface));
    }

    for (int i = 0; i < 3; i++)
    {
        this->animals.push_back(new Wolf(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, this->surface));
    }
}

void Ground::loop()
{

    SDL_Event event;
    bool quit = false;
    SDL_Rect field = SDL_Rect{0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_d:
                case SDLK_RIGHT:
                    this->player->move(0);
                    break;
                case SDLK_a:
                case SDLK_LEFT:
                    this->player->move(1);
                    break;
                case SDLK_s:
                case SDLK_DOWN:
                    this->player->move(2);
                    break;
                case SDLK_w:
                case SDLK_UP:
                    this->player->move(3);
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

        SDL_FillRect(surface, &field, SDL_MapRGB(surface->format, 0, 255, 0));

        this->player->draw();

        for (size_t i = 0; i < this->animals.size(); i++)
        {
            this->animals[i]->move();
            this->animals[i]->draw();
        }

        SDL_UpdateWindowSurface(window);
        SDL_Delay(1000 / this->frameRate);
    }
}