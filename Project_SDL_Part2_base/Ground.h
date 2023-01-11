#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "Animal.h"

class Ground
{
public:
    Ground(SDL_Renderer *renderer);
    ~Ground();
    void loop();
    void initAnimals();

private:
    unsigned int frameRate;
    std::vector<Animal *> animals;

    SDL_Renderer *renderer;
};