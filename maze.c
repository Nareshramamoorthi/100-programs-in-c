#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10  // Size of the maze

// Maze representation
int maze[N][N];

// Function to initialize the maze with walls (1) and open paths (0)
void initializeMaze() {
    srand(time(0));  // Seed for randomness
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N-1 || j == 0 || j == N-1) {
                maze[i][j] = 1;  // Create boundary walls
            } else {
                maze[i][j] = rand() % 2;  // Randomly place walls (1) and open paths (0)
            }
        }
    }
    maze[1][1] = 0;  // Start position
    maze[N-2][N-2] = 0;  // End position
}

// Function to print the maze
void printMaze() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maze[i][j] == 1)
                printf("# ");  // Wall
            else
                printf(". ");  // Path
        }
        printf("\n");
    }
}

// Function to check if the move is valid
int isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

// Recursive function to solve the maze using backtracking
int solveMaze(int x, int y) {
    // If we have reached the bottom-right corner, maze is solved
    if (x == N-2 && y == N-2) {
        maze[x][y] = 2;  // Mark the path
        return 1;
    }

    if (isValid(x, y)) {
        maze[x][y] = 2;  // Mark the current cell as part of the solution path

        // Move right
        if (solveMaze(x, y + 1))
            return 1;

        // Move down
        if (solveMaze(x + 1, y))
            return 1;

        // Move left
        if (solveMaze(x, y - 1))
            return 1;

        // Move up
        if (solveMaze(x - 1, y))
            return 1;

        maze[x][y] = 0;  // Backtrack, unmark the cell
    }
    return 0;
}

int main() {
    // Generate and print the maze
    initializeMaze();
    printf("Generated Maze:\n");
    printMaze();

    // Solve the maze
    if (solveMaze(1, 1)) {
        printf("\nSolution Found:\n");
        printMaze();  // Print the maze with the solution path
    } else {
        printf("\nNo solution exists.\n");
    }

    return 0;
}
