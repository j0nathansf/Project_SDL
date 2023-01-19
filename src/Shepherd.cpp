#include <SDL2/SDL.h>
#include "Shepherd.h"
#include "constants.h"
#include <cstdio>

Shepherd::Shepherd(int x, int y, int velocity, SDL_Surface *surface_ptr) : Entity(x, y, velocity, surface_ptr, "./media/player.png")
{
    this->srcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
    this->lifeTime = rand() % 3000 + 10000000;
    this->birthTime = SDL_GetTicks();
}

Shepherd::~Shepherd()
{
}

void Shepherd::draw()
{
    SDL_Rect destR;

    destR.x = this->x;
    destR.y = this->y;
    destR.w = SHAPE_SIZE;
    destR.h = SHAPE_SIZE;

    SDL_BlitScaled(this->texture, NULL, this->surface, &destR);
}

void Shepherd::move(const std::vector<Entity *> entities, int direction)
{
    int speed = SHAPE_SIZE / 16;
    switch (direction)
    {
    case 0:
        Entity::step(speed, 0);
        break;
    case 1:
        Entity::step(-speed, 0);
        break;
    case 2:
        Entity::step(0, speed);
        break;
    case 3:
        Entity::step(0, -speed);
        break;
    }
}

int Shepherd::isAlive()
{
    return SDL_GetTicks() - this->birthTime < this->lifeTime;
}

std::string Shepherd::name()
{
    return "Shepherd";
}