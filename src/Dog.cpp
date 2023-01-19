#include "Animal.h"
#include "Dog.h"
#include <cstdio>
#include <SDL2/SDL.h>

Dog::Dog(int x, int y, int velocity, SDL_Surface *surface_ptr) : Animal(x, y, velocity, surface_ptr, "./media/dog.png", MALE)
{
}

Dog::~Dog()
{
}

void Dog::move(const std::vector<Entity *> entities, int direction)
{
    int moveX = -8 + (rand() % static_cast<int>(17));
    int moveY = -8 + (rand() % static_cast<int>(17));
    Entity::step(moveX, moveY);
}

void Dog::action()
{
}

std::string Dog::name()
{
    return "Dog";
}