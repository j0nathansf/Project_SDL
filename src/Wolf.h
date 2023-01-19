#include "Animal.h"

#pragma once

class Wolf : public Animal
{
public:
    Wolf(int x, int y, int velocity, SDL_Surface *surface_ptr);
    ~Wolf();
    void move(int direction = -1);
    void action();
};