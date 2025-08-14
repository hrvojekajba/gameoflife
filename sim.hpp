#pragma once
#include "grid.hpp"
#include <utility>

class Simulation {
    public:
        Simulation(int width, int height, int cell_size) : grid(width, height, cell_size) {};
        void Draw() {
            grid.Draw();
        };
        void setCellValue(int row, int column, int value) {
            grid.setValue(row, column, value);
        };
        // cell neighbours are the cells that are directly next to the live cell, be it horizontally,
        // vertically or diagonally
        int countLiveNeighbours(int row, int column) {
            int liveNeigbours = 0;
            //vector of pairs that hold the cell neighbour index offsets
            std::vector<std::pair<int, int>> neighbourOffset = {
                {-1, 0}, // above
                {1, 0}, // below
                {0, -1}, // left
                {0, 1}, // right
                {-1, -1}, // diagonal upper left
                {-1, 1}, // diagonal upper right
                {1, -1}, // diagonal lower left
                {1, 1} // diagonal lower right
            };

            for (const auto& offset : neighbourOffset) {
                int neighbourRow = row + offset.first;
                int neigbourColumn = column + offset.second;
                liveNeigbours += grid.getValue(neighbourRow, neigbourColumn);
            }
            return liveNeigbours;
        }

    private:
        Grid grid;
};
