/*
Title: Pyramid Pattern
Description: Generates a number pyramid pattern for a given input.
*/

#include <stdio.h>

void printPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print increasing numbers
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Print decreasing numbers
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // Move to the next line
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printPyramid(n);

    return 0;
}