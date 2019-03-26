#include <vector>
using namespace std;

#include "Game.h"

class Tournament {
	public:
		Tournament(vector<string> names, string l);
		string logfile;
		vector<Player> play();
		vector<Player> _play(vector<Player> players, int i, string &logfile);
		vector<Player> players;
		int total_battles;
		int highest_battle;
};
