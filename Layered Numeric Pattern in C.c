#include <stdio.h>

int main() {
    int n = 10; // Number of layers
    int size = 2 * n - 1; // Size of the matrix
    int matrix[size][size];

    // Fill the matrix layer by layer
    for (int layer = 0; layer < n; layer++) {
        for (int i = layer; i < size - layer; i++) {
            for (int j = layer; j < size - layer; j++) {
                matrix[i][j] = layer;
            }
        }
    }

    // Print the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
