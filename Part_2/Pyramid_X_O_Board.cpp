#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
Pyramid_X_O_Board::Pyramid_X_O_Board () {
   n_rows = n_cols = 3;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}
// Display the board and the pieces on it
void Pyramid_X_O_Board::display_board() {
   for (int i: {0,1,2}) {
      cout << "\n| ";
      for (int j: {0,1,2}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n-----------------------------";
   }
   cout << endl;
}
