#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

#include "VoterDB.h"

VoterDB::VoterDB() {
}

VoterDB::VoterDB(int v) {
	this->max_size = v;
	this->size = 0;
	this->voters = new Voter[v];
}

//getter functions
Voter& VoterDB::get_voter(int i) { return this->voters[i]; }
bool VoterDB::is_full() { return this->size == this->max_size; }

void VoterDB::populate(ifstream &infile) {
	this->size = 0; //reset size in case we're loading a new database
	int x = 0;
	for (string line; getline(infile, line);) {
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		
		string data [10]; //voter information has 10 data pieces
		string value;
		for (int i = 0; ss >> value; ++i) {
			data[i] = value;
			cout << value;
		}
		this->voters[x] = Voter(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9]);
		this->size++;
		x++;
		if (x == this->max_size) {
			//if number of entries in database exceeds user supplied max value
			break;
		}
	}
	infile.close();
}

void VoterDB::save(ofstream &outfile) {
	for (int i = 0; i < this->size; ++i) {
		outfile << this->voters[i].info_line();
	}
	outfile.close();
}

void VoterDB::add_user(string last_name, string first_name, string userid, string password, string age, string street_number, string street_name, string town, string zip) {
	this->voters[size] = Voter(last_name, first_name, userid, password, age, street_number, street_name, town, zip, "0");
	//if size is 5, the last voter is in index 4, so add it to 5
	this->size++;
}

int VoterDB::user_exists(string userid) {
	for (int i = 0; i < this->size; ++i) {
		if (this->voters[i].get_userid() == userid)
			//return index of the voter
			return i;
	}
	return -1; //sentinel value if not found
}

float VoterDB::sum_donations() const {
	float total = 0;
	for (int i = 0; i < this->size; ++i) {
		total += this->voters[i].get_donation_amount();
	}
	return total;
}

ostream& operator<<(ostream& os, const VoterDB& db) {
	float donations = db.sum_donations();
	os 
	<< db.size << " voters in the database with a donation total of $" << fixed << setprecision(2) << donations;
}


