
Title: Random Number Guessing Game
Description: A program that generates random numbers and runs until the user guesses correctly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int generateRandomNumber() {
    return (rand() % 10) + 1;
}

// Function to check the user's guess
int checkGuess(int randomNum, int userGuess) {
    if (userGuess == randomNum) {
        return 1; // Correct guess
    }
    if (userGuess < randomNum) {
        printf("Too low! Try again.\n");
    } else {
        printf("Too high! Try again.\n");
    }
    return 0; // Incorrect guess
}

int main() {
    int randomNumber, userGuess, isCorrect = 0;

    // Seed the random number generator
    srand(time(0));
    randomNumber = generateRandomNumber();

    printf("Guess the number (1 to 10):\n");

    while (!isCorrect) {
        printf("Enter your guess: ");
        if (scanf("%d", &userGuess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (userGuess < 1 || userGuess > 10) {
            printf("Please guess a number between 1 and 10 only.\n");
            continue;
        }

        isCorrect = checkGuess(randomNumber, userGuess);
    }

    printf("Congratulations! You guessed it right. The number was %d.\n", randomNumber);

    return 0;
}
