#include "Animal.h"
#include "Wolf.h"
#include <cstdio>

Wolf::Wolf(int x, int y, int velocity, SDL_Surface *surface_ptr) : Animal(x, y, velocity, surface_ptr, "./media/wolf.png")
{
}

Wolf::~Wolf()
{
}

void Wolf::move(int direction)
{
    int test = rand() % 4;
    int speed = rand() % 3 + 1;
    switch (test)
    {
    case 0:
        this->x += speed;
        break;
    case 1:
        this->x -= speed;
        break;
    case 2:
        this->y += speed;
        break;
    case 3:
        this->y -= speed;
        break;
    }
}