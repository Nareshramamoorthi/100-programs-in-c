/*
Title: Find the Middle Number of a Sorted Array
Description: This program sorts a given array and identifies its middle number.
*/

#include <stdio.h>

// Function to sort the array using Bubble Sort
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the middle element
int findMiddle(int arr[], int size) {
    return arr[size / 2];
}

int main() {
    int n;

    // Input the array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    sortArray(arr, n);

    // Display the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Find and display the middle element
    if (n % 2 == 0) {
        printf("Middle elements are: %d and %d\n", arr[(n / 2) - 1], arr[n / 2]);
    } else {
        printf("Middle element is: %d\n", findMiddle(arr, n));
    }

    return 0;
}
