#ifndef GRID_H_
#define GRID_H_

#include <SDL2/SDL.h>

SDL_Window *create_window(const char *title, int x, int y, int width, int height, Uint32 flags);
int draw_cell(SDL_Surface *surface, int x, int y, int cell_size, Uint32 color);

// extern permite declarar la variable sin definirla aca.
extern SDL_Surface *init_window_surface(SDL_Window *window);

#endif // GRID_H_
