#include <SDL2/SDL.h>

#pragma once

class Animal
{
public:
    Animal(int x, int y, SDL_Renderer *renderer, SDL_Surface *textureImage);
    virtual ~Animal();
    virtual void move() = 0;
    void draw();
    int isAlive();

protected:
    int x;
    int y;
    SDL_Renderer *renderer;
    SDL_Surface *textureImage;
    SDL_Texture *texture;
    SDL_Rect srcR;
    Uint32 birthTime;
    Uint32 lifeTime;
};
