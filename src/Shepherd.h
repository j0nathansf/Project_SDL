#include "Entity.h"

#pragma once

class Shepherd : public Entity
{
public:
    Shepherd(int x, int y, int velocity, SDL_Surface *surface_ptr);
    ~Shepherd();
    void move(int direction = -1);
    void draw();
    int isAlive();

protected:
    SDL_Rect srcR;
    Uint32 lifeTime;
    Uint32 birthTime;
};
