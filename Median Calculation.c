/*
Title: Median Calculation
Description: Calculates the median of a given array after sorting it.
*/

#include <stdio.h>

// Function to sort the array (Bubble Sort)
void sortArray(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the median
float calculateMedian(int arr[], int size) {
    if (size % 2 == 0) {
        // For even-sized arrays
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        // For odd-sized arrays
        return arr[size / 2];
    }
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 1}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array
    sortArray(arr, size);

    // Calculate the median
    float median = calculateMedian(arr, size);

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Print the median
    printf("\nMedian: %.2f\n", median);

    return 0;
}
