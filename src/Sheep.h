#include "Animal.h"

#pragma once

class Sheep : public Animal
{
public:
    Sheep(int x, int y, int velocity, SDL_Surface *surface_ptr);
    ~Sheep();
    void move(int direction = -1);
};