#include <stdio.h>
int main() {
    int a, reverse = 0;
    scanf("%d", &a);
    while (a != 0) {
        int remainder = a % 10;
        reverse = reverse * 10 + remainder;
        a = a / 10;
    }
    printf("Reversed number: %d\n", reverse);
    return 0;
}
