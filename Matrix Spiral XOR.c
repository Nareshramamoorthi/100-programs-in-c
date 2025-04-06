#include <stdio.h>

#define MAX 100

void spiralFill(int n, int mat[MAX][MAX]) {
    int val = 1, top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            mat[top][i] = val++;
        top++;
        for (int i = top; i <= bottom; i++)
            mat[i][right] = val++;
        right--;
        for (int i = right; i >= left; i--)
            mat[bottom][i] = val++;
        bottom--;
        for (int i = bottom; i >= top; i--)
            mat[i][left] = val++;
        left++;
    }
}

int diagonalXOR(int n, int mat[MAX][MAX]) {
    int xorVal = 0;
    for (int i = 0; i < n; i++) {
        xorVal ^= mat[i][i];
        if (i != n - i - 1)
            xorVal ^= mat[i][n - i - 1];
    }
    return xorVal;
}

int main() {
    int n;
    printf("Enter matrix size: ");
    scanf("%d", &n);
    int mat[MAX][MAX];
    spiralFill(n, mat);

    printf("Spiral Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", mat[i][j]);
        printf("\n");
    }

    int result = diagonalXOR(n, mat);
    printf("Diagonal XOR: %d\n", result);
    return 0;
}
