#include <SDL2/SDL.h>
#include "Entity.h"

#pragma once

class Animal : public Entity
{
public:
    Animal(int x, int y, int velocity, SDL_Surface *surface_ptr, const std::string &texture_image);
    virtual ~Animal();
    virtual void move(int direction = -1) = 0;
    void draw();
    int isAlive();

protected:
    SDL_Rect srcR;
    Uint32 birthTime;
    Uint32 lifeTime;
};
