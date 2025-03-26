#include <stdio.h>
#include <string.h>

#define MAX 256  

int longestUniqueSubstring(char str[]) {
    int lastIndex[MAX]; 
    for (int i = 0; i < MAX; i++)
        lastIndex[i] = -1;

    int maxLength = 0, start = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (lastIndex[str[i]] >= start)
            start = lastIndex[str[i]] + 1;  

        lastIndex[str[i]] = i; 
        maxLength = (i - start + 1 > maxLength) ? (i - start + 1) : maxLength;
    }

    return maxLength;
}

int main() {
    char str[] = "zohointerview";
    printf("Longest unique substring length: %d\n", longestUniqueSubstring(str));
    return 0;
}
