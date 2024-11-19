#include <stdio.h>
#define N 5

// Function to print the solution path
void printSolution(int solution[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d", solution[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is safe to move to
int isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the maze
int solveMazeUtil(int maze[N][N], int x, int y, int solution[N][N]) {
    // If (x, y) is the goal, return success
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        solution[x][y] = 1;
        return 1;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y)) {
        // Mark the current cell as part of the solution path
        solution[x][y] = 1;

        // Move forward in the x direction
        if (solveMazeUtil(maze, x + 1, y, solution)) {
            return 1;
        }

        // Move down in the y direction
        if (solveMazeUtil(maze, x, y + 1, solution)) {
            return 1;
        }

        // If none of the above moves work, backtrack
        solution[x][y] = 0;
        return 0;
    }
    return 0;
}

// Function to solve the maze
void solveMaze(int maze[N][N]) {
    int solution[N][N] = {0};

    if (solveMazeUtil(maze, 0, 0, solution) == 0) {
        printf("No solution exists for the given maze.\n");
    } else {
        printf("Solution to the maze:\n");
        printSolution(solution);
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
