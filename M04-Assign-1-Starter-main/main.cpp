/* Program name: Main.cpp
* Author: Danielle Lloyd    
* Date last updated: 4/06/2025
* Purpose: Sudoku Solver
* Description: This program solves a Sudoku puzzle using backtracking.
*/

#include "sudoku.h"


int main() {
    // Creates a Sudoku object
    Sudoku sudoku;

    // Loads the initial grid from the file
    sudoku.loadGrid("sudoku.txt");

    // Prints the initial state of the grid
    std::cout << "Initial Sudoku Grid:\n";
    std::cout << sudoku << "\n";

    // Solves the Sudoku puzzle
    sudoku.solveGrid();

    // Prints the solved grid
    std::cout << "Solved Sudoku Grid:\n";
    std::cout << sudoku << "\n";

    return 0;
}

