#include <stdio.h>

void nextGreaterElement(int arr[], int n) {
    int result[n];
    
    for (int i = 0; i < n; i++) {
        result[i] = -1;  
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d -> %d\n", arr[i], result[i]);
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    nextGreaterElement(arr, n);
    return 0;
}