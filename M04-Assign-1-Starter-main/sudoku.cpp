#include "sudoku.h"
#include <fstream>

// Constructor to initialize the grid with zeros
Sudoku::Sudoku() {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            grid[i][j] = 0;
}
// Function to load the grid from a file
void Sudoku::loadGrid(const std::string& filename) {
    // Open the file and read the grid values
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file\n";
        return;
    }
    // Popoulates the grid, replacing unknown values with 0
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            file >> grid[i][j];
}

bool Sudoku::isValid(int row, int col, int num) {
    // Check if the number is already in the row, column, or 3x3 subgrid
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    }
    // determine the starting row and column of the 3x3 subgrid
    int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
    // Check the 3x3 subgrid
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool Sudoku::solve() {
    // Traverse the grid to find an empty cell (0)
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) { //if the cell is empty
            // Tries all possible numbers (1-9) in the empty cell
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isValid(row, col, num)) { // Check if the number is valid
                        grid[row][col] = num;
                        // Recursively try to solve the rest of the grid
                        if (solve())
                            return true;
                        //backtrack if the number doesn't lead to a solution
                        grid[row][col] = 0;
                    }
                }
                return false; 
            }
        }
    }
    return true;
}
// Calls the recursive solve function to solve the Sudoku puzzle
void Sudoku::solveGrid() {
    if (!solve()) { // If `solve()` returns false, it means no solution exists. // added the following to match expected output 
        std::cout << "No solution exists for the given Sudoku.\n";
    }
}

// Change in functions formatting to match expected regex. // Had copilot help me with this //
std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku) {
    for (int i = 0; i < 9; ++i) {
        // Print horizontal separator before each row group
        if (i % 3 == 0) {
            os << "+-----------+-----------+-----------+\n";
        }

        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0) os << "| "; // Start of a 3x3 block
            os << sudoku.grid[i][j] << "   "; // Ensure consistent spacing

            if (j == 8) os << "|"; // End of row
        }
        os << "\n";
    }
    // Final separator
    os << "+-----------+-----------+-----------+\n";
    return os;
}