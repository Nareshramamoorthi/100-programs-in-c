/*
Title: Incremental Number Pattern
Description: Prints a pattern where each row alternates between odd and even numbers.
*/

#include <stdio.h>

void generatePattern(int n) {
    int even = 2, odd = 1; // Initialize even and odd numbers

    for (int i = 1; i <= n; i++) {
        // For odd rows, print odd numbers
        if (i % 2 != 0) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", odd);
                odd += 2;
            }
        } else {
            // For even rows, print even numbers
            for (int j = 1; j <= i; j++) {
                printf("%d ", even);
                even += 2;
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);

    generatePattern(n);

    return 0;
}
