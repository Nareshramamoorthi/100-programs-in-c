#include <stdio.h>

#define N 3  

int isMagicSquare(int matrix[N][N]) {
    int sum = 0, diag1 = 0, diag2 = 0;

    for (int i = 0; i < N; i++)  
        sum += matrix[0][i];

    for (int i = 0; i < N; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != sum || colSum != sum)
            return 0;

        diag1 += matrix[i][i];
        diag2 += matrix[i][N - i - 1];
    }

    return (diag1 == sum && diag2 == sum);
}

void printMatrix(int matrix[N][N]) {
    printf("Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)  
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int matrix[N][N] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    };

    printMatrix(matrix);

    if (isMagicSquare(matrix))  
        printf("The given matrix is a Magic Square!\n");
    else  
        printf("Not a Magic Square.\n");

    return 0;
}
