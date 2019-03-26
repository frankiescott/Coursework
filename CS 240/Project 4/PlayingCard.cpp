#include <iostream>
#include <string>
using namespace std;

#include "PlayingCard.h"

PlayingCard::PlayingCard() {
}

PlayingCard::PlayingCard(int value, string suit) {
	this->value = value;
	this->suit = suit;
}

ostream& operator<<(ostream &os, const PlayingCard &card) {
	string names[] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
	string output = "(" + names[card.value - 2] + card.suit + ")";
	os << output;
	return os;
}

bool PlayingCard::operator==(const PlayingCard &card) {
	return this->value == card.value;
}

bool PlayingCard::operator>(const PlayingCard &card) {
	return this->value > card.value;
}

bool PlayingCard::operator<(const PlayingCard &card) {
	return this->value < card.value;
}
