/*
Title: String Manipulation - Expand Characters
Description: Expand characters based on associated numbers without using inbuilt functions.
*/

#include <stdio.h>

int main() {
    char input[100];
    char ch;
    int num, i, j;

    // Input the string
    printf("Enter the input string (e.g., a1b2c3): ");
    scanf("%s", input);

    printf("Output: ");

    // Loop through the input string
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            ch = input[i]; // Get the character
        } else if (input[i] >= '0' && input[i] <= '9') {
            num = input[i] - '0'; // Convert character digit to integer

            // Print the character 'num' times
            for (j = 0; j < num; j++) {
                printf("%c", ch);
            }
        }
    }

    printf("\n");
    return 0;
}
