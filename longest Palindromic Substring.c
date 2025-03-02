#include <stdio.h>
#include <string.h>

// Function to expand around center and return longest palindrome length
int expandAroundCenter(char *s, int left, int right) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;  // Length of palindrome
}

// Function to find longest palindromic substring
void longestPalindrome(char *s) {
    int start = 0, maxLen = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);      // Odd length palindrome
        int len2 = expandAroundCenter(s, i, i + 1);  // Even length palindrome
        int currLen = (len1 > len2) ? len1 : len2;

        if (currLen > maxLen) {
            maxLen = currLen;
            start = i - (currLen - 1) / 2;
        }
    }

    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++)
        printf("%c", s[i]);
    printf("\n");
}

int main() {
    char str[] = "babad";
    longestPalindrome(str);
    return 0;
}
