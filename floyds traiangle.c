#include <stdio.h>

int main() {
    int n, num = 1, c, d;

    printf("Enter the number of rows of Floyd's triangle you want: ");
    scanf("%d", &n);

    printf("Floyd's triangle:\n");
    for (c = 1; c <= n; c++) {
        for (d = 1; d <= c; d++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }

    return 0;
}
