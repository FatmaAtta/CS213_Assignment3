// File name: Connect_Four_Board.cpp
// Purpose: Connect Four game implementation
// Author(s): Fatma Mahmoud
// ID(s): 20220510
// Section: S9
// Date: Dec 18
// Version: 1.0

#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std;

Connect_Four_Board::Connect_Four_Board() {
    n_rows=6;
    n_cols=7;
    board = new char*[n_rows];
    for(int i=0; i<n_rows;i++){
        board[i]=new char[n_cols];
        for(int j=0;j<n_cols;j++){
            board[i][j]=' ';
        }
    }
}

bool Connect_Four_Board::update_board(int x, int y, char mark) {
    col_num=y;
    if((y>=1&&y<=7)&&col[y-1]<6){
        board[5-col[y-1]][y-1]=toupper(mark);
        col[y-1]++;
//        cout<<"sucess";
        n_moves++;
        return true;
    }
    else{
        cout<<"Invalid Position\n";
        return false;
    }

}

//bool Connect_Four_Board::check_hor() {
//    char symbol;
//    int count=0;
//    for(int i=0;i<n_rows;i++){
//        int j=0;
//        while(/*count<4&&*/j<n_cols-1){
//            if((board[i][j]==board[i][j+1])&&(board[i][j]!=' '&&board[i][j+1]!=' ')){
//                count++;
//                j++;
//            }
//            else{
//                count=0;
//                j++;
//            }
//            if(count==4){
//                cout<<"i= "<<i<<"\n";
//                cout<<board[i][j-1];
//                cout<<symbol<<"\n";
//                return true;
//            }
//        }
//    }
//    return false;
//}
bool Connect_Four_Board::check_hor() {
//    char symbol;
    int count = 0;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols - 3; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                symbol=board[i][j] ;
//                cout<<symbol<<"\n";
                return true;
            }
        }
    }
    return false;
}

bool Connect_Four_Board::check_ver() {
//    char symbol;
    int count = 0;
    for (int i = 0; i < n_cols; i++) {
        for (int j = 0; j < n_rows - 3; j++) {
            if (board[j][i] != ' ' && board[j][i] == board[j+1][i] && board[j][i] == board[j + 2][i] && board[j][i] == board[j + 3][i]) {
                symbol=board[j][i] ;
                cout<<symbol<<"\n";
                return true;
            }
        }
    }
    return false;
}

bool Connect_Four_Board::check_pos_diag(){
//    char symbol;
    for(int i=3;i<n_rows;i++){
        for(int j=0;j<n_cols;j++){
            if(board[i][j]!=' '&&board[i][j]==board[i-1][j+1]&&board[i][j]==board[i-2][j+2]&&board[i][j]==board[i-3][j+3]){
//                cout<<"YAY!\n";
                symbol=board[i][j];
//                cout<<symbol<<"\n";
                return true;
            }
        }
    }

    return false;
}

bool Connect_Four_Board::check_neg_diag(){
//    char symbol;
    for(int i=0;i<n_rows-3;i++){
        for(int j=0;j<n_cols-3;j++){
            if(board[i][j]!=' '&&board[i][j]==board[i+1][j+1]&&board[i][j]==board[i+2][j+2]&&board[i][j]==board[i+3][j+3]){
//                cout<<"YAY!\n";
                symbol=board[i][j];
//                cout<<symbol<<"\n";
                return true;
            }
        }
    }
    return false;
}

bool Connect_Four_Board::is_winner() {
    if(check_neg_diag()||check_pos_diag()||check_ver()||check_hor()){
        return true;
    }
    return false;
}
bool Connect_Four_Board::is_draw() {
    return ((n_moves==n_rows*n_cols)&&!is_winner());
}
bool Connect_Four_Board::game_is_over() {
    return (n_moves>=n_rows*n_cols);
}

void Connect_Four_Board::display_board() {
    cout<<"\n\n";
    cout<<"    ";
//    cout<<"\n\n";
//    system("cls");
    for(int i=0;i<n_cols;i++){
        cout<<setw(5)<<" "<<setw(5)<<i+1<<setw(5)<<" ";
    }
    cout<<"\n\n";
    for(int i=0;i<n_rows;i++){
        cout<<setw(4)<<i+1;
        for(int j=0;j<n_cols;j++){
            cout<<setw(5)<<"|"<<setw(5)<<board[i][j]<<setw(5)<<"|";
        }
        cout<<"\n\n";
    }
//for(int i=0;i<n_rows;i++){
//    for(int j=0;j<n_cols;j++){
//        cout<<board[i][j]<<" ";
//    }
//    cout<<"\n";
//}
}

