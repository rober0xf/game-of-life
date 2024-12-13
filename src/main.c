#include "../include/game.h"
#include "../include/grid.h"

#define TITLE "game of life"
#define WIDTH 900
#define HEIGHT 600
int cell_size = 10;

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = create_window(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    SDL_Surface *surface = init_window_surface(window);
    if (!surface) { // if its NULL
        SDL_Log("error getting the surface: %s\n", SDL_GetError());
        return -1;
    }

    int x_cell = (WIDTH - cell_size) / 2;
    int y_cell = (HEIGHT - cell_size) / 2;
    Uint32 red = SDL_MapRGB(surface->format, 255, 0, 0); // we need to define with this format

    int result = draw_cell(surface, x_cell, y_cell, cell_size, red);
    if (result != 0) {
        SDL_Log("error drawing the cell: %s\n", SDL_GetError());
    }

    SDL_UpdateWindowSurface(window); // we need to refresh the surface to see the rect

    SDL_Delay(5000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
