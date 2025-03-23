#include <stdio.h>

void fillSpiral(int n) {
    int matrix[n][n], value = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (value <= n * n) {
        for (int i = left; i <= right; i++)  // Left to Right
            matrix[top][i] = value++;
        top++;

        for (int i = top; i <= bottom; i++)  // Top to Bottom
            matrix[i][right] = value++;
        right--;

        for (int i = right; i >= left; i--)  // Right to Left
            matrix[bottom][i] = value++;
        bottom--;

        for (int i = bottom; i >= top; i--)  // Bottom to Top
            matrix[i][left] = value++;
        left++;
    }

    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter matrix size: ");
    scanf("%d", &size);
    fillSpiral(size);
    return 0;
}
