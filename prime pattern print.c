int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int count = 1, primesNeeded = 1, num = 2;

    while (count <= 5) {
        int printedPrimes = 0;

        while (printedPrimes < primesNeeded) {
            if (isPrime(num)) {
                printf("%d ", num);
                printedPrimes++;
            }
            num++;
        }

        printf("\n");
        primesNeeded++; // Increase the number of primes to print in the next row
        count++; // Move to the next row
    }

    return 0;
}
