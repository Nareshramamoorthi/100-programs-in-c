#include <stdio.h>

int findMissingPositive(int arr[], int n) {
    int present[n + 1];  

    for (int i = 0; i <= n; i++)  
        present[i] = 0;  

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] <= n)  
            present[arr[i]] = 1;  
    }

    for (int i = 1; i <= n; i++) {
        if (present[i] == 0)  
            return i;  
    }

    return n + 1;  
}

int main() {
    int arr[] = {0, -10, 1, 2,5, -20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissingPositive(arr, n);
    printf("Smallest missing positive number: %d\n", missing);

    return 0;
}