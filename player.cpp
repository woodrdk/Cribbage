#include "Player.h"


#include<sstream>

// tostring methos using a stringstream
string Player::toString() {
	stringstream ss;
	ss << "Name: ";
	ss << name;
	ss << "Score: ";
	ss << score;
	ss << "crib: ";
	ss << crib;

	return ss.str();
}

// setter to set Name
void Player::setName(string newName) {
	name = newName;
}

// getter to get Name
string Player::getName() {
	return name;
}



void Player::setScore(int score) {
	score = score;
}

int Player::seeScore() {
	return score;
}
