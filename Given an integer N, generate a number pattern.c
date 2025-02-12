#include <stdio.h>

void printPattern(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }
}

int main() {
    int n = 5; // Change value for different patterns
    printPattern(n);
    return 0;
}
