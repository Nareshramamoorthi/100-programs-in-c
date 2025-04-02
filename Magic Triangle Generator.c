#include <stdio.h>

void generateMagicTriangle(int n) {
    int arr[n][n];
    
    for (int i = 0; i < n; i++) {
        arr[i][0] = arr[i][i] = 1;  

        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]; 
        }
    }

    printf("Magic Triangle of size %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - i; k++)  
            printf("  ");
        for (int j = 0; j <= i; j++)  
            printf("%4d ", arr[i][j]);
        printf("\n");
    }
}

int main() {
    int size = 6; 
    generateMagicTriangle(size);
    return 0;
}
