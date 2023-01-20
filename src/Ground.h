#include <SDL2/SDL.h>
#include <vector>
#include "Entity.h"

#pragma once

class Ground
{
public:
    Ground(SDL_Surface *surface_ptr, SDL_Window *window_ptr, unsigned n_sheep, unsigned n_wolf);
    ~Ground();
    void loop(unsigned period);
    void init();
    int compute_score();
    void handle_action(std::tuple<std::string, int> action, int current_position);

private:
    unsigned int frameRate;
    unsigned n_sheep;
    unsigned n_wolf;
    std::vector<Entity *> animals;
    Entity *player;
    SDL_Surface *surface;
    SDL_Window *window;
};
