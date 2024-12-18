#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to calculate the sum of primary and secondary diagonals
void calculateDiagonalSums(int matrix[ROWS][COLS]) {
    int primaryDiagonalSum = 0, secondaryDiagonalSum = 0;

    for (int i = 0; i < ROWS; i++) {
        primaryDiagonalSum += matrix[i][i]; // Primary diagonal
        secondaryDiagonalSum += matrix[i][COLS - i - 1]; // Secondary diagonal
    }

    printf("Primary Diagonal Sum: %d\n", primaryDiagonalSum);
    printf("Secondary Diagonal Sum: %d\n", secondaryDiagonalSum);
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    calculateDiagonalSums(matrix);

    return 0;
}
