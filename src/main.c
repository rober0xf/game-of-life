#include "../include/game.h"
#include "../include/grid.h"
#include "../include/constants.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = create_window(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    SDL_Surface *surface = init_window_surface(window);
    if (!surface) { // if its NULL
        SDL_Log("error getting the surface: %s\n", SDL_GetError());
        return -1;
    }

    int *matrix = (int *)malloc(rows * cols * sizeof(int));
    if (!matrix) {
        fprintf(stderr, "error allocating memory for the matrix. \n");
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    init_matrix(rows, cols, matrix); // matrix is pointing to the first elem
    draw_matrix(surface, rows, cols, matrix);

    SDL_UpdateWindowSurface(window); // we need to refresh the surface to see the rect
    SDL_Delay(3000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
