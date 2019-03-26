#include <string>
using namespace std;

#include "Time.h"

class City {
	public:
		City();
		City(string name);
		City(string origin, string name, string departure, string arrival, string cost);
		string origin;
		string name;
		int cost;
		Time departure;
		Time arrival;
};
