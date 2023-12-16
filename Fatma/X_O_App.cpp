// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <bits/stdc++.h>
#include"BoardGame_Classes.hpp"
using namespace std;

int main() {
    Connect_Four_Board c;
    c.update_board(1,4,'X');
    c.update_board(1,5,'O');
    c.update_board(1,5,'X');
    c.update_board(1,6,'O');
    c.update_board(1,6,'O');
    c.update_board(1,6,'X');
    c.update_board(1,7,'O');
    c.update_board(1,7,'O');
    c.update_board(1,7,'O');
    c.update_board(1,7,'X');

    c.update_board(1,4,'X');
    c.update_board(1,3,'O');
    c.update_board(1,3,'X');
    c.update_board(1,2,'O');
    c.update_board(1,2,'O');
    c.update_board(1,2,'X');
    c.update_board(1,1,'O');
    c.update_board(1,1,'O');
    c.update_board(1,1,'O');
    c.update_board(1,1,'X');

    c.update_board(1,1,'X');
    c.update_board(1,2,'X');
    c.update_board(1,3,'X');



    c.display_board();

    if(c.check_neg_diag()){
        cout<<"YAY\n";
    }
    else{
        cout<<"WOOPS\n";
    }
    if(c.check_pos_diag()){
        cout<<"YAY\n";
    }
    else{
        cout<<"WOOPS\n";
    }
//    c.update_board(100,5,'Z');
//    c.display_board();
//    c.update_board(100,1,'Z');
//    int choice;
//    Player* players[2];
//    players[0] = new Player (1, 'x');
//
//    cout << "Welcome to FCAI X-O Game. :)\n";
//    cout << "Press 1 if you want to play with computer: ";
//    cin >> choice;
//    if (choice != 1)
//        players[1] = new Player (2, 'o');
//    else
//        //Player pointer points to child
//        players[1] = new RandomPlayer ('o', 3);
//
//    GameManager x_o_game (new X_O_Board(), players);
//    x_o_game.run();
//    system ("pause");

}
