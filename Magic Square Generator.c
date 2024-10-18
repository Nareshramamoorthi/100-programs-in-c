#include <stdio.h>

void generateMagicSquare(int n) {
    int magicSquare[15][15];

    // Initialize the magic square with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // Set initial position
    int num = 1;
    int row = 0;
    int col = n / 2;
    int current_row, current_col;

    while (num <= n * n) {
        magicSquare[row][col] = num;
        num++;
        current_row = row;
        current_col = col;

        // Move up and right
        row -= 1;
        col += 1;

        // Wrap around if out of bounds
        if (row < 0) row = n - 1;
        if (col == n) col = 0;

        // If the cell is already filled, move down instead
        if (magicSquare[row][col] != 0) {
            row = current_row + 1;
            col = current_col;
        }
    }

    // Display the magic square
    printf("Magic Square of size %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", magicSquare[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the magic square (odd number): ");
    scanf("%d", &n);

    // Ensure the input is an odd number
    if (n % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;
    }

    generateMagicSquare(n);

    return 0;
}
