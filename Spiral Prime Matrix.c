#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int nextPrime(int start) {
    while (!isPrime(start)) start++;
    return start;
}

int main() {
    int n;
    printf("Enter matrix size (n x n): ");
    scanf("%d", &n);

    int mat[n][n], top = 0, bottom = n - 1, left = 0, right = n - 1;
    int prime = 2;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            mat[top][i] = prime = nextPrime(prime);
            prime++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            mat[i][right] = prime = nextPrime(prime);
            prime++;
        }
        right--;
        for (int i = right; i >= left; i--) {
            mat[bottom][i] = prime = nextPrime(prime);
            prime++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--) {
            mat[i][left] = prime = nextPrime(prime);
            prime++;
        }
        left++;
    }

    printf("Spiral Prime Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5d", mat[i][j]);
        printf("\n");
    }
    return 0;
}
