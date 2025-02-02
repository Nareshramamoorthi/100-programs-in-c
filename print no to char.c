#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int maxLen = 0;
    int start = 0;
    int index[256] = {0};

    for (int i = 0; i < n; i++) {
        if (index[s[i]] > start) {
            start = index[s[i]];
        }
        index[s[i]] = i + 1;
        maxLen = (maxLen > i - start + 1) ? maxLen : i - start + 1;
    }
    return maxLen;
}

int main() {
    char str[] = "abcabcbb";
    int len = lengthOfLongestSubstring(str);
    printf("Length of longest substring without repeating characters: %d\n", len);
    return 0;
}