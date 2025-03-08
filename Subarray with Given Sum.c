#include <stdio.h>

void findSubarrayWithSum(int arr[], int n, int target) {
    int start = 0, sum = 0;

    for (int end = 0; end < n; end++) {
        sum += arr[end];

        while (sum > target && start <= end) {
            sum -= arr[start];
            start++;
        }

        if (sum == target) {
            printf("Subarray found from index %d to %d\n", start, end);
            return;
        }
    }
    printf("No subarray found\n");
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int target = 33;
    int n = sizeof(arr) / sizeof(arr[0]);

    findSubarrayWithSum(arr, n, target);
    return 0;
}
