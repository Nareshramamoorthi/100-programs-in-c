#include <stdio.h>

#define SIZE 3 

void generateMagicSquare(int n) {
    int magicSquare[SIZE][SIZE] = {0};

    int i = 0, j = n / 2;
    for (int num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num;
        int newI = (i - 1 + n) % n;
        int newJ = (j + 1) % n;
        if (magicSquare[newI][newJ] != 0) {
            i = (i + 1) % n;
        } else {
            i = newI;
            j = newJ;
        }
    }

    printf("Magic Square of size %d:\n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", magicSquare[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generateMagicSquare(SIZE);
    return 0;
}