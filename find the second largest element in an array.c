#include <stdio.h>

int findSecondLargest(int arr[], int n) {
    int largest = arr[0];
    int secondLargest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = findSecondLargest(arr, n);
    
    if (result != -1) {
        printf("Second Largest Element: %d\n", result);
    } else {
        printf("No second largest element\n");
    }
    
    return 0;
}
