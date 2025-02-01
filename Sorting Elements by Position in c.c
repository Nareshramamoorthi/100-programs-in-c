#include <stdio.h>

void sortOddEven(int arr[], int n) {
    int odd[50], even[50], oddCount = 0, evenCount = 0;

    // Separate odd and even index elements
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) 
            odd[oddCount++] = arr[i];
        else 
            even[evenCount++] = arr[i];
    }

    // Sort odd index elements in descending order
    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = i + 1; j < oddCount; j++) {
            if (odd[i] < odd[j]) {
                int temp = odd[i];
                odd[i] = odd[j];
                odd[j] = temp;
            }
        }
    }

    // Sort even index elements in ascending order
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = i + 1; j < evenCount; j++) {
            if (even[i] > even[j]) {
                int temp = even[i];
                even[i] = even[j];
                even[j] = temp;
            }
        }
    }

    // Merge back into the original array
    oddCount = 0;
    evenCount = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) 
            arr[i] = odd[oddCount++];
        else 
            arr[i] = even[evenCount++];
    }
}

int main() {
    int arr[] = {13, 2, 4, 15, 12, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortOddEven(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}