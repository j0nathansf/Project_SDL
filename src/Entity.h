#include <SDL2/SDL.h>
#include <string>

#pragma once

class Entity
{
public:
    Entity(int x, int y, int velocity, SDL_Surface *surface_ptr, const std::string &texture_image);
    virtual ~Entity();
    virtual void move(int direction = -1) = 0;
    virtual void draw() = 0;
    virtual int isAlive() = 0;

protected:
    int x;
    int y;
    int velocity;
    SDL_Surface *surface;
    SDL_Surface *texture;
};
