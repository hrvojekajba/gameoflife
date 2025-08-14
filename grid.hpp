#pragma once
#include <raylib.h>
#include <vector>

class Grid {
    public:
        // define class constructor -- we use an initializer list to intialize the
        // private variables
        Grid(int width, int height, int cellSize) : rows(height / cellSize), columns(width / cellSize),
            cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {};
            // initialize cells -- which is a vector of vectors of integers,
            // number of vectors is rows, and each row is a vector that contains
            // a columns number of elements

        void Draw() {
            for (int row = 0; row < rows; row++) {
                for (int column = 0; column < columns; column++) {
                    // assigns green to cell that holds a non zero value
                    Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
                    // draw rectangle for each cell
                    DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
                }
            }
        }

        bool isWithinBounds(int row, int column) {
            if (row >= 0 && row < rows && column >= 0 && column < columns) {
                return true;
            } else {
                return false;
            }
        }

        void setValue(int row, int column, int value) {
            if (isWithinBounds(row, column)) {
                cells[row][column] = value;
            }
        }

        int getValue(int row, int column) {
            if (isWithinBounds(row, column)) {
                return cells[row][column];
            }
            return 0;
        }
    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<int>> cells;
};
