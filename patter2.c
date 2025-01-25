#include <stdio.h>

void generatePattern(int n) {
    int num = 1; // Start number
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Print the number only if the sum of row and column index is odd
            if ((i + j) % 2 == 1) {
                printf("%d ", num++);
            } else {
                printf("  "); // Space for even positions
            }
        }
        printf("\n");
    }
}

int main() {
    int n = 3; // Number of rows (can be adjusted)
    generatePattern(n);

    return 0;
}
