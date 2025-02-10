#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char str[]) {
    int visited[256] = {0}, left = 0, right = 0, maxLen = 0, start = 0;
    
    while (str[right] != '\0') {
        if (!visited[str[right]]) {
            visited[str[right]] = 1;
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            right++;
        } else {
            visited[str[left]] = 0;
            left++;
        }
    }

    printf("Longest Unique Substring: ");
    for (int i = start; i < start + maxLen; i++)
        printf("%c", str[i]);
    printf("\nLength: %d\n", maxLen);

    return maxLen;
}

int main() {
    char str[] = "abcabcbb";  // Change input string here
    longestUniqueSubstring(str);
    return 0;
}
