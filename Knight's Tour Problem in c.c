#include <stdio.h>

#define N 8  // Size of the chessboard

// Utility function to print the solution matrix
void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

// Check if the move is valid for a knight
int isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

// Utility function to solve the Knight's Tour problem using backtracking
int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]) {
    int k, next_x, next_y;

    // If all squares have been visited, the knight's tour is complete
    if (movei == N * N)
        return 1;

    // Try all possible moves from the current position
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];

        // Check if the next move is valid
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;

            // Recur to make the next move
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove))
                return 1;
            else
                // Backtrack if the move doesn't lead to a solution
                sol[next_x][next_y] = -1;
        }
    }

    return 0;
}

// Function to solve the Knight's Tour problem
int solveKT() {
    int sol[N][N];

    // Initialize the solution matrix with -1 (indicating unvisited squares)
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    // Possible moves for a knight in chess (8 possible movements)
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Starting position of the knight (top-left corner of the board)
    sol[0][0] = 0;

    // Solve the problem using utility function
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        printf("Solution does not exist\n");
        return 0;
    } else
        printSolution(sol);

    return 1;
}

int main() {
    solveKT();
    return 0;
}
