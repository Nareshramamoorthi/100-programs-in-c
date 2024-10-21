#include <stdio.h>
#include <string.h>

// Function to expand from the center and check for the longest palindrome
int expandAroundCenter(char *str, int left, int right) {
    while (left >= 0 && right < strlen(str) && str[left] == str[right]) {
        left--;
        right++;
    }
    // Return length of the palindrome found
    return right - left - 1;
}

// Function to find the longest palindrome in the string
void findLongestPalindrome(char *str) {
    int start = 0, maxLength = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        // Check for odd length palindrome (center at i)
        int len1 = expandAroundCenter(str, i, i);
        // Check for even length palindrome (center between i and i+1)
        int len2 = expandAroundCenter(str, i, i + 1);

        int curLength = (len1 > len2) ? len1 : len2;

        if (curLength > maxLength) {
            maxLength = curLength;
            start = i - (curLength - 1) / 2;
        }
    }

    // Print the longest palindromic substring
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLength; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from fgets
    str[strcspn(str, "\n")] = 0;

    findLongestPalindrome(str);

    return 0;
}
