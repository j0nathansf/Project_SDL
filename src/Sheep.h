#include "Animal.h"
#include "constants.h"

#pragma once

class Sheep : public Animal
{
public:
    Sheep(int x, int y, int velocity, SDL_Surface *surface_ptr, bool is_male);
    ~Sheep();
    void move(const std::vector<Entity *> entities, int direction);
    std::string name();
    void action();
};