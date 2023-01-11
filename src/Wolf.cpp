#include "Animal.h"
#include "Wolf.h"
#include <cstdio>
#include <SDL2/SDL_image.h>

Wolf::Wolf(int x, int y, int velocity, SDL_Renderer *renderer) : Animal(x, y, velocity, renderer, IMG_Load("./media/wolf.png"))
{
}

Wolf::~Wolf()
{
}

void Wolf::move(Direction direction)
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