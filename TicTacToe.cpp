
// Two Standard Libraries
#include <iostream>
#include <cstring>
/**
 * Sources: 
 *          https://junilearning.com/blog/coding-projects/java-beginner-tic-tac-toe-tutorial/ 
 *          Used The Same Concept But Added Difference
 *          https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
 *          Error Handling From User Input
 *          https://www.w3schools.com/cpp/default.asp - General Knowledge
*/

/**
 * std (Standard) namespace
 * Gives Access To Standard C++ Library Functions and Objects
 * Without Specifying 'std::' Prefix
 * */
using namespace std;

// Define The Size Of The Board
const int BOARD_SIZE = 3;

// Initialize a Variable To Keep Track If The Game Is Stil In Progress
bool gameInProgress = true;

// Initialize The Board To Empty Square
void initBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = '-';
        }
    }
}

// Print The Current State Of The Board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// Check If a Player Has Won
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true;
        }
    }

    // Check Columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }

    // Check Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Check If The Game Is Over (Either a Player Has Won Or The Board Is Full)
bool isGameOver(char board[BOARD_SIZE][BOARD_SIZE], char currentPlayer) {
    // Check Rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == currentPlayer && board[row][1] == currentPlayer && board[row][2] == currentPlayer) {
            return true;
        }
    }

    // Check Columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == currentPlayer && board[1][col] == currentPlayer && board[2][col] == currentPlayer) {
            return true;
        }
    }

    // Check Diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }

    // Check For Empty Squares
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == '-') {
                return false;
            }
        }
    }

    // If True, The Board Is Full and There's No Winner
    return true;
}

// Make a Move On The Board
bool makeMove(char board[BOARD_SIZE][BOARD_SIZE], char player, int row, int col) {

    // Check If The Move Is Valid
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '-') {
        return false;
    }

    // Update The Board With The New Move
    board[row][col] = player;

    return true;
}

// Main Method
int main() {
    // Declaring a 2D Array
    char board[BOARD_SIZE][BOARD_SIZE];
    // Sets The currentPlayer's Choice To 'X'
    char currentPlayer = 'X';

    // Initialize The Board To Empty Squares
    initBoard(board);

    while (gameInProgress) {
    // Print The Current State Of The Board
    printBoard(board);

    // Get The Current Player's Move
    bool validMove = false;
    while (!validMove) {
        cout << "Player " << currentPlayer << ", Enter Your Move (Row): ";
        int row;
        cin >> row;

            /**Check if input is a string
             * cin.fail() Checks If The Input From The User Is Invalid/Failed
             * **/
            if (cin.fail()) {
                cout << "Invalid input. Please enter a number for the row." << endl;
                /**
                 * Program Clears The Input
                 * cin.clear() Commonly Used To Clear Error Flags From User Inputs
                */
                cin.clear();
                // Then Ignores The Invalid Input
                cin.ignore(256,'\n');
                /**
                 * Skips The Current Iteration From The Loop 
                 * and Proceeds To The Next Iteration
                 */ 
                continue;
                // Breaks From The Loop and Into The If Statement
                break;
            }
        row--; // Row = Row - 1

        cout << "Player " << currentPlayer << ", Enter Your Move (Column): ";
        int col;
        cin >> col;

        // Check if input is a string
            if (cin.fail()) {
                cout << "Invalid input. Please enter a number for the row." << endl;
                /**
                 * Program Clears The Input
                 * cin.clear() Commonly Used To Clear Error Flags From User Inputs
                */
                cin.clear();
                // Then Ignores The Invalid Input
                cin.ignore(256,'\n');
                /**
                 * Skips The Current Iteration From The Loop 
                 * and Proceeds To The Next Iteration
                 */ 
                continue;
                // Breaks From The Loop and Into The If Statement
                break;
            }
        col--; // Col = Col - 1

        /**
         * Checks Whether The User Enters The Same Input As The Other Player
        */
        validMove = makeMove(board, currentPlayer, row, col);
    if (!validMove) {
        cout << "Invalid Move, Please Try Again." << endl;
    }
}

        // Check For a Win Or Tie
        if (isGameOver(board, currentPlayer)) {
            printBoard(board);
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " Wins!" << endl;
            } else {
                cout << "Tie Game!" << endl;
            }
            gameInProgress = false;
        }

        // Switch to the other player
        /**
         * ? Is Called a Ternary Operator Used To Represents Conditional Expressions
         * Takes 3 Operands: The Condition To Check, and : To Seperate The True and 
         * False Conditions
        */
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}