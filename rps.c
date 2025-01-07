/*
Title: Rock-Paper-Scissors Game
Description: A random Rock-Paper-Scissors game where the user competes against the computer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the computer's random choice
const char* getComputerChoice() {
    int random = rand() % 3; // 0 = Rock, 1 = Paper, 2 = Scissors
    if (random == 0) return "Rock";
    if (random == 1) return "Paper";
    return "Scissors";
}

// Function to determine the winner
int determineWinner(const char* userChoice, const char* computerChoice) {
    if (strcmp(userChoice, computerChoice) == 0) {
        return 0; // Tie
    }
    if ((strcmp(userChoice, "Rock") == 0 && strcmp(computerChoice, "Scissors") == 0) ||
        (strcmp(userChoice, "Paper") == 0 && strcmp(computerChoice, "Rock") == 0) ||
        (strcmp(userChoice, "Scissors") == 0 && strcmp(computerChoice, "Paper") == 0)) {
        return 1; // User wins
    }
    return -1; // Computer wins
}

int main() {
    char userChoice[10];
    const char* computerChoice;
    int userScore = 0, computerScore = 0;

    // Seed the random number generator
    srand(time(0));

    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("Type 'Rock', 'Paper', or 'Scissors' to play. Type 'Quit' to exit.\n");

    while (1) {
        printf("\nYour Choice: ");
        scanf("%s", userChoice);

        // Check if the user wants to quit
        if (strcmp(userChoice, "Quit") == 0) {
            break;
        }

        // Get the computer's random choice
        computerChoice = getComputerChoice();
        printf("Computer's Choice: %s\n", computerChoice);

        // Determine the winner
        int result = determineWinner(userChoice, computerChoice);

        if (result == 0) {
            printf("It's a Tie!\n");
        } else if (result == 1) {
            printf("You Win!\n");
            userScore++;
        } else if (result == -1) {
            printf("Computer Wins!\n");
            computerScore++;
        } else {
            printf("Invalid choice! Please enter 'Rock', 'Paper', or 'Scissors'.\n");
        }
    }

    // Final results
    printf("\n=== Game Over ===\n");
    printf("Your Score: %d\n", userScore);
    printf("Computer's Score: %d\n", computerScore);

    return 0;
}
