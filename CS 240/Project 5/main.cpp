#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

#include "Graph.h"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "\nYou must supply an input file.\n";
		return 0;
	}
	string file;
	Graph schedule = Graph();
	if (argc > 1) {
		istringstream buf(argv[1]);
		buf >> file;
	}
	ifstream infile(file);
	if (infile) {
		schedule.populate(infile);
	}
	
	string origin, destination, departure, returntime;
	int obj;
	
	cout << "\nSelect your itinerary objective\n1. Any itinerary\n2. Earliest arrival\n3. Cheapest flight\n:";
	cin >> obj;
	cout << "Provide the following trip constraints on a single line separated by spaces\n";
	cout << "[Departure city] [Destination city] [Departure time] [Return time for the next day]\n:";
	cin >> origin >> destination >> departure >> returntime;

	schedule.generate_itinerary(origin, destination, departure, returntime, obj);
}
