#include <stdio.h>
#include <string.h>

// Function to get the integer value of a Roman numeral character
int romanToInt(char ch) {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

// Function to convert a Roman numeral to an integer
int convertRomanToInteger(char roman[]) {
    int total = 0;
    int length = strlen(roman);

    for (int i = 0; i < length; i++) {
        int current = romanToInt(roman[i]);
        int next = romanToInt(roman[i + 1]);

        if (next > current) {
            total += (next - current);
            i++;  // Skip the next character
        } else {
            total += current;
        }
    }
    return total;
}

int main() {
    char roman[20];

    printf("Enter a Roman numeral: ");
    scanf("%s", roman);

    int result = convertRomanToInteger(roman);
    printf("The integer value of the Roman numeral %s is %d.\n", roman, result);

    return 0;
}
