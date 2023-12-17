// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    // Create a 5x5 Tic Tac Toe board
    5x5_X_O_Board board;

    // Sample gameplay
    board.update_board(0, 0, 'X');
    board.update_board(1, 1, 'O');
    board.update_board(0, 1, 'X');
    board.update_board(1, 2, 'O');
    board.update_board(0, 2, 'X');
    board.update_board(1, 3, 'O');
    board.update_board(0, 3, 'X');

    // Display the board
    board.display_board();

    // Check for a winner or a draw
    if (board.is_winner()) {
        cout << "We have a winner!" << endl;
    } else if (board.is_draw()) {
        cout << "It's a draw!" << endl;
    } else {
        cout << "Game is still ongoing..." << endl;
    }

    return 0;
}
