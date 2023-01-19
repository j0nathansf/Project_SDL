#include "Animal.h"
#include "Wolf.h"
#include <cstdio>

Wolf::Wolf(int x, int y, int velocity, SDL_Surface *surface_ptr) : Animal(x, y, velocity, surface_ptr, "./media/wolf.png", MALE)
{
}

Wolf::~Wolf()
{
}

void Wolf::move(int direction)
{
    Animal::default_move();
}

void Wolf::action()
{
}