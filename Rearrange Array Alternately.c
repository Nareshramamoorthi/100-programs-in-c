#include <stdio.h>

void rearrange(int arr[], int n) {
    int temp[n];
    int left = 0, right = n - 1, i = 0;

    while (left <= right) {
        if (i % 2 == 0)
            temp[i] = arr[right--];  // Pick max
        else
            temp[i] = arr[left++];   // Pick min
        i++;
    }

    for (i = 0; i < n; i++)
        arr[i] = temp[i];  // Copy back to original array
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);
    printf("Rearranged array: ");
    printArray(arr, n);

    return 0;
}
