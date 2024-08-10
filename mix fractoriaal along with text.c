#include <stdio.h>
#include <ctype.h>

// Function to calculate factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    char str[100];
    int i;

    // Get the string input from the user
    printf("Enter a string: ");
    scanf("%s", str);

    // Print the characters
    printf("Characters in the string:\n");
    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            printf("%c ", str[i]);
        }
    }
    printf("\n");

    // Print digits and their factorials
    printf("Digits and their factorials:\n");
    for (i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            int num = str[i] - '0'; // Convert char to int
            printf("%d! = %d\n", num, factorial(num));
        }
    }

    return 0;
}

