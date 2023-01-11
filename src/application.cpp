#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "Sheep.h"
#include "Wolf.h"
#include "Ground.h"
#include "constants.h"

int main(int argc, char *args[])
{
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
        0);

    if (window == NULL)
    {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    Ground *g = new Ground(renderer);
    g->loop();

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

int WinMain()
{
    main(0, NULL);
    return 0;
}