#include "Animal.h"

#pragma once

class Dog : public Animal
{
public:
    Dog(int x, int y, int velocity, SDL_Surface *surface_ptr);
    ~Dog();
    void move(const std::vector<Entity *> entities, int direction = -1);
    std::string name();
    void action();
};