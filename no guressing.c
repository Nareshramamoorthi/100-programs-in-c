#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to play the guessing game
void playGame() {
    int randomNumber, guess, attempts = 0;

    // Generate a random number between 1 and 100
    srand(time(0));
    randomNumber = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess a number between 1 and 100:\n");

    // Loop until the user guesses the correct number
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", randomNumber, attempts);
        }
    } while (guess != randomNumber);
}

int main() {
    playGame(); // Start the game
    return 0;
}

