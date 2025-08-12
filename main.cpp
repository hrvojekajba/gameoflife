#include <raylib.h>
#include <vector>

class Grid {
public:
  // define class constructor -- we use an initializer list to intialize the
  // private variables
  Grid(int width, int height, int cell_size)
      : rows(height / cell_size), columns(width / cell_size),
        cell_size(cell_size), cells(rows, std::vector<int>(columns, 0)) {};
  // initialize cells -- which is a vector of vectors of integers,
  // number of vectors is rows, and each row is a vector that contains
  // a columns number of elements

  void Draw() {
    for (int row = 0; row < rows; row++) {
      for (int column = 0; column < columns; column++) {
        // assigns green to cell that holds a non zero value
        Color color =
            cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
        // draw rectangle for each cell
        DrawRectangle(column * cell_size, row * cell_size, cell_size - 1,
                      cell_size - 1, color);
      }
    }
  }

  void SetValue(int row, int column, int value) {
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

int main() {
  Color color_grey = {29, 29, 29, 255};
  const int window_height = 750;
  const int window_width = 750;
  const int cell_size = 25;
  const int target_fps = 15;

  InitWindow(window_width, window_height, "Game of Life"); // initialize window
  SetTargetFPS(target_fps); // set target fps for window
  Grid grid{window_width, window_height, cell_size}; // initialize Grid object

  while (WindowShouldClose() == false) {
    BeginDrawing();
    ClearBackground(color_grey);
    grid.Draw();
    EndDrawing();
  }

  return 0;
}
