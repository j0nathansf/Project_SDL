#include <SDL2/SDL.h>
#include <vector>
#include "Entity.h"

#pragma once

class Ground
{
public:
    Ground(SDL_Renderer *renderer);
    ~Ground();
    void loop();
    void init();

private:
    unsigned int frameRate;
    std::vector<Entity *> animals;
    Entity *player;
    SDL_Renderer *renderer;
};