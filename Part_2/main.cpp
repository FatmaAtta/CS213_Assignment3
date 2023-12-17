#include "BoardGame_Classes.hpp"
#include <bits/stdc++.h>
using namespace std;


int main()
{
	Pyramid_X_O_Board* pb = new Pyramid_X_O_Board();
	Connect_Four_Board* cfb = new Connect_Four_Board();
	FiveByFive_X_O_Board* fbf = new FiveByFive_X_O_Board();

	Player* players[] = {new Player(1, 'X'), new Player(2, 'O')};
	GameManager* game = new GameManager(fbf, players);

	game->run();
}
