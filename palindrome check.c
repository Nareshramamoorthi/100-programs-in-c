// C implementation to check if a given
// string is palindrome or not
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char str[], int l, int h)
{
    // if the string size is 0 or 1
    // it is a palindrome
    if (l >= h)
        return true;

    // if both the terminal characters
    // not matching, not palindrome
    if (str[l] != str[h])
        return false;

    // call the smaller sub-problem
    return isPalindrome(str, l + 1, h - 1);
}

int main()
{
    char str[] = { "abbba" };

    // Start from first and
    // last character of str
    int l = 0;
    int h = strlen(str) - 1;

    bool ans = isPalindrome(str, l, h);
    if (ans) {
        printf("%s is a palindrome\n", str);
    }
    else {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}
