#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortStrings(char **arr, int n) {
    char *temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();  // Consume newline character

    char **arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter string %d: ", i + 1);
        fgets(arr[i], 100, stdin);
        arr[i][strcspn(arr[i], "\n")] = 0;
    }

    sortStrings(arr, n);

    printf("\nSorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);

    return 0;
}
