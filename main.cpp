// ### RULES OF THE GAME OF LIFE ###
// 1. Underpopulation: a live cell with fewer than two neighbours dies
// 2. Stasis: a live cell with two or three neighbours lives to the next generation
// 3. Overpopulation: a live cell with more than three neighbours dies
// 4. Reproduction: a dead cell with exactly three neighbours becomes a live cell

#include "sim.hpp"
#include <raylib.h>
#include <iostream>

int main() {
    Color colorGrey = {29, 29, 29, 255};
    const int windowHeight = 750;
    const int windowWidth = 750;
    const int cellSize = 25;
    const int targetFPS = 15;

    InitWindow(windowWidth, windowHeight, "Game of Life"); // initialize window
    SetTargetFPS(targetFPS); // set target fps for window
    Simulation sim{windowWidth, windowHeight, cellSize};
    sim.setCellValue(3, 4, 1);
    sim.setCellValue(3, 5, 1);
    sim.setCellValue(2, 4, 1);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(colorGrey);
        sim.Draw();
        EndDrawing();
    }

    return 0;
}
