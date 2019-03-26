#include <vector>
using namespace std;

#include "City.h"

class Graph {
	public:
		Graph();
		void populate(ifstream &infile);
		void generate_itinerary(string origin, string destination, string departure, string returntime, int obj);
		vector<City> retrieve_flights(string name);
	private:
		vector<vector<City>> adj_list;
};

