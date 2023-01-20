#include <SDL2/SDL.h>
#include "Animal.h"
#include "constants.h"
#include <cstdio>

Animal::Animal(int x, int y, int velocity, SDL_Surface *surface_ptr, const std::string &texture_image, Gender gender, Uint32 life_time) : Entity(x, y, velocity, surface_ptr, texture_image)
{
    this->srcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
    this->birth_time = SDL_GetTicks();
    this->life_time = life_time;
    this->gender = gender;
}

Animal::~Animal()
{
}

void Animal::draw()
{
    SDL_Rect destR;

    destR.x = this->get_x();
    destR.y = this->get_y();
    destR.w = SHAPE_SIZE;
    destR.h = SHAPE_SIZE;

    SDL_BlitScaled(this->get_texture(), NULL, this->get_surface(), &destR);
}

int Animal::isAlive()
{
    return SDL_GetTicks() - this->birth_time < this->life_time;
}