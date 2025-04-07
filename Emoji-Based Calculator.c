#include <stdio.h>
#include <string.h>

int emojiToNum(char emoji[]) {
    if (strcmp(emoji, "😊") == 0) return 1;
    if (strcmp(emoji, "😂") == 0) return 2;
    if (strcmp(emoji, "😍") == 0) return 3;
    if (strcmp(emoji, "🤩") == 0) return 4;
    if (strcmp(emoji, "😎") == 0) return 5;
    return 0;
}

int main() {
    char emoji1[10], emoji2[10], op;
    printf("Enter first emoji: ");
    scanf("%s", emoji1);
    printf("Enter operator (+,-,*,/): ");
    scanf(" %c", &op);
    printf("Enter second emoji: ");
    scanf("%s", emoji2);

    int num1 = emojiToNum(emoji1);
    int num2 = emojiToNum(emoji2);

    if (num1 == 0 || num2 == 0) {
        printf("Invalid emoji input.\n");
        return 0;
    }

    int result;
    switch(op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = (num2 != 0) ? num1 / num2 : 0; break;
        default: printf("Invalid operator.\n"); return 0;
    }

    printf("Result: %d\n", result);
    return 0;
}
