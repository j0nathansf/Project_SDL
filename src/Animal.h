#include <SDL2/SDL.h>
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
    Animal(int x, int y, int velocity, SDL_Surface *surface_ptr, const std::string &texture_image, Gender gender);
    virtual ~Animal();
    virtual void move(const std::vector<Entity *> entities, int direction = -1) = 0;
    virtual void action() = 0;
    virtual std::string name() = 0;
    void draw();
    int isAlive();

protected:
    SDL_Rect srcR;
    Uint32 birthTime;
    Uint32 lifeTime;
    Gender gender;
};
