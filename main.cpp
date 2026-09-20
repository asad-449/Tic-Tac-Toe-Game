int main() {
    char playAgain;

    do {
        char board[3][3] = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
        };

        char currentPlayer = 'X';
        bool winner = false;

        for(int turn = 0; turn < 9; turn++) {

            cout << "\n";
            for(int i = 0; i < 3; i++) {
                cout << " ";
                for(int j = 0; j < 3; j++) {
                    cout << board[i][j];
                    if(j < 2) cout << " | ";
                }
                cout << endl;
                if(i < 2) cout << "---|---|---" << endl;
            }

            int move;
            cout << "\nPlayer " << currentPlayer << ", enter position: ";
            cin >> move;

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if(board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = currentPlayer;
            } else {
                cout << "Invalid Move! Try Again.\n";
                turn--;
                continue;
            }

            bool win = false;

            for(int i = 0; i < 3; i++) {
                if(board[i][0] == currentPlayer &&
                   board[i][1] == currentPlayer &&
                   board[i][2] == currentPlayer)
                    win = true;

                if(board[0][i] == currentPlayer &&
                   board[1][i] == currentPlayer &&
                   board[2][i] == currentPlayer)
                    win = true;
            }

            if(board[0][0] == currentPlayer &&
               board[1][1] == currentPlayer &&
               board[2][2] == currentPlayer)
                win = true;

            if(board[0][2] == currentPlayer &&
               board[1][1] == currentPlayer &&
               board[2][0] == currentPlayer)
                win = true;

            if(win) {
                cout << "\nPlayer " << currentPlayer << " Wins!\n";
                winner = true;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        if(!winner) {
            cout << "\nGame Draw!\n";
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank you for playing!\n";

    return 0;
}
