#include <vector>
#include <fstream>
using namespace std;

#include "Tournament.h"

Tournament::Tournament(vector<string> names, string l) {
	total_battles = 0;
	highest_battle = 0;
	logfile = l;
	for (int i = 0; i < names.size(); ++i) {
		string name = names.at(i);
		Player p = Player(name);
		players.push_back(p);
	}
}

vector<Player> Tournament::play() {
	return _play(players, 0, logfile);
}

vector<Player> Tournament::_play(vector<Player> players, int i, string &logfile) {
	if (players.size() == 1) { //base case when vector contains only 1 player, that player is the winner
		return players;
	}
	if (i == players.size()) { //signals the start of a new tournament round
		i = 0;
	}
	Game game = Game(players, i, logfile);
	vector<Player> p = game.play(total_battles, highest_battle); //pass stats as reference
	for (int i = 0; i < p.size() - 1; ++i) { //clear player decks before making a new call
		p.at(i).deck.clear();
	}
	return _play(p, i + 1, logfile);
}
