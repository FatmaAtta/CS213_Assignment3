#include "BoardGame_Classes.hpp"

Pyramid_X_O_Board::Pyramid_X_O_Board() {
	n_rows = 3;
	n_cols = 5;
	board = new char*[n_rows];
	for (int i = 0; i < n_rows; i++) {
		board[i] = new char[n_cols];
		for (int j = 0; j < n_cols; j++)
			board[i][j] = 0;
	}
}

void Pyramid_X_O_Board::display_board() {

}
