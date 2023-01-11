#include <SDL2/SDL.h>

#pragma once

enum Direction
{
    UP = 0,
    LEFT = 1,
    RIGHT = 2,
    DOWN = 3
};

class Entity
{
public:
    Entity(int x, int y, int velocity, SDL_Renderer *renderer, SDL_Surface *texture_image);
    virtual ~Entity();
    virtual void move(Direction direction) = 0;
    virtual void draw() = 0;
    virtual int isAlive() = 0;

protected:
    int x;
    int y;
    int velocity;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
};
