=#include <stdio.h>

#define MAX 10

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int row, int col);
void printMatrix(int matrix[MAX][MAX], int row, int col);
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int row, int col);

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int row, col;

    // Input the dimensions of the matrices
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);

    // Ensure dimensions do not exceed MAX
    if (row > MAX || col > MAX) {
        printf("Rows and columns should not exceed %d.\n", MAX);
        return 1;
    }

    // Input matrices
    printf("Enter elements of the first matrix:\n");
    inputMatrix(mat1, row, col);

    printf("Enter elements of the second matrix:\n");
    inputMatrix(mat2, row, col);

    // Add matrices
    addMatrices(mat1, mat2, result, row, col);

    // Print result
    printf("Resultant matrix after addition:\n");
    printMatrix(result, row, col);

    return 0;
}

void inputMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
