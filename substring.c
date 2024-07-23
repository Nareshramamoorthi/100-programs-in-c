#include <stdio.h>
#include <string.h>

int main() {
    char string[100];  // Assuming maximum string length is 100 characters
    int i, c, length;

    printf("Enter a string to print its all substrings: ");
    fgets(string, sizeof(string), stdin);

    // Remove newline character from fgets input
    string[strcspn(string, "\n")] = '\0';

    length = strlen(string);

    printf("Substrings of \"%s\" are:\n", string);

    // Generate all substrings
    for (c = 0; c < length; c++) {
        for (i = 1; i <= length - c; i++) {
            printf("%.*s\n", i, string + c);
        }
    }

    return 0;
}
