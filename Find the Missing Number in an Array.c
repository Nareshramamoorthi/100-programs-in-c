#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    int total = (n * (n + 1)) / 2; // Sum of first N natural numbers
    int sum = 0;

    for (int i = 0; i < n - 1; i++)
        sum += arr[i];

    return total - sum;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6}; // Missing number is 3
    int n = 6; // Array should have numbers from 1 to 6

    printf("Missing Number: %d\n", findMissingNumber(arr, n));
    return 0;
}
