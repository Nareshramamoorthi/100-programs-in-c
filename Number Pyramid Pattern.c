#include <stdio.h>

void printPyramid(int n) {
    int num = 1;  // Starting number
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter the number of rows for the pyramid: ");
    scanf("%d", &rows);

    printPyramid(rows);
    
    return 0;
}
