#include "Animal.h"

#pragma once

class Wolf : public Animal
{
public:
    Wolf(int x, int y, int velocity, SDL_Renderer *renderer);
    ~Wolf();
    void move(Direction direction);
};