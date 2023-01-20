#include "Entity.h"
#include <tuple>

#pragma once

class Shepherd : public Entity
{
public:
    Shepherd(int x, int y, int velocity, SDL_Surface *surface_ptr);
    ~Shepherd();
    void move(const std::vector<Entity *> entities, int direction = -1);
    std::string name();
    void draw();
    std::tuple<std::string, int> action(std::vector<Entity *> entities);

protected:
    SDL_Rect srcR;
    Uint32 life_time;
    Uint32 birth_time;
};
