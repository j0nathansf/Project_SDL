#include <SDL2/SDL.h>
#include <vector>
#include "Entity.h"

#pragma once

class Ground
{
public:
    Ground(SDL_Surface *surface_ptr, SDL_Window *window_ptr);
    ~Ground();
    void loop();
    void init();

private:
    unsigned int frameRate;
    std::vector<Entity *> animals;
    Entity *player;
    SDL_Surface *surface;
    SDL_Window *window;
};