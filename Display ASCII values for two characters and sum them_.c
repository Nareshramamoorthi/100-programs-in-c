// Zoho Interview Question: ASCII Operations // Program: Display ASCII values for two characters and sum them

#include <stdio.h> int main() { char ch1, ch2; printf("Enter two characters: "); scanf(" %c %c", &ch1, &ch2);

int ascii1 = (int)ch1;
int ascii2 = (int)ch2;
int sum = ascii1 + ascii2;

printf("ASCII of %c: %d\n", ch1, ascii1);
printf("ASCII of %c: %d\n", ch2, ascii2);
printf("Sum of ASCII values: %d\n", sum);

return 0;

}

