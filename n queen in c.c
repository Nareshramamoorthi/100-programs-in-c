#include <stdio.h>
#include <stdbool.h>

#define N 8  // Define N for an 8x8 chessboard, can be modified for other sizes

// Function to print the solution (the board configuration)
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed on the board at position board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check the row on the left
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check the upper diagonal on the left
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the lower diagonal on the left
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive utility function to solve the N-Queens problem
bool solveNQUtil(int board[N][N], int col) {
    // Base case: If all queens are placed, return true
    if (col >= N)
        return true;

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place the queen on board[i][col]
            board[i][col] = 1;

            // Recur to place queens in the remaining columns
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing the queen leads to a solution, remove the queen (backtrack)
            board[i][col] = 0;
        }
    }

    // If no solution found, return false
    return false;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQ() {
    int board[N][N] = {0};

    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQ();
    return 0;
}
