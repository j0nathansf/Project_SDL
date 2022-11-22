#include "Animal.h"

#pragma once

class Sheep : public Animal
{
public:
    Sheep(int x, int y, SDL_Renderer *renderer);
    ~Sheep();
    void move();
};