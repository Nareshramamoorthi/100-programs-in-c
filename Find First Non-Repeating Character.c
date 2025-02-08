#include <stdio.h>
#include <string.h>

#define SIZE 256

char firstNonRepeatingChar(char *str) {
    int count[SIZE] = {0};
    
    for (int i = 0; str[i]; i++)
        count[(int)str[i]]++;

    for (int i = 0; str[i]; i++)
        if (count[(int)str[i]] == 1)
            return str[i];

    return '\0';
}

int main() {
    char str[] = "zohozo";
    char result = firstNonRepeatingChar(str);
    
    if (result)
        printf("First Non-Repeating Character: %c\n", result);
    else
        printf("No unique character found\n");

    return 0;
}
