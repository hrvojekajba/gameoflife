// ### RULES OF THE GAME OF LIFE ###
// 1. Underpopulation: a live cell with fewer than two neighbours dies
// 2. Stasis: a live cell with two or three neighbours lives to the next generation
// 3. Overpopulation: a live cell with more than three neighbours dies
// 4. Reproduction: a dead cell with exactly three neighbours becomes a live cell

#include "sim.hpp"
#include <raylib.h>

int main() {
    Color colorGrey = {29, 29, 29, 255};
    const int windowHeight = 1000;
    const int windowWidth = 1500;
    const int cellSize = 25;
    int targetFPS = 10;

    InitWindow(windowWidth, windowHeight, "Game of Life"); // initialize window
    SetTargetFPS(targetFPS); // set target fps for window
    Simulation sim{windowWidth, windowHeight, cellSize};

    while (WindowShouldClose() == false) {
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / cellSize;
            int column = mousePosition.x / cellSize;
            sim.toggleCell(row, column);
        }
        if (IsKeyPressed(KEY_ENTER)) {
            sim.startSimulation();
            SetWindowTitle("Game of Life is running");
        } else if (IsKeyPressed(KEY_SPACE)) {
            sim.stopSimulation();
            SetWindowTitle("Game of Life has stopped");
        } else if (IsKeyPressed(KEY_F)) {
            targetFPS += 1;
            SetTargetFPS(targetFPS);
        } else if (IsKeyPressed(KEY_S)) {
            if (targetFPS > 5) {
                targetFPS -= 1;
                SetTargetFPS(targetFPS);
            }
        } else if (IsKeyPressed(KEY_R)) {
            sim.createRandomState();
        } else if (IsKeyPressed(KEY_C)) {
            sim.clearGrid();
        }

        sim.updateState();

        BeginDrawing();
        ClearBackground(colorGrey);
        sim.Draw();
        EndDrawing();
    }

    return 0;
}
