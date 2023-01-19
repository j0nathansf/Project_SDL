#include "Animal.h"
#include "Wolf.h"
#include <cstdio>

Wolf::Wolf(int x, int y, int velocity, SDL_Surface *surface_ptr) : Animal(x, y, velocity, surface_ptr, "./media/wolf.png", MALE)
{
}

Wolf::~Wolf()
{
}

void Wolf::move(const std::vector<Entity *> entities, int direction)
{
    int moveX = -8 + (rand() % static_cast<int>(17));
    int moveY = -8 + (rand() % static_cast<int>(17));
    Entity::step(moveX, moveY);
}

void Wolf::action()
{
}