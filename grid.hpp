#pragma once
#include <raylib.h>
#include <vector>

class Grid {
    public:
        // define class constructor -- we use an initializer list to intialize the
        // private variables
        Grid(int width, int height, int cell_size) : rows(height / cell_size), columns(width / cell_size),
            cell_size(cell_size), cells(rows, std::vector<int>(columns, 0)) {};
            // initialize cells -- which is a vector of vectors of integers,
            // number of vectors is rows, and each row is a vector that contains
            // a columns number of elements

        void draw() {
            for (int row = 0; row < rows; row++) {
                for (int column = 0; column < columns; column++) {
                    // assigns green to cell that holds a non zero value
                    Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
                    // draw rectangle for each cell
                    DrawRectangle(column * cell_size, row * cell_size, cell_size - 1, cell_size - 1, color);
                }
            }
        }

        void setValue(int row, int column, int value) {
            if (row >= 0 && row < rows && column >= 0 && column < columns) {
                cells[row][column] = value;
            }
        }

    private:
        int rows;
        int columns;
        int cell_size;
        std::vector<std::vector<int>> cells;
};
