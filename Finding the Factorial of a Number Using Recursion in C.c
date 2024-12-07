#include <stdio.h>

// Recursive function to calculate factorial
long long factorial(int num) {
    if (num == 0 || num == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    } else {
        return num * factorial(num - 1); // Recursive case
    }
}

int main() {
    int num;

    // Input from user
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    // Check for negative numbers
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Call the recursive function and display the result
        printf("Factorial of %d is %lld\n", num, factorial(num));
    }

    return 0;
}
