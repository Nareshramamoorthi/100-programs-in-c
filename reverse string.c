#include <stdio.h>
#include <string.h>

int main() {
    char original[100];
    char reverse[100] = "";
    int length, i;

    printf("Enter a string to reverse: ");
    fgets(original, sizeof(original), stdin);

    // Remove newline character from fgets input
    original[strcspn(original, "\n")] = '\0';

    length = strlen(original);

    // Reverse the string
    for (i = length - 1; i >= 0; i--) {
        strncat(reverse, &original[i], 1);
    }

    printf("Reverse of entered string is: %s\n", reverse);

    return 0;
}

