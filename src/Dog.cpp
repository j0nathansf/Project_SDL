#include "Animal.h"
#include "Dog.h"
#include <cstdio>
#include <SDL2/SDL.h>

Dog::Dog(int x, int y, int velocity, SDL_Surface *surface_ptr, Entity *player)
    : Animal(x, y, velocity, surface_ptr, "./media/dog.png", MALE, DEFAULT_LIFE_TIME)
{
    this->player = player;
}

Dog::~Dog()
{
}

void Dog::move(const std::vector<Entity *> entities, int direction)
{
    int diff_x = (this->get_x() - this->player->get_x()) + SHAPE_SIZE;
    int diff_y = (this->get_y() - this->player->get_y()) + SHAPE_SIZE;

    int moveX = (diff_x >= 0) ? -8 : 8;
    int moveY = (diff_y >= 0) ? -8 : 8;
    Entity::step((diff_x < -8 || diff_x > 8) ? moveX : 0, (diff_y < -8 || diff_y > 8) ? moveY : 0);
}

std::tuple<std::string, int> Dog::action(std::vector<Entity *> entities)
{
    return std::make_tuple("NULL", -1);
}

std::string Dog::name()
{
    return "Dog";
}