#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, randomNum, attempts = 0;
    srand(time(0));
    randomNum = rand() % 10 + 1;

    printf("Guess a number between 1 and 10: ");
    do {
        scanf("%d", &guess);
        attempts++;
        if (guess > randomNum) {
            printf("Too high! Try again: ");
        } else if (guess < randomNum) {
            printf("Too low! Try again: ");
        }
    } while (guess != randomNum);

    printf("Congratulations! You guessed it in %d attempts.\n", attempts);
    return 0;
}
