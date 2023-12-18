// File name: FiveByFive_X_O_Board.cpp
// Purpose: Five by five x o game implementation
// Author(s): Muntasir Gaafar
// ID(s): 20220834
// Section: S9
// Date: Dec 18
// Version: 1.0

#include "BoardGame_Classes.hpp"
using namespace std;

FiveByFive_X_O_Board::FiveByFive_X_O_Board(){
        n_rows = n_cols = 5;
        n_moves = 0;
        board = new char*[n_rows];
        for (int i = 0; i < n_rows; i++) {
            board[i] = new char[n_cols];
            for (int j = 0; j < n_cols; j++)
                board[i][j] = ' ';
	}
}

    bool FiveByFive_X_O_Board::update_board(int x, int y, char mark) {
        if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == ' ')) {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        } else {
            return false;
        }
    }

void FiveByFive_X_O_Board::display_board() {
//    system("cls");
    cout << "   ";
    for (int i = 0; i < n_cols; i++) {
        cout << setw(3) << i << "   ";
    }
    cout << "\n";
    for (int i = 0; i < n_rows; i++) {
        cout << setw(2) << i << " ";
        for (int j = 0; j < n_cols; j++) {
            cout << "|  " << board[i][j] << "  ";
        }
        cout << "|";
        cout << "\n";
        }
   cout << endl;
}

    bool FiveByFive_X_O_Board:: is_winner() {
        if(check_neg_diag()||check_pos_diag()||check_ver()||check_hor()){
            return true;
        }
        return false;
    }
//int countX = 0, countO = 0;
//        // Check rows and columns
//        for (int i = 0; i < 4; i++) {
//            int rowX = 0, rowO = 0, colX = 0, colO = 0;
//            for (int j = 0; j < 4; j++) {
//                if (board[i][j] == 'X') {
//                    rowX++;
//                    if (rowX == 3) countX++;
//                } else if (board[i][j] == 'O') {
//                    rowO++;
//                    if (rowO == 3) countO++;
//                }
//
//                if (board[j][i] == 'X') {
//                    colX++;
//                    if (colX == 3) countX++;
//                } else if (board[j][i] == 'O') {
//                    colO++;
//                    if (colO == 3) countO++;
//                }
//            }
//        }
//
//        // Check diagonals
//        int diagX1 = 0, diagO1 = 0, diagX2 = 0, diagO2 = 0;
//        for (int i = 0; i < n_rows; i++) {
//            if (board[i][i] == 'X') {
//                diagX1++;
//                if (diagX1 == 3) countX++;
//            } else if (board[i][i] == 'O') {
//                diagO1++;
//                if (diagO1 == 3) countO++;
//            }
//
//            if (board[i][n_cols - i - 1] == 'X') {
//                diagX2++;
//                if (diagX2 == 3) countX++;
//            } else if (board[i][n_cols - i - 1] == 'O') {
//                diagO2++;
//                if (diagO2 == 3) countO++;
//            }
//        }
//
//        return countX > countO;
//    }

    bool FiveByFive_X_O_Board:: is_draw() {
        return (n_moves == n_rows * n_cols && !is_winner());
    }

    bool FiveByFive_X_O_Board:: game_is_over() {
        return n_moves >= n_rows * n_cols;
    }
bool FiveByFive_X_O_Board::check_hor() {
//    int count = 0;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols - 2; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
                symbol=board[i][j] ;
                return true;
            }
        }
    }
    return false;
}
bool FiveByFive_X_O_Board::check_ver() {
    int count = 0;
    for (int i = 0; i < n_cols; i++) {
        for (int j = 0; j < n_rows - 2; j++) {
            if (board[j][i] != ' ' && board[j][i] == board[j+1][i] && board[j][i] == board[j + 2][i]) {
                symbol=board[j][i] ;
                cout<<symbol<<"\n";
                return true;
            }
        }
    }
    return false;
}
bool FiveByFive_X_O_Board::check_pos_diag() {
    for(int i=2;i<n_rows;i++){
        for(int j=0;j<n_cols;j++){
            if(board[i][j]!=' '&&board[i][j]==board[i-1][j+1]&&board[i][j]==board[i-2][j+2]){
//                cout<<"YAY!\n";
                symbol=board[i][j];
//                cout<<symbol<<"\n";
                return true;
            }
        }
    }

    return false;
}
bool FiveByFive_X_O_Board::check_neg_diag() {
    for(int i=0;i<3;i++){
        for(int j=0;j<n_cols-2;j++){
            if(board[i][j]!=' '&&board[i][j]==board[i+1][j+1]&&board[i][j]==board[i+2][j+2]){
//                cout<<"YAY!\n";
                symbol=board[i][j];
//                cout<<symbol<<"\n";
                return true;
            }
        }
    }
    return false;
}