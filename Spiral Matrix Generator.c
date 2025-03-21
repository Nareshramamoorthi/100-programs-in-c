#include <stdio.h>

void generateSpiral(int n) {
    int matrix[n][n];
    int num = 1, left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (num <= n * n) {
        for (int i = left; i <= right; i++) matrix[top][i] = num++;
        top++;
        for (int i = top; i <= bottom; i++) matrix[i][right] = num++;
        right--;
        for (int i = right; i >= left; i--) matrix[bottom][i] = num++;
        bottom--;
        for (int i = bottom; i >= top; i--) matrix[i][left] = num++;
        left++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter matrix size: ");
    scanf("%d", &size);
    generateSpiral(size);
    return 0;
}
