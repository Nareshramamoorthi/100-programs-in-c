#include <stdio.h>

#define N 5

// Function to print the maze solution
void printSolution(int solution[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is safe to move to
int isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Function to solve the maze using recursion
int solveMazeUtil(int maze[N][N], int x, int y, int solution[N][N]) {
    // If x, y is the goal, return true
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return 1;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y)) {
        solution[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x + 1, y, solution))
            return 1;

        // Move down
        if (solveMazeUtil(maze, x, y + 1, solution))
            return 1;

        // Backtrack
        solution[x][y] = 0;
    }
    return 0;
}

// Function to solve the maze problem
void solveMaze(int maze[N][N]) {
    int solution[N][N] = {0};

    if (solveMazeUtil(maze, 0, 0, solution)) {
        printf("Maze Solution:\n");
        printSolution(solution);
    } else {
        printf("No solution exists!\n");
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1}};

    printf("Original Maze:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    solveMaze(maze);
    return 0;
}
