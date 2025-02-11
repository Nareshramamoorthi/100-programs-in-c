#include <stdio.h>

void printPattern(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++) {
        int val = num;
        for (int j = 1; j <= i; j++) {
            printf("%d ", val);
            val += 2; 
        }
        num += i; 
        printf("\n");
    }
}

int main() {
    int n = 4; // Change this for different values
    printPattern(n);
    return 0;
}