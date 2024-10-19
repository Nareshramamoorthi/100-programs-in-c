#include <stdio.h>

char board[3][3];  // 3x3 game board
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  -----\n");
    }
}

int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return 1;  // Row win
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return 1;  // Column win
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return 1;  // Diagonal win
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return 1;  // Anti-diagonal win

    return 0;  // No winner
}

int isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;  // Board is not full
    return 1;  // Board is full
}

void changePlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // Switch between X and O
}

int main() {
    int row, col;
    currentPlayer = 'X';  // Start with player X
    initializeBoard();

    while (1) {
        printBoard();
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check for valid input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;  // Place the player's mark

        // Check for a winner
        if (checkWinner()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        // Check for a draw
        if (isBoardFull()) {
            printBoard();
            printf("The game is a draw!\n");
            break;
        }

        changePlayer();  // Switch player
    }

    return 0;
}
