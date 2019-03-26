#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h> 
using namespace std;

#include "Game.h"

//constructor creates the deck, shuffles, and deals to the two players
Game::Game(vector<Player> p, int i, string &l) {
	logfile = l;
	v = i;
	players = p;
	playerone = players.at(i);
	playertwo = players.at(i+1);

	ofstream fout;
	fout.open(logfile, ios::app);
	fout << "===\n";
	fout << playerone.name << " vs. " << playertwo.name << "\n";
	fout.close();
	
	wars = 0;
	battles = 0;
	
	//create deck of cards
	string suits[] = {"S", "C", "D", "H"};
	PlayingCard card;
	for (int i = 0; i < 4; ++i) {
		for (int j = 2; j < 15; ++j) {
			card = PlayingCard(j, suits[i]);
			deck.insert(card);
		}
	}
	
	int loop = rand() % 100 + 5000;
	//try to get a good shuffle with awful psuedo random shuffle
	for (int i = 0; i < loop; ++i) {
		deck.shuffle();
	}
	
	//deal cards
	int flip = 0;
	for (int i = 0; i < 52; ++i) {
		if (flip == 0) {
			flip = 1;
			playerone.deck.insert(deck.pop());
		}
		else if (flip == 1) {
			flip = 0;
			playertwo.deck.insert(deck.pop());
		}
	}
}

void Game::war(int &total_battles) {
	wars++;
	for (int i = 0; i < 3; ++i) {
		if (playerone.deck.len() == 1) { //we want to insert at most 3 cards but leave 1 card to battle with
			break;
		}
		deck.insert(playerone.deck.pop());
	}
	for (int i = 0; i < 3; ++i) {
		if (playertwo.deck.len() == 1) {
			break;
		}
		deck.insert(playertwo.deck.pop());
	}
	//after each player puts down 3 (or less) cards, we just call another battle
	battle(1, total_battles); //we need a flag to let the battle function know we're in a war
}

void Game::battle(int a, int &total_battles) {
	if (a == 0) { //if we're not in a war
		battles++;
		total_battles++;
	}
	
	ofstream fout;
	fout.open(logfile, ios::app);
	
	p1_card = playerone.deck.peek(); //for comparison
	p2_card = playertwo.deck.peek();
	deck.insert(playerone.deck.pop()); //hold cards in middle
	deck.insert(playertwo.deck.pop());

	if (p1_card == p2_card) {
		if (playerone.deck.len() != 0 && playertwo.deck.len() != 0) {
			war(total_battles);
		}
	}
	else if (p1_card > p2_card) { //if player one's card is bigger
		int len = deck.len();
		deck.shuffle();
		for (int i = 0; i < len; ++i) {
			playerone.deck.insert(deck.pop()); //take cards from middle to add to p1's pile
		}
		if (a == 0) {
			fout << "\tBattle " << battles << ": " << playerone.name << " " << p1_card << " defeated " << playertwo.name << " " << p2_card << ": " << playerone.name << " " << playerone.deck.len() << ", " << playertwo.name << " " << playertwo.deck.len() << endl;
		}
		else {
			fout << "\tWar " << wars << ": " << playerone.name << " " << p1_card << " defeated " << playertwo.name << " " << p2_card << ": " << playerone.name << " " << playerone.deck.len() << ", " << playertwo.name << " "<< playertwo.deck.len() << endl;
		}
	}
	else { //player two won
		int len = deck.len();
		deck.shuffle();
		for (int i = 0; i < len; ++i) {
			playertwo.deck.insert(deck.pop());
		}
		if (a == 0) {
			fout << "\tBattle " << battles << ": " << playertwo.name << " " << p2_card << " defeated " << playerone.name << " " << p1_card << ": " << playerone.name << " " << playerone.deck.len() << ", " << playertwo.name << " " << playertwo.deck.len() << endl;
		}
		else {
			fout << "\tWar " << wars << ": " << playertwo.name << " " << p2_card << " defeated " << playerone.name << " " << p1_card << ": " << playerone.name << " " << playerone.deck.len() << ", " << playertwo.name << " " << playertwo.deck.len() << endl;
		}
	}
	fout.close();
}

vector<Player> Game::play(int &total_battles, int &highest_battle) {
	ofstream fout;
	fout.open(logfile, ios::app);

	while (true) { //while there is no winner
		battle(0, total_battles);
		if (battles > highest_battle) {
			highest_battle = battles;
		}
		
		if (battles == 1000) { //max 1000 battles
			if (playerone.deck.len() > playertwo.deck.len()) {
				players.at(v).wins++;
				fout << playerone.name << " (" << players.at(v).wins << ") DEFEATED " << playertwo.name << " in " << battles << " battles and " << wars << " wars.\n";
				players.erase(players.begin() + (v + 1));
				return players;
			}
			else if (playertwo.deck.len() > playerone.deck.len()) {
				players.at(v + 1).wins++;
				fout << playertwo.name << " (" << players.at(v + 1).wins << ") DEFEATED " << playerone.name << " in " << battles << " battles and " << wars << " wars.\n";
				players.erase(players.begin() + v);
				return players;
			}
			else { //lengths equal, flip coin
				int randnum = rand() % 2;
				if (randnum == 0) {
					players.at(v).wins++;
					fout << playerone.name << " (" << players.at(v).wins << ") DEFEATED " << playertwo.name << " in " << battles << " battles and " << wars << " wars.\n";
					players.erase(players.begin() + (v + 1));
					return players;
				}
				else {
					players.at(v + 1).wins++;
					fout << playertwo.name << " (" << players.at(v + 1).wins << ") DEFEATED " << playerone.name << " in " << battles << " battles and " << wars << " wars.\n";
					players.erase(players.begin() + v);
					return players;
				}
			}
		}
		if (playertwo.deck.len() == 0) {
			players.at(v).wins++;
			fout << playerone.name << " (" << players.at(v).wins << ") DEFEATED " << playertwo.name << " in " << battles << " battles and " << wars << " wars.\n";
			players.erase(players.begin() + (v + 1));
			return players;
		}
		else if (playerone.deck.len() == 0) {
			players.at(v + 1).wins++;
			fout << playertwo.name << " (" << players.at(v + 1).wins << ") DEFEATED " << playerone.name << " in " << battles << " battles and " << wars << " wars.\n";
			players.erase(players.begin() + v);
			return players;
		}
		else {
			continue;
		}
	}
	fout.close();
}

