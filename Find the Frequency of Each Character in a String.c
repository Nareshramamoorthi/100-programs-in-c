#include <stdio.h>
#include <string.h>

void countCharacterFrequency(char *str) {
    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }

    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i, freq[i]);
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = 0;

    countCharacterFrequency(str);

    return 0;
}
