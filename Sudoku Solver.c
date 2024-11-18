#include <stdio.h>
#include <stdbool.h>

#define N 9  // Size of the Sudoku grid

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if placing a number is valid
bool isValid(int grid[N][N], int row, int col, int num) {
    // Check row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool emptySpot = false;

    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                emptySpot = true;
                break;
            }
        }
        if (emptySpot) {
            break;
        }
    }

    // If no empty cell is left, the puzzle is solved
    if (!emptySpot) {
        return true;
    }

    // Try numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            // Backtrack
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        printf("Sudoku puzzle solved:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}
