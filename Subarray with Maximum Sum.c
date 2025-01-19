/*
Title: Subarray with Maximum Sum
Description: Finds the subarray with the largest sum using Kadane's Algorithm.
*/

#include <stdio.h>

void findMaxSubarray(int arr[], int size) {
    int maxSum = arr[0], currentSum = arr[0];
    int start = 0, end = 0, tempStart = 0;

    for (int i = 1; i < size; i++) {
        if (currentSum + arr[i] < arr[i]) {
            currentSum = arr[i];
            tempStart = i;
        } else {
            currentSum += arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    printf("Maximum Sum: %d\n", maxSum);
    printf("Subarray: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]);

    findMaxSubarray(arr, size);

    return 0;
}
