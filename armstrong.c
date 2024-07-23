#include <stdio.h>

int main() {
    int number, originalNumber, reverse, result = 0;

    // Input number from user
    printf("Enter an integer: ");
    scanf("%d", &number);

    originalNumber = number;

    // Calculate result as sum of cubes of digits
    while (originalNumber != 0) {
        reverse = originalNumber % 10;
        result += reverse * reverse * reverse;
        originalNumber /= 10;
    }

    // Check if the number is Armstrong and print appropriate message
    if (number == result) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}
