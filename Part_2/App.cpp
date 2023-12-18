// File name: App.cpp
// Purpose: Integrated game
// Author(s): Iyad Mahdy
// ID(s): 20220075
// Section: S9
// Date: Dec 18
// Version: 1.0


#include "BoardGame_Classes.hpp"
#include <bits/stdc++.h>
using namespace std;


int main()
{
	Board* b;
	int choice;
	bool chosen = false;
	char computer;
	cout << "Welcome!" << endl;
	cout << "1- X O\n" << "2- Pyramid X O\n" << "3- Connect Four\n" << "4- Five By Five X O\n";
	cout << "Choose a game to play (1, 2, 3, 4): ";

	while (!chosen)
	{
		cin >> choice;
		switch (choice)
		{
			case 1:
				b = new X_O_Board();
				chosen = true;
				break;
			case 2:
				b = new Pyramid_X_O_Board();
				chosen = true;
				break;
			case 3:
				b = new Connect_Four_Board();
				chosen = true;
				break;
			case 4:
				b = new FiveByFive_X_O_Board();
				chosen = true;
				break;
			default:
				cout << "Please Choose Valid Number" << endl;
				chosen = false;
		}
	}

	Player* players[2];

	players[0] = new Player(1, 'X');
	cout << "Play against a computer? (y/n): ";
	cin >> computer;

    if (computer == 'y'){
        players[1] = new RandomPlayer('O', b->get_rows(), b->get_cols());
    }
    else{
        players[1] = new Player(2, 'O');
    }

	GameManager* game = new GameManager(b, players);
	game->run();
}

