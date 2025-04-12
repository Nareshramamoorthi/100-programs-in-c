#include <stdio.h>
#include <string.h>

#define SIZE 256

char firstUniqueChar(char *str) {
    int count[SIZE] = {0};

    for (int i = 0; str[i]; i++)
        count[(int)str[i]]++;

    for (int i = 0; str[i]; i++)
        if (count[(int)str[i]] == 1)
            return str[i];

    return '-';
}

int main() {
    char str[] = "engineering";
    char result = firstUniqueChar(str);

    if (result != '-')
        printf("First unique character: %c\n", result);
    else
        printf("No unique character found.\n");

    return 0;
}
