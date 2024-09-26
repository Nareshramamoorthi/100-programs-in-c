#include <stdio.h>
#include <ctype.h> // For isdigit() function

int main() {
    char input[100], ch;
    int i = 0, repeat;

    // Taking input from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Loop through each character in the input string
    while (input[i] != '\0') {
        ch = input[i]; // Get the character
        i++;

        // Check if the next character is a digit
        if (isdigit(input[i])) {
            repeat = input[i] - '0'; // Convert char to int
            for (int j = 0; j < repeat; j++) {
                printf("%c", ch); // Print the character multiple times
            }
            i++; // Move to the next character
        }
    }

    printf("\n");
    return 0;
}
