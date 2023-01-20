#include "Animal.h"
#include "constants.h"

#pragma once

class Dog : public Animal
{
public:
    Dog(int x, int y, int velocity, SDL_Surface *surface_ptr, Entity *player);
    ~Dog();
    void move(const std::vector<Entity *> entities, int direction = -1);
    std::string name();
    std::tuple<std::string, int> action(std::vector<Entity *> entities);

private:
    Entity *player;
};
