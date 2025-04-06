#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>

class Sudoku {
private:
    int grid[9][9]; // 2D array to hold the Sudoku grid
    // Function to check if a number can be placed in a given cell
    bool isValid(int row, int col, int num);
    // Recursive function to solve the Sudoku puzzle
    bool solve();

public:
    Sudoku(); // Constructor to initialize the grid with zeros
    void loadGrid(const std::string& filename); // Function to load the grid from a file
    void solveGrid(); // Function to solve the Sudoku puzzle
    friend std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku); // Overloaded operator to print the grid
};

#endif // SUDOKU_H