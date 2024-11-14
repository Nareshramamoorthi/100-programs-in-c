#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Target found
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search the right half
        } else {
            right = mid - 1;  // Search the left half
        }
    }
    return -1;  // Target not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found.\n", target);
    }

    return 0;
}
