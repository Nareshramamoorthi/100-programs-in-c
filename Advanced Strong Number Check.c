#include <stdio.h>

// Function to calculate factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to check if the number is a strong number
int isStrongNumber(int num) {
    int originalNum = num, sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }
    return sum == originalNum;
}

int main() {
    int number;

    printf("Enter a number to check if it is a Strong Number: ");
    scanf("%d", &number);

    if (isStrongNumber(number)) {
        printf("%d is a Strong Number.\n", number);
    } else {
        printf("%d is not a Strong Number.\n", number);
    }

    return 0;
}
