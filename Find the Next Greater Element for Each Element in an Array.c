#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char str[]) {
    int n = strlen(str);
    int maxLength = 0;
    int start = 0;
    int visited[256] = { -1 };  

    for (int end = 0; end < n; end++) {
        if (visited[str[end]] >= start) {  
            start = visited[str[end]] + 1;  
        }
        visited[str[end]] = end;  
        int length = end - start + 1;
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;
}

int main() {
    char str[] = "zohointerview";
    printf("Length of longest unique substring: %d\n", longestUniqueSubstring(str));
    return 0;
}