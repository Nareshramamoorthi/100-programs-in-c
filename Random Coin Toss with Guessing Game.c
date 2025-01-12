/*
Title: Random Coin Toss with Guessing Game
Description: Simulates a coin toss, determines heads or tails, and checks the user's guess to assign batting or fielding.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, userGuess;
    char choice[10];

    // Initialize random seed
    srand(time(0));

    // Generate a random number (0 or 1)
    randomNumber = rand() % 2;

    // Prompt the user for their guess
    printf("Guess the coin toss result (0 for Tails, 1 for Heads): ");
    scanf("%d", &userGuess);

    // Determine coin toss result
    if (randomNumber == 0) {
        printf("Coin Toss Result: Tails\n");
    } else {
        printf("Coin Toss Result: Heads\n");
    }

    // Check if user's guess matches the result
    if (userGuess == randomNumber) {
        printf("Your guess is correct!\n");
        printf("Choose your preference (batting/bowling): ");
        scanf("%s", choice);
        printf("You chose %s.\n", choice);
    } else {
        printf("Your guess is wrong. You are fielding!\n");
    }

    return 0;
}
