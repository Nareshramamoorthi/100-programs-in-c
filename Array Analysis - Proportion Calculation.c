/*
Title: Array Analysis - Proportion Calculation
Description: Calculates the proportion of positive, neutral, and negative numbers in an array.
*/

#include <stdio.h>

int main() {
    int arr[] = {2, 1, 0, -8, -9}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int positive = 0, neutral = 0, negative = 0;
    int i;

    // Count positive, neutral, and negative numbers
    for (i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive++;
        } else if (arr[i] == 0) {
            neutral++;
        } else {
            negative++;
        }
    }

    // Calculate proportions
    float positiveProportion = (float)positive / size;
    float neutralProportion = (float)neutral / size;
    float negativeProportion = (float)negative / size;

    // Print the results
    printf("Proportions: [%.1f, %.1f, %.1f]\n", positiveProportion, neutralProportion, negativeProportion);

    return 0;
}
