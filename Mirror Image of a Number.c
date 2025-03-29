#include <stdio.h>

int mirrorNumber(int num) {
    int mirrored = 0;
    while (num > 0) {
        mirrored = mirrored * 10 + (9 - (num % 10));
        num /= 10;
    }
    return mirrored;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int mirrored = mirrorNumber(num);
    printf("Mirror Image of %d is: %d\n", num, mirrored);
    
    return 0;
}
