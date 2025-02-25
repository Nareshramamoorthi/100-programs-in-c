#include <stdio.h>

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int findUglyNumber(int n) {
    int ugly[n];
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int next2 = 2, next3 = 3, next5 = 5;
    int nextUgly;

    for (int i = 1; i < n; i++) {
        nextUgly = min(next2, next3, next5);
        ugly[i] = nextUgly;

        if (nextUgly == next2) {
            i2++;
            next2 = ugly[i2] * 2;
        }
        if (nextUgly == next3) {
            i3++;
            next3 = ugly[i3] * 3;
        }
        if (nextUgly == next5) {
            i5++;
            next5 = ugly[i5] * 5;
        }
    }
    return ugly[n - 1];
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input!\n");
    } else {
        printf("The %dth Ugly Number is: %d\n", n, findUglyNumber(n));
    }
    return 0;
}
