#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_LEN 50

// Function to sort strings alphabetically
void sortStrings(char arr[][MAX_LEN], int n) {
    char temp[MAX_LEN];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                // Swap strings if not in order
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    char strings[MAX][MAX_LEN];
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); // Clear the newline character from input buffer

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(strings[i], MAX_LEN, stdin);
        strings[i][strcspn(strings[i], "\n")] = 0; // Remove newline
    }

    sortStrings(strings, n);

    printf("\nStrings in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
