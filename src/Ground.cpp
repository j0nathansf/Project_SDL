#include "Shepherd.h"
#include "Ground.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Dog.h"
#include "constants.h"
#include <cstdio>

Ground::Ground(SDL_Surface *surface_ptr, SDL_Window *window_ptr, unsigned n_sheep, unsigned n_wolf)
{
    this->frameRate = 60;
    this->animals = std::vector<Entity *>();
    this->n_sheep = n_sheep;
    this->n_wolf = n_wolf;
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
    this->animals.push_back(new Dog(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, this->surface, this->player));
    for (int i = 0; i < n_sheep; i++)
        this->animals.push_back(new Sheep(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, this->surface, rand() % 2));
    for (int i = 0; i < n_wolf; i++)
        this->animals.push_back(new Wolf(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 2, this->surface, rand() % 3000 + 7000));
}

void Ground::loop(unsigned period)
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
                    this->player->move(animals, 0);
                    break;
                case SDLK_a:
                case SDLK_LEFT:
                    this->player->move(animals, 1);
                    break;
                case SDLK_s:
                case SDLK_DOWN:
                    this->player->move(animals, 2);
                    break;
                case SDLK_w:
                case SDLK_UP:
                    this->player->move(animals, 3);
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

        if (SDL_GetTicks() >= period)
        {
            quit = true;
            break;
        }

        SDL_FillRect(surface, &field, SDL_MapRGB(surface->format, 60, 98, 85));

        this->player->draw();

        for (size_t i = 0; i < this->animals.size(); i++)
        {
            std::tuple<std::string, int> res;
            if (!this->animals[i]->isAlive())
                this->animals.erase(this->animals.begin() + i);
            this->animals[i]->move(animals);
            res = this->animals[i]->action(animals);
            this->animals[i]->draw();
        }

        SDL_UpdateWindowSurface(window);
        SDL_Delay(1000 / this->frameRate);
    }
}

int Ground::compute_score()
{
    int result = 0;
    std::string target = "Sheep";
    for (size_t i = 0; i < this->animals.size(); i++)
    {
        if (!target.compare(this->animals[i]->name()))
            result += 1;
    }
    return result;
}
