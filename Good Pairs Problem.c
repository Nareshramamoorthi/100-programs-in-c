/*
Title: Good Pairs Problem
Description: Identifies all pairs in an array where the sum equals a target value.
*/

#include <stdio.h>

// Function to find and print good pairs
void findGoodPairs(int arr[], int size, int target) {
    int count = 0;

    printf("Good pairs (i, j) where arr[i] + arr[j] == %d:\n", target);
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d) => (%d + %d)\n", i, j, arr[i], arr[j]);
                count++;
            }
        }
    }

    if (count == 0) {
        printf("No good pairs found.\n");
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5; // Target sum

    // Find and print good pairs
    findGoodPairs(arr, size, target);

    return 0;
}
