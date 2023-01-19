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

void Sheep::move(int direction)
{
    Animal::default_move();
}

void Sheep::action()
{
}