#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.h"
#include "constants.h"
#include <cstdio>

Entity::Entity(int x, int y, int velocity, SDL_Surface *surface_ptr, const std::string &texture_image)
{
    this->x = x;
    this->y = y;
    this->velocity = velocity;
    this->surface = surface_ptr;
    this->texture = IMG_Load(texture_image.c_str());
}

Entity::~Entity()
{
}