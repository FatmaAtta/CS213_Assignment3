#include "BoardGame_Classes.hpp"
#include <bits/stdc++.h>
using namespace std;


int main()
{
	Pyramid_X_O_Board* pb = new Pyramid_X_O_Board();
	Player* players[] = {new Player(1, 'X'), new Player(2, 'O')};
	GameManager* game = new GameManager(pb, players);

	game->run();
}
