#include <stdio.h>

void rearrangeArray(int arr[], int n) {
    int evenIndex = 0;
    int temp[n];

    // Store even numbers first
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            temp[evenIndex++] = arr[i];
        }
    }

    // Store odd numbers next
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            temp[evenIndex++] = arr[i];
        }
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {3, 1, 2, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrangeArray(arr, n);

    printf("Rearranged array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}