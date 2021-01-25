#pragma once

#include <iostream>
using namespace std;

class Player
{
private:
	string name;
	int score;
	string crib[4];
	string cards[5];

public:
	string toString();
	void setName(string newName);
	string getName();
	void setScore(int score);
	int seeScore();
	void setCards(string cards[5]);
	void setCrib(string cards[4]);
};
