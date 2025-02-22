#include <stdio.h>

void sortOddEvenPositions(int arr[], int n) {
    // Sort odd-positioned elements in descending order
    for (int i = 0; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Sort even-positioned elements in ascending order
    for (int i = 1; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {13, 2, 4, 15, 12, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortOddEvenPositions(arr, n);

    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
