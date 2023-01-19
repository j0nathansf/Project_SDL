#include "Animal.h"
#include "Sheep.h"
#include <cstdio>
#include <SDL2/SDL.h>

Sheep::Sheep(int x, int y, int velocity, SDL_Surface *surface_ptr, bool is_male)
    : Animal(x, y, velocity, surface_ptr, is_male ? "./media/msheep.png" : "./media/wsheep.png", is_male ? MALE : FEMALE)
{
}

Sheep::~Sheep()
{
}

void Sheep::move(const std::vector<Entity *> entities, int direction)
{
    int moveX = -8 + (rand() % static_cast<int>(17));
    int moveY = -8 + (rand() % static_cast<int>(17));
    Entity::step(moveX, moveY);
}

void Sheep::action()
{
}

std::string Sheep::name()
{
    return "Sheep";
}