#include <stdio.h>

void findSecondLargest(int arr[], int n) {
    if (n < 2) {
        printf("No second largest element\n");
        return;
    }

    int first = arr[0], second = -1;  

    for (int i = 1; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == -1)
        printf("No second largest element\n");
    else
        printf("Second Largest: %d\n", second);
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSecondLargest(arr, n);
    return 0;
}