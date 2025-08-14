#pragma once
#include "grid.hpp"

class Simulation {
    public:
        Simulation(int width, int height, int cell_size) : grid(width, height, cell_size) {};
        void draw() { grid.draw(); };
        void setCellValue(int row, int column, int value) {
            grid.setValue(row, column, value);
        };

    private:
        Grid grid;
};
