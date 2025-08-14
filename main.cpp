// ### RULES OF THE GAME OF LIFE ###
// 1. Underpopulation: a live cell with fewer than two neighbours dies
// 2. Stasis: a live cell with two or three neighbours lives to the next generation
// 3. Overpopulation: a live cell with more than three neighbours dies
// 4. Reproduction: a dead cell with exactly three neighbours becomes a live cell

#include "sim.hpp"
#include <raylib.h>

int main() {
    Color color_grey = {29, 29, 29, 255};
    const int window_height = 750;
    const int window_width = 750;
    const int cell_size = 25;
    const int target_fps = 15;

    InitWindow(window_width, window_height, "Game of Life"); // initialize window
    SetTargetFPS(target_fps); // set target fps for window
    Simulation sim{window_width, window_height, cell_size};

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(color_grey);
        sim.draw();
        EndDrawing();
    }

    return 0;
}
