#include <SDL2/SDL.h>
#include "Entity.h"

#pragma once

class Animal : public Entity
{
public:
    Animal(int x, int y, int velocity, SDL_Renderer *renderer, SDL_Surface *texture_image);
    virtual ~Animal();
    virtual void move() = 0;
    void draw();
    int isAlive();

protected:
    SDL_Rect srcR;
    Uint32 birthTime;
    Uint32 lifeTime;
};
