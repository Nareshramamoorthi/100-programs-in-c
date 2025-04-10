#include <stdio.h>

#define SIZE 4

void reverseZigzagDiagonal(int mat[SIZE][SIZE]) {
    for (int d = 0; d < 2 * SIZE - 1; d++) {
        int temp[SIZE], k = 0;
        for (int i = 0; i < SIZE; i++) {
            int j = d - i;
            if (j >= 0 && j < SIZE)
                temp[k++] = mat[i][j];
        }
        // Reverse and put back
        for (int i = 0; i < k; i++) {
            int j = d - i;
            if (j >= 0 && j < SIZE)
                mat[i][j] = temp[k - 1 - i];
        }
    }
}

int main() {
    int mat[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };

    reverseZigzagDiagonal(mat);

    printf("Reversed Zigzag Diagonals:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%3d", mat[i][j]);
        printf("\n");
    }
    return 0;
}
