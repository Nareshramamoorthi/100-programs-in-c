#include <stdio.h>
#define SIZE 256

char firstNonRepeating(char str[]) {
    int count[SIZE] = {0}; // Frequency array

    for (int i = 0; str[i] != '\0'; i++)
        count[(int)str[i]]++;

    for (int i = 0; str[i] != '\0'; i++)
        if (count[(int)str[i]] == 1)
            return str[i];

    return '\0'; // No non-repeating character found
}

int main() {
    char str[] = "zohozo";
    char result = firstNonRepeating(str);

    if (result != '\0')
        printf("First Non-Repeating Character: %c\n", result);
    else
        printf("No Non-Repeating Character Found\n");

    return 0;
}
