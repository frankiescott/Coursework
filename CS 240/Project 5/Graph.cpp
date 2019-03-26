#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "Graph.h"

Graph::Graph() {
	vector<vector<City>> adj_list;
}

void Graph::populate(ifstream &infile) {
	for (string line; getline(infile, line);) {
		stringstream ss(line);
		string data [5]; //flight info has 5 pieces of data
		string value;
		for (int i = 0; ss >> value; ++i) {
			data[i] = value;
		}

		int found = -1; //assume the city has not been found
		for (int i = 0; i < adj_list.size(); ++i) {
			if (adj_list.at(i).at(0).name == data[0]) { //if found
				found = i; //save index
			}
		}
		if (found != -1) { //if it WAS found, it's a new edge. place the edge at index 'found'
			City c = City(data[0], data[1], data[2], data[3], data[4]);
			adj_list.at(found).push_back(c);
		}
		else { //if it WASNT found, we create a new spot on the adj list
			vector<City> v;
			City c = City(data[0]);
			City c2 = City(data[0], data[1], data[2], data[3], data[4]);
			v.push_back(c);
			v.push_back(c2);
			adj_list.push_back(v);
		}
	}
	infile.close();
	
	for (int i = 0; i < adj_list.size(); ++i) {
		for (int j = 0; j < adj_list.at(i).size(); ++j) {
			cout << adj_list.at(i).at(j).name << " ";
		}
		cout << endl;
	}
}

vector<City> Graph::retrieve_flights(string name) {
	for (int i = 0; i < adj_list.size(); ++i) {
		if (adj_list.at(i).at(0).name == name) {
			return adj_list.at(i);
		}
	}
	vector<City> v;
	return v; //return empty vector
}

void Graph::generate_itinerary(string origin, string destination, string departure, string returntime, int obj) {
	vector<City> origin_flights = retrieve_flights(origin);
	vector<City> return_flights = retrieve_flights(destination);
	if (origin_flights.size() == 0) {
		cout << "No flights from that city were found.";
		return;
	}
	vector<City> departure_path;
	vector<City> return_path;
	Time depart = Time(departure);
	Time returnt = Time(returntime);
	if (obj == 1 || obj == 3) { //any itinerary or cheapest flight
		for (int i = 1; i < origin_flights.size(); ++i) {
			City city = origin_flights.at(i);
			if (city.name != destination) { //check if city matches desired destination
				continue;
			}
			if (depart.greater(city.departure) == -1) { //does the user want to leave later than this flight departs?
				continue;
			}
			departure_path.push_back(origin_flights.at(i));
		}
		for (int i = 1; i < return_flights.size(); ++i) {
			City city = return_flights.at(i);
			if (city.name != origin) { //check if return city matches the city the user left from
				continue;
			}
			if (returnt.greater(city.arrival) == -1) { //desired return time is less than the arrival of the flight
				continue;
			}
			return_path.push_back(return_flights.at(i));
		}
	}
	else if (obj == 2) { //earliest arrival
		for (int i = 1; i < origin_flights.size(); ++i) {
			City city = origin_flights.at(i);
			if (city.name != destination) { //check if city matches desired destination
				continue;
			}
			if (depart.greater(city.departure) == -1) { //does the user want to leave later than this flight departs?
				continue;
			}
			if (departure_path.size() == 0) { //if the departure path is empty, add the first valid flight
				departure_path.push_back(origin_flights.at(i));
			}
			else { //if it's not empty, we have to check if there's an earlier arrival
				if (city.arrival.greater(departure_path.at(0).arrival) == -1) { //found an earlier flight
					departure_path.erase(departure_path.begin());
					departure_path.push_back(origin_flights.at(i)); //replace it
				}
			}
		}
		for (int i = 1; i < return_flights.size(); ++i) {
			City city = return_flights.at(i);
			if (city.name != origin) { //check if return city matches the city the user left from
				continue;
			}
			if (returnt.greater(city.arrival) == -1) { //desired return time is less than the arrival of the flight
				continue;
			}
			return_path.push_back(return_flights.at(i));
		}
	}
	if (obj == 3) { //displays cheapest flight only
		cout << "\nBelow lists every possible flight combination under the provided constraints\n\n";
		stringstream ss;
		int lowest_cost = 999999999;
		for (int i = 0; i < return_path.size(); ++i) {
			for (int j = 0; j < departure_path.size(); ++j) {
				int cost = departure_path.at(j).cost + return_path.at(i).cost;
				if (cost < lowest_cost) {
					lowest_cost = cost;
					ss.str(string());
					ss.clear();
					ss << "(DEPARTURE FLIGHT) Depart: " << origin_flights.at(0).name << " " << departure_path.at(j).departure << " Arrive: " << departure_path.at(j).name << " " << departure_path.at(j).arrival << " (RETURN FLIGHT) Depart: " << return_flights.at(0).name << " " << return_path.at(i).departure << " Arrive: " << origin_flights.at(0).name << " " << return_path.at(i).arrival << " (TOTAL COST) $" << cost << endl;
				}
			}
		}
		cout << ss.str();
	}
	else { //displays the generated itinerary
		cout << "\nBelow lists every possible flight combination under the provided constraints\n\n";
		for (int i = 0; i < return_path.size(); ++i) {
			for (int j = 0; j < departure_path.size(); ++j) {
				int cost = departure_path.at(j).cost + return_path.at(i).cost;
				cout << "(DEPARTURE FLIGHT) Depart: " << origin_flights.at(0).name << " " << departure_path.at(j).departure << " Arrive: " << departure_path.at(j).name << " " << departure_path.at(j).arrival << " (RETURN FLIGHT) Depart: " << return_flights.at(0).name << " " << return_path.at(i).departure << " Arrive: " << origin_flights.at(0).name << " " << return_path.at(i).arrival << " (TOTAL COST) $" << cost << endl;
			}
		}
	}
	
	if (departure_path.size() == 0) {
		cout << "No valid itinerary exists with the constraints provided.\n";
	}
}
