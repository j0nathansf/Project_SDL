#include "Animal.h"
#include "Sheep.h"
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sheep::Sheep(int x, int y, SDL_Renderer *renderer) : Animal(x, y, renderer, IMG_Load("./media/sheep.png"))
{
}

Sheep::~Sheep()
{
}

void Sheep::move()
{
    int direction = rand() % 4;
    int speed = rand() % 3 + 1;
    switch (direction)
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