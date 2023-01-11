#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.h"
#include "constants.h"
#include <cstdio>

Player::Player(int x, int y, int velocity, SDL_Renderer *renderer) : Entity(x, y, velocity, renderer, IMG_Load("./media/player.png"))
{
    this->srcR = {0, 0, SHAPE_SIZE, SHAPE_SIZE};
    this->lifeTime = rand() % 3000 + 10000000;
    this->birthTime = SDL_GetTicks();
}

Player::~Player()
{
}

void Player::draw()
{
    SDL_Rect destR;

    destR.x = this->x;
    destR.y = this->y;
    destR.w = SHAPE_SIZE;
    destR.h = SHAPE_SIZE;

    SDL_RenderCopy(renderer, this->texture, &this->srcR, &destR);
    SDL_RenderPresent(renderer);
}

void Player::move()
{
    int direction = rand() % 4;
    int speed = rand() % 3 + 1;
    switch (direction)
    {
    case 0:
        this->x += speed;
        break;
    case 1:
        this->x -= speed;
        break;
    case 2:
        this->y += speed;
        break;
    case 3:
        this->y -= speed;
        break;
    }
}

int Player::isAlive()
{
    return SDL_GetTicks() - this->birthTime < this->lifeTime;
}