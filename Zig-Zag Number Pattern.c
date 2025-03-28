#include <stdio.h>

void printZigZagPattern(int n) {
    int num = 1, direction = 1;

    for (int i = 0; i < n; i++) {
        if (direction) {
            for (int j = 0; j <= i; j++)
                printf("%d ", num++);
        } else {
            int temp = num + i;
            for (int j = 0; j <= i; j++)
                printf("%d ", --temp);
            num += i + 1;
        }
        direction = !direction;
        printf("\n");
    }
}

int main() {
    int n = 5; // Change for different sizes
    printZigZagPattern(n);
    return 0;
}