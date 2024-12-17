#include <stdio.h>
#define ROWS 4
#define COLS 4

// Function to print a 2D array in a zigzag pattern
void printZigzag(int matrix[ROWS][COLS]) {
    printf("Zigzag Pattern Traversal:\n");

    for (int i = 0; i < ROWS; i++) {
        if (i % 2 == 0) {
            // Left to right for even rows
            for (int j = 0; j < COLS; j++) {
                printf("%d ", matrix[i][j]);
            }
        } else {
            // Right to left for odd rows
            for (int j = COLS - 1; j >= 0; j--) {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printZigzag(matrix);

    return 0;
}
