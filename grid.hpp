#pragma once
#include <raylib.h>
#include <vector>

class Grid {
    public:
        Grid(int width, int height, int cellSize) : rows(height / cellSize), columns(width / cellSize),
            cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {};

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
        // check if given cell is within board bounds
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

        int getRows() {
            return rows;
        }

        int getColumns() {
            return columns;
        }

        void fillRandom() {
            for (int row = 0; row < rows; row++) {
                for (int column = 0; column < columns; column++) {
                    int randomValue = GetRandomValue(0, 5);
                    cells[row][column] = (randomValue == 5) ? 1 : 0;
                }
            }
        }

        void clearGrid() {
            for (int row = 0; row < rows; row++) {
                for (int column = 0; column < columns; column++) {
                    cells[row][column] = 0;
                }
            }
        }

        void toggleCell(int row, int column) {
            if (isWithinBounds(row, column)) {
                cells[row][column] = !cells[row][column];
            }
        }

    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<int>> cells;
};
