#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

// Initialize board
void initializeBoard() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = ' ';
}

// Display board
void displayBoard() {
    cout << "\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << " " << board[i][j] << " ";
            if(j < 2) cout << "|";
        }
        cout << "\n";
        if(i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Check win
bool checkWin() {
    // Rows
    for(int i=0;i<3;i++)
        if(board[i][0]==currentPlayer && board[i][1]==currentPlayer && board[i][2]==currentPlayer)
            return true;

    // Columns
    for(int i=0;i<3;i++)
        if(board[0][i]==currentPlayer && board[1][i]==currentPlayer && board[2][i]==currentPlayer)
            return true;

    // Diagonals
    if(board[0][0]==currentPlayer && board[1][1]==currentPlayer && board[2][2]==currentPlayer)
        return true;

    if(board[0][2]==currentPlayer && board[1][1]==currentPlayer && board[2][0]==currentPlayer)
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' ')
                return false;
    return true;
}

// Switch players
void switchPlayer() {
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';

        while(true) {
            displayBoard();

            int row, col;
            cout << "Player " << currentPlayer << " enter row (1-3) and column (1-3): ";
            cin >> row >> col;

            row--; 
            col--;

            if(row<0 || row>2 || col<0 || col>2 || board[row][col] != ' ') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if(checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if(checkDraw()) {
                displayBoard();
                cout << "Game is a draw!\n";
                break;
            }

            switchPlayer();
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}