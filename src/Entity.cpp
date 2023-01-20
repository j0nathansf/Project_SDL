#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.h"
#include "constants.h"
#include <cstdio>

Entity::Entity(int x, int y, int velocity, SDL_Surface *surface_ptr, const std::string &texture_image, Uint32 life_time)
{
    this->x = x;
    this->y = y;
    this->velocity = velocity;
    this->surface = surface_ptr;
    this->texture = IMG_Load(texture_image.c_str());
    this->birth_time = SDL_GetTicks();
    this->life_time = life_time;
}

Entity::~Entity()
{
    SDL_FreeSurface(this->texture);
}

bool Entity::is_near(Entity *entity)
{
    double distance = sqrt(pow(entity->x - this->x, 2) + pow(entity->y - this->y, 2));
    return distance <= ENTITY_RANGE;
}

int Entity::compute_distance(Entity *entity)
{
    double distance = sqrt(pow(entity->x - this->x, 2) + pow(entity->y - this->y, 2));
    return (int)distance;
}

void Entity::step(int move_x, int move_y)
{
    this->x += move_x;
    this->y += move_y;
    if (this->x < 0)
        this->x = 0;
    if (this->x + SHAPE_SIZE >= SCREEN_WIDTH)
        this->x = SCREEN_WIDTH - SHAPE_SIZE;
    if (this->y < 0)
        this->y = 0;
    if (this->y + SHAPE_SIZE >= SCREEN_HEIGHT)
        this->y = SCREEN_HEIGHT - SHAPE_SIZE;
}

int Entity::get_x()
{
    return this->x;
}

int Entity::get_y()
{
    return this->y;
}

int Entity::get_velocity()
{
    return this->velocity;
}

void Entity::set_velocity(int new_velocity)
{
    this->velocity = new_velocity;
}

SDL_Surface *Entity::get_surface()
{
    return this->surface;
}

SDL_Surface *Entity::get_texture()
{
    return this->texture;
}

Uint32 Entity::get_birth_time()
{
    return this->birth_time;
}

Uint32 Entity::get_life_time()
{
    return this->life_time;
}

bool Entity::is_alive()
{
    return SDL_GetTicks() - this->birth_time < this->life_time;
}