#include <stdio.h>

void rearrange(int arr[], int n) {
    int temp[n];
    int left = 0, right = n - 1, i = 0;

    while (left <= right) {
        if (i % 2 == 0) 
            temp[i] = arr[right--];
        else 
            temp[i] = arr[left++];
        i++;
    }

    for (int j = 0; j < n; j++) 
        arr[j] = temp[j];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    rearrange(arr, n);

    printf("Rearranged array: ");
    printArray(arr, n);

    return 0;
}