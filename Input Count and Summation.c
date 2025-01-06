/*
Title: Input Count and Summation
Description: Counts the number of inputs, sums them, and subtracts the count from the sum when the user stops input with '.'.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[10]; // Buffer for input
    int count = 0;  // Number of inputs
    int sum = 0;    // Sum of inputs
    int number;     // Temporary storage for each valid input

    printf("Enter numbers to add (type '.' to stop):\n");

    while (1) {
        printf("Input: ");
        scanf("%s", input);

        // Check for termination condition
        if (input[0] == '.' && input[1] == '\0') {
            break;
        }

        // Try converting input to an integer
        number = atoi(input);

        if (number == 0 && input[0] != '0') {
            printf("Invalid input. Please enter a number or '.' to stop.\n");
            continue;
        }

        sum += number; // Add to the sum
        count++;       // Increment the count
    }

    int result = sum - count;

    printf("\nResults:\n");
    printf("Total Count of Inputs: %d\n", count);
    printf("Sum of Numbers: %d\n", sum);
    printf("Final Result (Sum - Count): %d\n", result);

    return 0;
}
