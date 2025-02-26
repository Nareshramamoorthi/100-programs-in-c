#include <stdio.h>

void multiplyMatrix(long long F[2][2], long long M[2][2]) {
    long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void powerMatrix(long long F[2][2], int n) {
    if (n == 0 || n == 1) return;
    
    long long M[2][2] = {{1, 1}, {1, 0}};
    
    powerMatrix(F, n / 2);
    multiplyMatrix(F, F);

    if (n % 2 != 0) multiplyMatrix(F, M);
}

long long fibonacci(int n) {
    if (n == 0) return 0;
    
    long long F[2][2] = {{1, 1}, {1, 0}};
    powerMatrix(F, n - 1);
    
    return F[0][0];
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("The %dth Fibonacci number is: %lld\n", n, fibonacci(n));
    return 0;
}
