#include <SDL2/SDL.h>
#include <string>
#include <cmath>
#include <vector>

#pragma once

class Entity
{
public:
    Entity(int x, int y, int velocity, SDL_Surface *surface_ptr, const std::string &texture_image, Uint32 life_time);
    virtual ~Entity();
    virtual void move(const std::vector<Entity *> entities, int direction = -1) = 0;
    virtual void draw() = 0;
    bool is_alive();
    void step(int move_x, int move_y);
    virtual std::tuple<std::string, int> action(std::vector<Entity *> entities) = 0;
    virtual std::string name() = 0;
    int get_x();
    int get_y();
    int get_velocity();
    Uint32 get_birth_time();
    Uint32 get_life_time();
    SDL_Surface *get_surface();
    SDL_Surface *get_texture();
    void set_velocity(int new_velocity);
    void add_life_time(Uint32 additional_time);
    bool is_near(Entity *entity);
    int compute_distance(Entity *entity);

private:
    int x;
    int y;
    int velocity;
    Uint32 birth_time;
    Uint32 life_time;
    SDL_Surface *surface;
    SDL_Surface *texture;
};
