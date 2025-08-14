#pragma once
#include "grid.hpp"
#include <utility>

class Simulation {
    public:
        Simulation(int width, int height, int cellSize) : grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false) {};
        void Draw() {
            grid.Draw();
        };
        void setCellValue(int row, int column, int value) {
            grid.setValue(row, column, value);
        };
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
                // method of finding row and column positions on toroidal grid
                int neighbourRow = (row + offset.first +grid.getRows()) % grid.getRows() ;
                int neigbourColumn = (column + offset.second + grid.getColumns()) % grid.getColumns();
                liveNeigbours += grid.getValue(neighbourRow, neigbourColumn);
            }
            return liveNeigbours;
        }

        void updateState() {
            if (isRunning()) {
                for (int row = 0; row < grid.getRows(); row++) {
                    for (int column = 0; column < grid.getColumns(); column++) {
                        int liveNeighbours = countLiveNeighbours(row, column);
                        int cellValue = grid.getValue(row, column);

                        if (cellValue == 1) {
                            if (liveNeighbours > 3 || liveNeighbours < 2) {
                                tempGrid.setValue(row, column, 0);
                            } else {
                                tempGrid.setValue(row, column, 1);
                            }
                        }
                        else {
                            if (liveNeighbours == 3) {
                                tempGrid.setValue(row, column, 1);
                            } else {
                                tempGrid.setValue(row, column, 0);
                            }
                        }
                    }
                }
                grid = tempGrid;
            }
        };

        void startSimulation() {
            run = true;
        }

        void stopSimulation() {
            run = false;
        }

        bool isRunning() {
            return run;
        }

        void clearGrid() {
            if (!isRunning()) {
                grid.clearGrid();
            }
        }

        void createRandomState() {
            if (!isRunning()) {
                grid.fillRandom();
            }
        }

        void toggleCell(int row, int column) {
            if (!isRunning()) {
                grid.toggleCell(row, column);
            }
        }

    private:
        Grid grid;
        Grid tempGrid;
        bool run;
};
