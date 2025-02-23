#include <stdio.h>

int reverseNumber(int num, int rev) {
    if (num == 0)
        return rev;
    return reverseNumber(num / 10, rev * 10 + num % 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num == reverseNumber(num, 0))
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}
