#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>

void init_matrix(int row, int col, int *matrix);
void draw_matrix(SDL_Surface *surface, int row, int col, int *matrix);

#endif // GAME_H_
