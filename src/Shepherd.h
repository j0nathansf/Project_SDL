#include "Entity.h"

#pragma once

class Shepherd : public Entity
{
public:
    Shepherd(int x, int y, int velocity, SDL_Renderer *renderer);
    ~Shepherd();
    void move(Direction direction);
    void draw();
    int isAlive();

protected:
    SDL_Rect srcR;
    Uint32 lifeTime;
    Uint32 birthTime;
};
