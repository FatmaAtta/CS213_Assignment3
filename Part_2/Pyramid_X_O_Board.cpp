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
	if (!is_valid(x, y)) {
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
	char mark = board[x][2-x + y];
	int tmp = y;
	while (is_valid(x, tmp) && board[x][2-x + tmp] == mark)
	{
		actual_count++;
		tmp++;
		if (actual_count == count)
			return true;
	}
	tmp = y-1;
	while (is_valid(x, tmp) && board[x][2-x + tmp] == mark)
	{
		actual_count++;
		tmp--;
		if (actual_count == count)
			return true;
	}
	return false;
}

// Checks if mark occured count times in a row from position x, y vertically
bool Pyramid_X_O_Board::check_vertical(int x, int y, int count) {
	char mark = board[x][2-x + y];
	int actual_count = 0;
	int tmp = x;
	while (is_valid(tmp, y) && board[tmp][2-x + y] == mark)
	{
		actual_count++;
		tmp++;
		if (actual_count == count)
			return true;
	}
	tmp = x-1;
	while (is_valid(tmp, y) && board[tmp][2-x + y] == mark)
	{
		actual_count++;
		tmp--;
		if (actual_count == count)
			return true;
	}
	return false;
}

// Checks if mark occured count times in a row from position x, y right-diagonally
bool Pyramid_X_O_Board::check_rdiag(int x, int y, int count) {
	char mark = board[x][2-x + y];
	int actual_count = 0;
	int tmp = x;
	while (is_valid(tmp, y) && board[tmp][2-tmp + y] == mark)
	{
		actual_count++;
		tmp++;
		if (actual_count == count)
			return true;
	}
	tmp = x-1;
	while (is_valid(tmp, y) && board[tmp][2-tmp + y] == mark)
	{
		actual_count++;
		tmp--;
		if (actual_count == count)
			return true;
	}
	return false;
}

// Checks if mark occured count times in a row from position x, y left-diagonally
bool Pyramid_X_O_Board::check_ldiag(int x, int y, int count) {
	char mark = board[x][2-x + y];
	int actual_count = 0;
	int tmp_x = x;
	int tmp_y = y;
	while (is_valid(tmp_x, tmp_y) && board[tmp_x][2-tmp_x + tmp_y] == mark)
	{
		actual_count++;
		tmp_x++;
		tmp_y += 2;
		if (actual_count == count)
			return true;
	}
	tmp_x = x-1;
	tmp_y = y-2;
	while (is_valid(tmp_x, tmp_y) && board[tmp_x][2-tmp_x + tmp_y] == mark)
	{
		actual_count++;
		tmp_x--;
		tmp_y -= 2;
		if (actual_count == count)
			return true;
	}
	return false;
}


// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Pyramid_X_O_Board::is_winner() {
	/*
	int row_count = 0, col_count;
	for (int i: {0,1,2}) {
		col_count = 0;
		for (int j: {0,1,2,3,4}) {

			if (board[i][j] == '0' || board[i][j] == '?')
		        	continue;
			cout << "Row: " << row_count << "\nCol: " << col_count << endl;
			if (check_horizontal(row_count, col_count, 3) || check_vertical(row_count, col_count, 3) || check_rdiag(row_count, col_count, 3) || check_ldiag(row_count, col_count, 3))
				return true;
			col_count++;
		}
		row_count++;
	}
	*/
	return false;
}


// Return true if 9 moves are done and no winner
bool Pyramid_X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramid_X_O_Board::game_is_over () {
    return n_moves >= 9;
}
