#include "Animal.h"

#pragma once

class Wolf : public Animal
{
public:
    Wolf(int x, int y, int velocity, SDL_Surface *surface_ptr, Uint32 life_time);
    ~Wolf();
    void move(const std::vector<Entity *> entities, int direction);
    std::string name();
    void action();
};