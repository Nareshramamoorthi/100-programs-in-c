#include <stdio.h>
#define SIZE 4

void rotateBorder(int mat[SIZE][SIZE]) {
    int top = 0, bottom = SIZE - 1, left = 0, right = SIZE - 1;
    int prev = mat[top + 1][left];

    for (int i = left; i <= right; i++) {
        int temp = mat[top][i];
        mat[top][i] = prev;
        prev = temp;
    }
    top++;

    for (int i = top; i <= bottom; i++) {
        int temp = mat[i][right];
        mat[i][right] = prev;
        prev = temp;
    }
    right--;

    for (int i = right; i >= left; i--) {
        int temp = mat[bottom][i];
        mat[bottom][i] = prev;
        prev = temp;
    }
    bottom--;

    for (int i = bottom; i >= top; i--) {
        int temp = mat[i][left];
        mat[i][left] = prev;
        prev = temp;
    }
}

int main() {
    int mat[SIZE][SIZE] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15,16}
    };

    rotateBorder(mat);

    printf("Rotated Matrix Border:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%3d", mat[i][j]);
        printf("\n");
    }

    return 0;
}
