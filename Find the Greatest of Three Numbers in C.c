#include <stdio.h>

int main() {
    float num1, num2, num3;

    // Input three numbers
    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    // Check for the greatest number
    if (num1 >= num2 && num1 >= num3) {
        printf("The greatest number is: %.2f\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("The greatest number is: %.2f\n", num2);
    } else {
        printf("The greatest number is: %.2f\n", num3);
    }

    return 0;
}
