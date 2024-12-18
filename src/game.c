#include "../include/game.h"
#include "../include/constants.h"
#include "../include/grid.h"

void init_matrix(int row, int col, int *matrix) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            *(matrix + i * col + j) = rand() % 2;
        }
    }
}

void draw_matrix(SDL_Surface *surface, int row, int col, int *matrix) {
    Uint32 blue = SDL_MapRGB(surface->format, 0, 255, 0); // we need to define in this format
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            if (*(matrix + i * col + j)) {
                draw_cell(surface, j, i, CELL_SIZE, blue); // we need to pass j first. (x,y) -> (j,i)
            }
        }
    }
}
