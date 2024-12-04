#include <stdio.h>
#include <stdlib.h>

// Function to generate prime numbers up to a given limit
void generatePrimes(int limit) {
    if (limit < 2) {
        printf("No primes available below 2.\n");
        return;
    }

    int *isPrime = (int *)malloc((limit + 1) * sizeof(int));

    for (int i = 0; i <= limit; i++) {
        isPrime[i] = 1; // Mark all numbers as prime initially
    }

    isPrime[0] = isPrime[1] = 0; // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = 0; // Mark multiples of i as non-prime
            }
        }
    }

    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(isPrime);
}

int main() {
    int limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    generatePrimes(limit);

    return 0;
}
