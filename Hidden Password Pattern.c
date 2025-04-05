#include <stdio.h>
#include <ctype.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int isPatternValid(char* str) {
    for (int i = 1; str[i]; i++) {
        if (isVowel(str[i]) == isVowel(str[i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);

    if (isPatternValid(password))
        printf("Valid hidden pattern!\n");
    else
        printf("Pattern does not match.\n");

    return 0;
}
