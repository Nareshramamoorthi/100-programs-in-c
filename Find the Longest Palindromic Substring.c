#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) 
            return 0;
        start++;
        end--;
    }
    return 1;
}

void findLongestPalindrome(char *str) {
    int maxLength = 0;
    int start = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (isPalindrome(str, i, j) && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    printf("Longest palindrome substring: ");
    for (int i = start; i < start + maxLength; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[] = "babad";
    findLongestPalindrome(str);
    return 0;
}
