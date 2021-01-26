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

void Player::setCards(string setCards[5]) {
	
	//cards = setCards; // assign to player cards
}

// make getCards

void Player::setCrib(string cribCards[4]) {
	for (int i = 0; i < 4; i++) {
		crib[i] = cribCards[i];
    //	cout << crib[i] << " " << endl;
	}
}

void Player::seeCrib() {
	for (int i = 0; i < 4; i++) {
		cout << crib[i] << " | " << flush;
	}
	cout << endl;
}

void Player::setScore(int score) {
	score = score;
}

int Player::seeScore() {
	return score;
}
