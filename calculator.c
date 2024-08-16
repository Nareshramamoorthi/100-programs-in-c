// C Program to Make a Simple Calculator using if-else Statements
#include <limits.h>
#include <stdio.h>

// Function that implements the simple calculator
double simpleCalc(double num1, double num2, char op) {
    int result;

    // Perform the corresponding operation
    if (op == '+') {

        // Addition
        result = num1 + num2;
    }
    else if (op == '-') {

        // Subtraction
        result = num1 - num2;
    }
    else if (op == '*') {

        // Multiplication
        result = num1 * num2;
    }
    else if (op == '/') {

        // Division
        // Check for division by zero
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            printf("Error! Division by zero.\n");
            return INT_MIN;
        }
    }
    else {
        printf("Error! Operator is not correct.\n");
        return INT_MIN;
    }

    return result;
}

int main() {
    char op;
    double num1, num2;

    // Read the operator
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);

    // Read the two numbers
    printf("Enter two operands: ");
    scanf("%lf %lf", &num1, &num2);

    double result = simpleCalc(num1, num2, op);

    printf("Result: %.2lf\n", result);

    return 0;
}

