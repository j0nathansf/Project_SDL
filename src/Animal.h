#include <SDL2/SDL.h>
#include <tuple>
#include "Entity.h"

#pragma once

enum Gender
{
    MALE = 0,
    FEMALE = 1,
};

class Animal : public Entity
{
public:
    Animal(int x, int y, int velocity, SDL_Surface *surface_ptr, const std::string &texture_image, Gender gender, Uint32 life_time);
    virtual ~Animal();
    virtual void move(const std::vector<Entity *> entities, int direction = -1) = 0;
    virtual std::tuple<std::string, int> action(std::vector<Entity *> entities) = 0;
    virtual std::string name() = 0;
    void draw();
    int isAlive();

protected:
    SDL_Rect srcR;
    Uint32 birth_time;
    Uint32 life_time;
    Gender gender;
};
