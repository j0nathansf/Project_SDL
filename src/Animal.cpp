#include <SDL2/SDL.h>
#include "Animal.h"
#include "constants.h"
#include <cstdio>

Animal::Animal(int x, int y, int velocity, SDL_Surface *surface_ptr, const std::string &texture_image, Gender gender) : Entity(x, y, velocity, surface_ptr, texture_image)
{
    this->srcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
    this->birthTime = SDL_GetTicks();
    // life time between 2 and 5 seconds
    this->lifeTime = rand() % 3000 + 2000;
    this->gender = gender;
}

Animal::~Animal()
{
}

void Animal::draw()
{
    SDL_Rect destR;

    destR.x = this->x;
    destR.y = this->y;
    destR.w = SHAPE_SIZE;
    destR.h = SHAPE_SIZE;

    SDL_BlitScaled(this->texture, NULL, this->surface, &destR);
}

void Animal::default_move()
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

int Animal::isAlive()
{
    return SDL_GetTicks() - this->birthTime < this->lifeTime;
}