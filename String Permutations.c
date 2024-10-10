#include <stdio.h>
#include <string.h>

// Function to swap two characters
void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate all permutations of a string
void permute(char* str, int left, int right) {
    // Base case: If left index equals the right index, a permutation is complete
    if (left == right) {
        printf("%s\n", str);  // Print the current permutation
    } else {
        // Loop through all characters
        for (int i = left; i <= right; i++) {
            // Swap the current character with the leftmost character
            swap(&str[left], &str[i]);

            // Recurse to generate all permutations with the current character fixed
            permute(str, left + 1, right);

            // Backtrack: Swap back the characters to restore the original order
            swap(&str[left], &str[i]);
        }
    }
}

int main() {
    char str[100];  // Input string

    // Take input from the user
    printf("Enter a string: ");
    scanf("%s", str);

    // Get the length of the string
    int n = strlen(str);

    // Call the function to generate all permutations of the string
    permute(str, 0, n - 1);

    return 0;
}
