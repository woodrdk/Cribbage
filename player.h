#pragma once

#include <iostream>
using namespace std;

class Player
{
private:
	string name;
	int score;
	int crib;

public:
	string toString();
	void setName(string newName);
	string getName();
	void setScore(int score);
	int seeScore();
	
};
