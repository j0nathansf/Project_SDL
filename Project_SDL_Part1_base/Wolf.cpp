#include "Animal.h"
#include "Wolf.h"
#include <cstdio>
#include <SDL2/SDL_image.h>

Wolf::Wolf(int x, int y, SDL_Renderer *renderer) : Animal(x, y, renderer, IMG_Load("./media/wolf.png"))
{
}

Wolf::~Wolf()
{
}

void Wolf::move()
{
    int direction = rand() % 4;
    int speed = rand() % 3 + 5;
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