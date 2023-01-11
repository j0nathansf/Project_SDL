#include "Entity.h"

#pragma once

class Player : public Entity
{
public:
    Player(int x, int y, int velocity, SDL_Renderer *renderer);
    ~Player();
    void move(Direction direction);
    void draw();
    int isAlive();

protected:
    SDL_Rect srcR;
    Uint32 lifeTime;
    Uint32 birthTime;
};
