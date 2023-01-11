#include "Animal.h"
#include "Sheep.h"
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sheep::Sheep(int x, int y, int velocity, SDL_Renderer *renderer) : Animal(x, y, velocity, renderer, IMG_Load("./media/sheep.png"))
{
}

Sheep::~Sheep()
{
}

void Sheep::move(Direction direction)
{
    int speed = rand() % 3 + 1;
    switch (direction)
    {
    case RIGHT:
        this->x += speed;
        break;
    case LEFT:
        this->x -= speed;
        break;
    case DOWN:
        this->y += speed;
        break;
    case UP:
        this->y -= speed;
        break;
    }
}