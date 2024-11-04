#include <stdio.h>

#define MAX 10

// Function to perform Gaussian elimination
void gaussianElimination(float matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        // Make the diagonal element 1
        float pivot = matrix[i][i];
        for (int j = 0; j <= n; j++) {
            matrix[i][j] /= pivot;
        }

        // Make all elements below the pivot in the current column 0
        for (int k = i + 1; k < n; k++) {
            float factor = matrix[k][i];
            for (int j = 0; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Back substitution to find the solution
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            matrix[i][n] -= matrix[i][j] * matrix[j][n];
        }
    }
}

// Function to display the matrix
void displayMatrix(float matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    float matrix[MAX][MAX];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("\nAugmented Matrix:\n");
    displayMatrix(matrix, n);

    gaussianElimination(matrix, n);

    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %0.2f\n", i + 1, matrix[i][n]);
    }

    return 0;
}
