#include "Player.h"

class Game {
	public:
		int v;
		Game(vector<Player> p, int i, string &l);
		vector<Player> play(int &total_battles, int &highest_battle);
		void battle(int a, int &total_battles);
		void war(int &total_battles);
	private:
		string logfile;
		vector<Player> players;
		Player playerone;
		Player playertwo;
		int battles;
		int wars;
		PlayingCard p1_card;
		PlayingCard p2_card;
		LLC<PlayingCard> deck;
};
