#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
Pyramid_X_O_Board::Pyramid_X_O_Board () {
   n_rows = 3;
   n_cols = 5;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++) {
		if (j >= n_cols/2 - i && j <= n_cols/2 + i)
			board[i][j] = '?';
		else
			board[i][j] = '0';
	}
   }
}

// Display the board and the pieces on it
void Pyramid_X_O_Board::display_board() {
	system("clear");
	int row_count = 0, col_count;
	for (int i: {0,1,2}) {
		cout << "\n";
		col_count = 0;
		for (int j: {0,1,2,3,4}) {
			if (board[i][j] == '0')
				cout << '\t';
			else
			{
				if (board[i][j] == '?')
			        	cout << "| (" << row_count << "," << col_count << ") ";
				else
			        	cout << "| " << "  " << board[i][j] << "   ";
				if (board[i][j + 1] == '0')
					cout << '|';
				col_count++;
			}
	        }
		row_count++;
		if (i == 2)
			cout << '|';
	        cout << "\n-----------------------------------------";
	}
	cout << endl;
}

// Checks validity of the coordinate x,y in the board
bool Pyramid_X_O_Board::is_valid(int x, int y) {
	if (x < 0 || x > 2|| y < 0 || y > 2 * x)
		return false;
	return true;
}

// To update position x, y on the board to mark
bool Pyramid_X_O_Board::update_board (int x, int y, char mark){
	// Return false if position is out of bounds of shown choices
	if (!is_valid(x, y) || board[x][2-x + y] != '?') {
		cout << "Invalid Position!\n";
		return false;
	}
	// Row will always be x but column will have to scale with the shown array by using (2)
	// which is the maximum row number and subtracting the x from it then adding the shown
	// column number to get the actual index in the board array

	board[x][2-x + y] = mark;
	n_moves++;
	return true;
}

// Checks if mark occured count times in a row from position x, y horizontally
bool Pyramid_X_O_Board::check_horizontal(int x, int y, int count) {
	int actual_count = 0;
	char mark = board[x][y];
	int tmp = y;
	while (board[x][tmp] == mark)
	{
		actual_count++;
		tmp++;
		if (actual_count == count)
			return true;
		if (tmp >= n_cols)
			break;
		
	}
	if (y == 0)
		return false;
	tmp = y-1;
	while (board[x][tmp] == mark)
	{
		actual_count++;
		tmp--;
		if (actual_count == count)
			return true;
		if (tmp < 0)
			break;
		
	}
	return false;
}

// Checks if mark occured count times in a row from position x, y vertically
bool Pyramid_X_O_Board::check_vertical(int x, int y, int count) {
	char mark = board[x][y];
	int actual_count = 0;
	int tmp = x;
	while (board[tmp][y] == mark)
	{
		actual_count++;
		tmp++;
		if (actual_count == count)
			return true;
		if (tmp >= n_rows)
			break;
		
	}
	if (x == 0)
		return false;
	tmp = x-1;
	while (board[tmp][y] == mark)
	{
		actual_count++;
		tmp--;
		if (actual_count == count)
			return true;
		if (tmp < 0)
			break;
		
	}
	return false;
}

// Checks if mark occured count times in a row from position x, y right-diagonally
bool Pyramid_X_O_Board::check_rdiag(int x, int y, int count) {
	char mark = board[x][y];
	int actual_count = 0;
	int tmp_x = x;
	int tmp_y = y;
	while (board[tmp_x][tmp_y] == mark)
	{
		actual_count++;
		tmp_x--;
		tmp_y++;
		if (actual_count == count)
			return true;
		if (tmp_x < 0 || tmp_y >= n_cols)
			break;
	}
	if (x == n_rows - 1|| y == 0)
		return false;
	tmp_x = x+1;
	tmp_y = y-1;
	while (board[tmp_x][tmp_y] == mark)
	{
		actual_count++;
		tmp_x++;
		tmp_y--;
		if (actual_count == count)
			return true;
		if (tmp_x >= n_rows || tmp_y < 0)
			break;
	}
	return false;
}

// Checks if mark occured count times in a row from position x, y left-diagonally
bool Pyramid_X_O_Board::check_ldiag(int x, int y, int count) {
	char mark = board[x][y];
	int actual_count = 0;
	int tmp_x = x;
	int tmp_y = y;
	while (board[tmp_x][tmp_y] == mark)
	{
		actual_count++;
		tmp_x++;
		tmp_y++;
		if (actual_count == count)
			return true;
		if (tmp_x >= n_rows || tmp_y >= n_cols)
			break;
		
	}
	if (x == 0 || y == 0)
		return false;
	tmp_x = x-1;
	tmp_y = y-1;
	while (board[tmp_x][tmp_y] == mark)
	{
		actual_count++;
		tmp_x--;
		tmp_y--;
		if (actual_count == count)
			return true;
		if (tmp_x < 0 || tmp_y < 0)
			break;
	}
	return false;
}


// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Pyramid_X_O_Board::is_winner() {
	for (int i: {0,1,2}) {
		for (int j: {0,1,2,3,4}) {
			if (board[i][j] == '0' || board[i][j] == '?')
		        	continue;
			if (check_horizontal(i, j, 3) || check_vertical(i, j, 3) || check_rdiag(i, j, 3) || check_ldiag(i, j, 3))
				return true;
		}
	}
	return false;
}


// Return true if 9 moves are done and no winner
bool Pyramid_X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramid_X_O_Board::game_is_over () {
    return n_moves >= 9;
}
