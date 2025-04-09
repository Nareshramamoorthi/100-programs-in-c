#include <stdio.h>
void waveSort(int rows, int cols, int mat[rows][cols]) {
    int temp[rows * cols], k = 0;

    // Flatten the matrix
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp[k++] = mat[i][j];

    // Sort the array
    for (int i = 0; i < k - 1; i++)
        for (int j = 0; j < k - i - 1; j++)
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }

    // Fill back in wave pattern
    k = 0;
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++)
                mat[i][j] = temp[k++];
        } else {
            for (int j = cols - 1; j >= 0; j--)
                mat[i][j] = temp[k++];
        }
    }
}

int main() {
    int mat[3][3] = {{9, 2, 7}, {4, 6, 3}, {8, 1, 5}};
    waveSort(3, 3, mat);

    printf("Wave Sorted Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%3d", mat[i][j]);
        printf("\n");
    }
    return 0;
}