#include <stdio.h>

int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int isStrong(int n) {
    int temp = n, sum = 0, digit;

    while (temp > 0) {
        digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    return (sum == n);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isStrong(num))
        printf("%d is a Strong Number\n", num);
    else
        printf("%d is not a Strong Number\n", num);

    return 0;
}
