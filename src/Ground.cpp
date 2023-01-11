#include "Ground.h"
#include "Sheep.h"
#include "Wolf.h"
#include "constants.h"
#include <cstdio>

Ground::Ground(SDL_Renderer *renderer)
{
    this->frameRate = 60;
    this->animals = std::vector<Animal *>();
    this->renderer = renderer;
    this->initAnimals();
}

Ground::~Ground()
{
    printf("Ground destroyed\n");
}

void Ground::initAnimals()
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

        if (SDL_GetTicks() >= 10000)
        {
            quit = true;
        }

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);

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