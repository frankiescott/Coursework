#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#include "Voter.h"

Voter::Voter() {
}

Voter::Voter(string last_name, string first_name, string userid, string password, string age, string street_number, string street_name, string town, string zip, string donated) {
	//first convert certain values from strings
	int new_age = stoi(age);
	int new_street_number = stoi(street_number);
	float new_donated = stof(donated);
	
	this->last_name = last_name;
	this->first_name = first_name;
	this->userid = userid;
	this->password = password;
	this->age = new_age;
	this->street_number = new_street_number;
	this->street_name = street_name;
	this->town = town;
	this->zip = zip;
	this->donated = new_donated;
}

//getter functions
string Voter::get_userid() { return this->userid; }
string Voter::get_password() { return this->password; }
string Voter::get_last_name() { return this->last_name; }
string Voter::get_first_name() { return this->first_name; }
int Voter::get_age() { return this->age; }
int Voter::get_street_number() { return this->street_number; }
string Voter::get_street_name() { return this->street_name; }
string Voter::get_town() { return this->town; }
string Voter::get_zip() { return this->zip; }
float Voter::get_donation_amount() { return this->donated; }

//setter functions
void Voter::change_password(string new_password) { this->password = new_password; }
void Voter::donate(float amount) { this->donated += amount; }
void Voter::set_last_name(string last_name) { this->last_name = last_name; }
void Voter::set_first_name(string first_name) { this->first_name = first_name; }
void Voter::set_age(int age) { this->age = age; }
void Voter::set_street_number(int street_number) { this->street_number = street_number; }
void Voter::set_street_name(string street_name) { this->street_name = street_name; }
void Voter::set_town(string town) { this->town = town; }
void Voter::set_zip(string zip) { this->zip = zip; }

//print operators
string Voter::info_line() {
	stringstream donate;
	donate << fixed << setprecision(2) << this->donated;
	return this->last_name + "," + this->first_name + "," + this->userid + "," + this->password + "," + to_string(this->age) + "," + to_string(this->street_number) + "," + this->street_name + "," + this->town + "," + this->zip + "," + donate.str() + "\n";
}

ostream& operator<<(ostream& os, const Voter& v) {
	os 
	<< "Name: " << v.first_name << " " << v.last_name << "\n"
	<< "Age: " << v.age << "\n"
	<< "Address: " << v.street_number << " " << v.street_name << ", " << v.town << " " << v.zip << "\n"
	<< "Amount Donated: $" << fixed << setprecision(2) << v.donated << "\n";
}

	
