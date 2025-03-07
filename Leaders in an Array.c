#include <stdio.h>

void findLeaders(int arr[], int n) {
    int maxRight = arr[n - 1]; 
    printf("%d ", maxRight); 

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            maxRight = arr[i]; 
            printf("%d ", maxRight);
        }
    }
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLeaders(arr, n);
    return 0;
}
