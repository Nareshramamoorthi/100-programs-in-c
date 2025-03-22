#include <stdio.h>

void generatePascal(int n) {
    int triangle[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                triangle[i][j] = 1;
            else
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];

            printf("%4d", triangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    generatePascal(rows);
    return 0;
}
