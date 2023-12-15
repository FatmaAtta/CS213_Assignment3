// Class definition for XO_RandomPlayer class
// Which is a computer player playing randomly
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <bits/stdc++.h>
#include <ctime>
#include"BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer (char symbol, int dimension_x, int dimension_y):Player(symbol)
{
    this->dimension_x = dimension_x;
    this->dimension_y = dimension_y;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y) {
    srand(time(0));
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension_x);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension_y);
}
