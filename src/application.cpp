#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ostream>
#include "Sheep.h"
#include "Wolf.h"
#include "Ground.h"
#include "constants.h"

int main(int argc, char *args[])
{
    std::cout << "Starting up the application" << std::endl;

    if (argc != 4)
        throw std::runtime_error("Need three arguments - "
                                 "number of sheep, number of wolves, "
                                 "simulation time in seconde\n");

    SDL_Window *window = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Could not initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow(
        "Project SDL",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    Ground *g = new Ground(surface, window, std::stoul(args[1]), std::stoul(args[2]));
    g->loop(std::stoul(args[3]));
    int score = g->compute_score();

    std::cout << "Score : " << score << "." << std::endl;

    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
