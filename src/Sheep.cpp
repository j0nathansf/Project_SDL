#include "Animal.h"
#include "Sheep.h"
#include "constants.h"
#include <cstdio>
#include <SDL2/SDL.h>

Sheep::Sheep(int x, int y, int velocity, SDL_Surface *surface_ptr) : Animal(x, y, velocity, surface_ptr, "./media/sheep.png")
{
}

Sheep::~Sheep()
{
}

void Sheep::move(int direction)
{
    int moveX = -8 + (rand() % static_cast<int>(17));
    int moveY = -8 + (rand() % static_cast<int>(17));
    x += moveX;
    y += moveY;
    if (x < 0)
        x = 0;
    if (x + SHAPE_SIZE >= SCREEN_WIDTH)
        x = SCREEN_WIDTH - SHAPE_SIZE;
    if (y < 0)
        y = 0;
    if (y + SHAPE_SIZE >= SCREEN_HEIGHT)
        y = SCREEN_HEIGHT - SHAPE_SIZE;
}