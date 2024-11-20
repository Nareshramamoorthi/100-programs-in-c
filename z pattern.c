#include <stdio.h>

void printZPattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Print 'Z' on the first row, last row, or diagonal
            if (i == 0 || i == n - 1 || j == (n - 1 - i)) {
                printf("Z");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of the Z pattern: ");
    scanf("%d", &size);

    if (size < 3) {
        printf("Size must be 3 or larger.\n");
    } else {
        printZPattern(size);
    }

    return 0;
}
