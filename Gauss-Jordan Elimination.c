#include <stdio.h>

#define SIZE 10

void gaussJordan(float matrix[SIZE][SIZE], int n) {
    int i, j, k;
    float ratio;

    // Performing Gauss-Jordan elimination
    for (i = 0; i < n; i++) {
        // Making the diagonal element 1
        if (matrix[i][i] != 0) {
            float pivot = matrix[i][i];
            for (j = 0; j < n + 1; j++) {
                matrix[i][j] = matrix[i][j] / pivot;
            }
        }

        // Making the other elements in the column 0
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = matrix[j][i];
                for (k = 0; k < n + 1; k++) {
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
                }
            }
        }
    }

    // Printing the solution
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }
}

int main() {
    int n, i, j;
    float matrix[SIZE][SIZE];

    // Input: number of variables
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    // Input: augmented matrix
    printf("Enter the coefficients of the augmented matrix (including the constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Applying Gauss-Jordan elimination
    gaussJordan(matrix, n);

    return 0;
}
