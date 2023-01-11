#include "Animal.h"

#pragma once

class Sheep : public Animal
{
public:
    Sheep(int x, int y, int velocity, SDL_Renderer *renderer);
    ~Sheep();
    void move();
};