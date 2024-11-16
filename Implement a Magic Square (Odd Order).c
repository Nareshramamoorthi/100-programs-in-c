#include <stdio.h>

// Function to generate a magic square
void generateMagicSquare(int n) {
    int magicSquare[n][n];

    // Initialize all slots to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    // Start position for 1
    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num;  // Place the current number

        // Calculate the next position
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (magicSquare[newi][newj] != 0) {  // If the cell is already filled
            i = (i + 1) % n;  // Move down
        } else {
            i = newi;
            j = newj;
        }
    }

    // Print the magic square
    printf("Magic Square of order %d:\n", n);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf("%3d ", magicSquare[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter an odd order for the magic square: ");
    scanf("%d", &n);

    if (n % 2 == 0 || n < 1) {
        printf("Order must be a positive odd number.\n");
    } else {
        generateMagicSquare(n);
    }

    return 0;
}
