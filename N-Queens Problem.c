#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8 // Change this for different board sizes

// Function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen
bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) // Check left
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // Check upper diagonal
        if (board[i][j]) return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--) // Check lower diagonal
        if (board[i][j]) return false;

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueensUtil(int board[N][N], int col) {
    if (col >= N) { // All queens are placed
        printBoard(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen

            // Recursively place the rest
            res = solveNQueensUtil(board, col + 1) || res;

            board[i][col] = 0; // Backtrack
        }
    }
    return res;
}

// Driver function
void solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0)) {
        printf("Solution does not exist.\n");
    }
}

int main() {
    solveNQueens();
    return 0;
}
