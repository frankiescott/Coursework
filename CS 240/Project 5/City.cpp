#include <string>
#include <iostream>
using namespace std;

#include "City.h"

City::City() {
}

City::City(string name) {
	this->name = name;
}

City::City(string origin, string name, string departure, string arrival, string cost) {
	this->origin = origin;
	this->name = name;
	this->departure = Time(departure);
	this->arrival = Time(arrival);
	this->cost = stoi(cost.substr(1, cost.length()));
}
