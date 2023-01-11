#include <SDL2/SDL.h>
#include "Animal.h"
#include "constants.h"
#include <cstdio>

Animal::Animal(int x, int y, int velocity, SDL_Renderer *renderer, SDL_Surface *texture_image) : Entity(x, y, velocity, renderer, texture_image)
{
    this->srcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
    this->birthTime = SDL_GetTicks();
    // life time between 2 and 5 seconds
    this->lifeTime = rand() % 3000 + 2000;
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

    SDL_RenderCopy(renderer, this->texture, &this->srcR, &destR);
    SDL_RenderPresent(renderer);
}

int Animal::isAlive()
{
    return SDL_GetTicks() - this->birthTime < this->lifeTime;
}