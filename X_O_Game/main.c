#include <stdio.h>

char board[3][3]; // 3x3 board array

// Function to initialize the board
void init_board() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to print the board
void print_board() {
    printf("  0 1 2\n");
    for(int i=0; i<3; i++) {
        printf("%d ", i);
        for(int j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
int check_win(char player) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for(int j=0; j<3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main() {
    char player1 = 'X'; // Player 1 symbol
    char player2 = 'O'; // Player 2 symbol
    char current_player = player1; // Start with player 1
    int row, col;

    init_board(); // Initialize the board

    // Game loop
    while(1) {
        printf("Current player: %c\n", current_player);
        print_board(); // Print the board

        // Get user input for row and column
        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter column (0-2): ");
        scanf("%d", &col);

        // Check if move is valid
        if(board[row][col] != '-') {
            printf("Invalid move, try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = current_player;

        // Check if the game is over
        if(check_win(current_player)) {
            printf("Player %c wins!\n", current_player);
            break; // End the game
        }
        if(board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' &&
           board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' &&
           board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-') {
            printf("Tie game!\n");
            break; // End the game
        }

        // Switch to the other player
        if(current_player == player1) {
            current_player = player2;
        }
        else {
            current_player = player1;
        }
    }

    return 0;
}
