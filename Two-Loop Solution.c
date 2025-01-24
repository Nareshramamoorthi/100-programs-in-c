#include <stdio.h>

void generatePattern(int n) {
    int num = 1; // Start with 1
    for (int i = 1; i <= n; i++) {
        int start = num + i - 1; // Calculate the end of the row
        for (int j = 1; j <= i; j++) {
            // Odd row: Print increasing order
            // Even row: Print decreasing order
            if (i % 2 == 1) {
                printf("%d ", num++);
            } else {
                printf("%d ", start--);
                num++;
            }
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
