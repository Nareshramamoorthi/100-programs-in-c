#include <stdio.h>

void countFrequency(int num) {
    int freq[10] = {0};
    
    while (num > 0) {
        int digit = num % 10;
        freq[digit]++;
        num /= 10;
    }
    
    printf("Digit Frequency:\n");
    for (int i = 0; i < 10; i++) {
        if (freq[i] > 0) {
            printf("%d => %d times\n", i, freq[i]);
        }
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    countFrequency(num);
    
    return 0;
}
