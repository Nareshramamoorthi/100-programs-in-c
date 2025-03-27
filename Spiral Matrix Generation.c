#include <stdio.h>

void generateSpiralMatrix(int n) {
    int matrix[n][n], value = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (value <= n * n) {
        for (int i = left; i <= right; i++)
            matrix[top][i] = value++;
        top++;

        for (int i = top; i <= bottom; i++)
            matrix[i][right] = value++;
        right--;

        for (int i = right; i >= left; i--)
            matrix[bottom][i] = value++;
        bottom--;

        for (int i = bottom; i >= top; i--)
            matrix[i][left] = value++;
        left++;
    }

    printf("Spiral Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int n = 5; // Change size here
    generateSpiralMatrix(n);
    return 0;
}