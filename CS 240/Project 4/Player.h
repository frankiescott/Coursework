#include <string>
using namespace std;

#include "LLC.cpp"
#include "PlayingCard.h"

class Player {
	public:
		Player();
		Player(string n);
		LLC<PlayingCard> deck;
		string name;
		int wins;
};

