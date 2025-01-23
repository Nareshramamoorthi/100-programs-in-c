#include <stdio.h>

void generatePattern(int n) {
    // Upper triangle (1 to n)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d  ", j);
        }
        printf("\n");
    }

    // Lower inverted triangle
    for (int i = 2; i <= n; i++) {
        // Print spaces
        for (int j = 1; j < i; j++) {
            printf("   "); // Each space block aligns numbers
        }
        // Print numbers
        for (int j = i; j <= n; j++) {
            printf("%d  ", j);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    generatePattern(n);

    return 0;
}
