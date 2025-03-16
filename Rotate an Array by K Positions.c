#include <stdio.h>

void rotateArray(int arr[], int n, int k) {
    k = k % n;  // Handle cases where k > n
    int temp[k];

    // Store last k elements
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift the rest of the elements
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Copy the elements back
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Original array: ");
    printArray(arr, n);

    rotateArray(arr, n, k);

    printf("Rotated array: ");
    printArray(arr, n);

    return 0;
}