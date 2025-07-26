#include<bits/stdc++.h>
using namespace std;

char board[3][3];        // global 3x3 board to store X and O
void initializeBoard() {
    char count = '1';  // start from character '1'
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = count++;  // fill board with '1' to '9'
}

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];               // print cell
            if (j < 2) cout << " | ";          // add vertical line
        }
        if (i < 2) cout << "\n_____________\n";  // add horizontal line
    }
    cout << "\n\n";
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}
bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;  // a cell is still empty
    return true;
}

bool makeMove(char player) {
    int pos;
    cout << "Player " << player << ", enter a number (1-9): ";
    cin >> pos;

    int row = (pos - 1) / 3;     // convert position to row index
    int col = (pos - 1) % 3;     // convert position to column index

    if (pos < 1 || pos > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        return false;           // don't switch turn
    }

    board[row][col] = player;   // make the move
    return true;                // valid move
}


int main() {
    char currentPlayer = 'X';      // X always starts
    initializeBoard();

    while (true) {
        printBoard();              // show current state

        if (!makeMove(currentPlayer))
            continue;              // invalid move → retry same player

        if (checkWin(currentPlayer)) {
            printBoard();
            cout << " Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw()) {
            printBoard();
            cout << " It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // switch turns
    }

    return 0;
}

