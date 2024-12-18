#include "../include/grid.h"

SDL_Window *create_window(const char *title, int x, int y, int width, int height, Uint32 flags) {
    SDL_Window *win = SDL_CreateWindow(title, x, y, width, height, flags);

    if (win == NULL) {
        printf("error creating window: %s\n", SDL_GetError());
    }

    return win;
}

// we define the global variable
SDL_Surface *window_surface = NULL;

// initialize the surface
SDL_Surface *init_window_surface(SDL_Window *window) {
    window_surface = SDL_GetWindowSurface(window);
    return window_surface;
}

int draw_cell(SDL_Surface *surface, int x, int y, int cell_size, Uint32 color) {
    if (!surface) {
        SDL_Log("error drawing cell");
        return -1;
    }

    // the magic numbers are just to leave a teeny tiny space between each cell
    SDL_Rect rect = {x * cell_size + 1, y * cell_size + 1, cell_size - 1, cell_size - 1}; // x, y, w, h

    if (SDL_FillRect(surface, &rect, color) != 0) {
        SDL_Log("error fill rect failed: %s", SDL_GetError());
        return -1;
    }
    return 0;
}
