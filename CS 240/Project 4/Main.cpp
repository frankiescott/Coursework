#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "Tournament.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	string infile;
	string logfile;
	if (argc > 0) {
		istringstream buf(argv[1]);
		buf >> infile;
	}
	if (argc > 1) {
		istringstream buf(argv[2]);
		buf >> logfile;
	}

	ifstream ifile(infile);
	string input;
	vector<string> names;
	while (ifile >> input) {
		names.push_back(input);
	}
	ifile.close();
	
	int size = names.size();
	if ((size & (size - 1) != 0) || size < 2 || size > 64) {
		cout << "\nInvalid input file. Number of participants must be a power of 2 between 2 and 64!\n";
		return 0;
	}
	
	ofstream ofs;
	ofs.open(logfile, ofstream::out | ofstream::trunc); //program appends to file, make sure file is cleared first
	ofs.close();
	
	Tournament t = Tournament(names, logfile);
	vector<Player> winner = t.play();
	
	cout << "\nThe winner is " << winner.at(0).name << "!\n";
	cout << "Highest battle: " << t.highest_battle << "\n";
	cout << "Total battles: " << t.total_battles << "\n";
	cout << "Average battles among " << (size - 1) << " matches: " << t.total_battles / (size - 1) << "\n"; //8 person tournament has 7 matches, 16 person tournament has 15 matches, etc
}
