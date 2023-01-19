#include "Animal.h"

#pragma once

class Sheep : public Animal
{
public:
    Sheep(int x, int y, int velocity, SDL_Surface *surface_ptr, bool is_male);
    ~Sheep();
    void move(int direction = -1);
    void action();
};