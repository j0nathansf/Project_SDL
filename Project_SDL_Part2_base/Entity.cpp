#include <SDL2/SDL.h>
#include "Entity.h"
#include "constants.h"
#include <cstdio>

Entity::Entity(int x, int y, int velocity, SDL_Renderer *renderer, SDL_Surface *texture_image)
{
    this->x = x;
    this->y = y;
    this->velocity = velocity;
    this->renderer = renderer;
    this->texture = SDL_CreateTextureFromSurface(renderer, texture_image);
}

Entity::~Entity()
{
}