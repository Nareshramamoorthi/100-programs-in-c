#include <stdio.h>

int findGCD(int a, int b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("GCD of %d and %d is %d\n", num1, num2, findGCD(num1, num2));

    return 0;
}
