#include <iostream>
using namespace std;


void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], char player, int row, int col);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
void switchPlayer(char &currentPlayer);
bool playAgain();

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    do {
        
        displayBoard(board);

        
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (makeMove(board, currentPlayer, row, col)) {
            
            gameWon = checkWin(board, currentPlayer);
            if (gameWon) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            
            gameDraw = checkDraw(board);
            if (gameDraw) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            
            switchPlayer(currentPlayer);
        } else {
            cout << "Invalid move. Try again." << endl;
        }

    } while (true);


    if (playAgain()) {
        main();  
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}


void displayBoard(char board[3][3]) {
    cout << "Game Board:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}


bool makeMove(char board[3][3], char player, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    } else {
        return false;
    }
}


bool checkWin(char board[3][3], char player) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}


bool checkDraw(char board[3][3]) {
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
