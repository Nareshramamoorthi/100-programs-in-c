#include <stdio.h>
#include <string.h>

void convertToWords(long long int n);

const char *ones[] = {"", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN",
                      "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN",
                      "EIGHTEEN", "NINETEEN"};
const char *tens[] = {"", "", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"};
const char *places[] = {"", "THOUSAND", "MILLION", "BILLION", "TRILLION"};

void printWords(long long int n) {
    if (n >= 100) {
        printf("%s HUNDRED ", ones[n / 100]);
        n %= 100;
    }
    if (n >= 20) {
        printf("%s ", tens[n / 10]);
        n %= 10;
    }
    if (n > 0) {
        printf("%s ", ones[n]);
    }
}

void convertToWords(long long int n) {
    if (n == 0) {
        printf("ZERO\n");
        return;
    }

    int place = 0;
    char result[1000] = "";

    while (n > 0) {
        int segment = n % 1000; // Take last 3 digits
        n /= 1000;

        if (segment > 0) {
            char segmentStr[100] = "";
            sprintf(segmentStr, "%s %s ", places[place], result); // Add place (e.g., Thousand, Million)
            strcpy(result, segmentStr);

            printWords(segment);
            if (place > 0 && n > 0) printf("%s ", places[place]);
        }
        place++;
    }
    printf("\n");
}

int main() {
    long long int num;
    printf("Enter a number (up to 99999999999999): ");
    scanf("%lld", &num);

    printf("Output: ");
    convertToWords(num);
    return 0;
}
