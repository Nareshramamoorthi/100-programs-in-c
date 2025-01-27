Here’s a simple Rock, Paper, Scissors game in C:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to determine the winner
void determineWinner(char user, char computer) {
    if (user == computer) {
        printf("It's a tie!\n");
    } else if ((user == 'R' && computer == 'S') || 
               (user == 'P' && computer == 'R') || 
               (user == 'S' && computer == 'P')) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int main() {
    char userChoice, computerChoice;
    char choices[] = {'R', 'P', 'S'}; // R = Rock, P = Paper, S = Scissors
    srand(time(0));

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
    scanf(" %c", &userChoice);

    // Generate random choice for computer
    computerChoice = choices[rand() % 3];
    printf("Computer chose: %c\n", computerChoice);

    // Determine the winner
    determineWinner(userChoice, computerChoice);

    return 0;
}