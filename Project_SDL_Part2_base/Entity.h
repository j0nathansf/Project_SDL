#include <SDL2/SDL.h>

#pragma once

class Entity
{
public:
    Entity(int x, int y, int velocity, SDL_Renderer *renderer, SDL_Surface *texture_image);
    virtual ~Entity();
    virtual void move() = 0;

protected:
    int x;
    int y;
    int velocity;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
};
