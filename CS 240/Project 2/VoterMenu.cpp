#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

#include "VoterDB.h"

string user_input() {
	string i;
	cin >> i;
	return i;
}

void update(Voter &voter) {
	string last, first, street_name, town, zip;
	int age, street_number;
	
	cout << voter; //display current information
	cout << "\nEnter each value you would like to change or return to skip to the next entry.\n";
	cin.ignore();
	cout << "Last name: ";
	if (cin.peek() != '\n') {
		cin >> last;
		voter.set_last_name(last);
	}
	cin.ignore();
	cout << "First name: ";
	if (cin.peek() != '\n') {
		cin >> first;
		voter.set_first_name(first);
	}
	cin.ignore();
	cout << "Age: ";
	if (cin.peek() != '\n') {
		cin >> age;
		voter.set_age(age);
	}
	cin.ignore();
	cout << "Street number: ";
	if (cin.peek() != '\n') {
		cin >> street_number;
		voter.set_street_number(street_number);
	}
	cin.ignore();
	cout << "Street name: ";
	if (cin.peek() != '\n') {
		cin >> street_name;
		voter.set_street_name(street_name);
	}
	cin.ignore();
	cout << "Town: ";
	if (cin.peek() != '\n') {
		cin >> town;
		voter.set_town(town);
	}
	cin.ignore();
	cout << "Zip: ";
	if (cin.peek() != '\n') {
		cin >> zip;
		voter.set_zip(zip);
	}
	cin.ignore();
}

void change_password(Voter &voter) {
	cout << "\nEnter your current password: ";
	string input = user_input();
	if (input == voter.get_password()) {
		cout << "\nEnter a new password: ";
		string new_password = user_input();
		cout << "\nVerify your new password: ";
		string new_password2 = user_input();
		if (new_password != new_password2) {
			cout << "\nPassword was not changed.";
		}
		else {
			cout << "\nPassword change successful.";
			voter.change_password(new_password);
		}
	}
	else {
		cout << "Invalid password.";
	}
}

float get_donation() {
	float donation;
	while (cout << "\nEnter a donation amount ($0 - $2700): ") {
		cin >> donation;
		if (donation < 0 || donation > 2700) {
			cout << "\nInvalid donation amount.";
			continue;
		}
		break;
	}
	return donation;
}	
	
void inner_menu(Voter &voter) {
	do {
		cout
		<< "\n\nVoter Information User Menu: Please select from the following\n"
		<< "Update\n"
		<< "Password\n"
		<< "View\n"
		<< "Donate\n"
		<< "Report\n"
		<< "Logout\n";
		string choice = user_input();
				
		if (choice == "Logout")
			break;
		else if (choice == "Update") {
			update(voter);
		}
		else if (choice == "Password") {
			change_password(voter);
		}
		else if (choice == "View") {
			cout << voter;
		}
		else if (choice == "Donate") {
			float donation = get_donation();
			voter.donate(donation);
		}
		else if (choice == "Report") {
			cout << voter.get_last_name() << ": $" << voter.get_donation_amount();
		}
	} while (true);
}

void login_menu(VoterDB &voter_database) {
	cout << "\nEnter your userid: ";
	string user = user_input();
	int i = voter_database.user_exists(user); //will return index of the user
	if (i == -1) {
		cout << "\nInvalid userid.";
	}
	else {
		//grab address of the voter and verify password
		Voter& voter = voter_database.get_voter(i);
		cout << "Enter your password: ";
		string input = user_input();
		if (input == voter.get_password()) {
			cout << "\nLogin successful.";
			inner_menu(voter); //pass address into inner menu
		}
		else {
			cout << "\nInvalid password.";
		}
	}
}

void create_new(VoterDB &voter_database) {
	if (voter_database.is_full()) {
		cout << "Voter database is full.";
	}
	else {
		while (cout << "\nEnter a userid: ") {
			string userid = user_input();
			if (voter_database.user_exists(userid) != -1) {
				cout << "That username is taken.";
				continue;
			}
			else {
				cout << "\nCreating new user.";
				cout << "\nEnter a password: ";
				string password = user_input();
				cout << "Enter your last name: ";
				string last_name = user_input();
				cout << "Enter your first name: ";
				string first_name = user_input();
				cout << "Enter your age: ";
				string age = user_input();
				cout << "Enter your street number: ";
				string street_number = user_input();
				cout << "Enter your street name: ";
				string street_name = user_input();
				cout << "Enter your town: ";
				string town = user_input();
				cout << "Enter your zip code: ";
				string zip = user_input();
				voter_database.add_user(last_name, first_name, userid, password, age, street_number, street_name, town, zip);
				break;
			}
		}
	}
}

void save_database(VoterDB &voter_database) {
	cout << "\nEnter the name (without extension) of the file you would like to save to: ";
	string file = user_input() + ".csv";
	ofstream outfile(file);
	if (outfile) {
		cout << "A file with that name already exists. Overwrite? (y/n): ";
		char ch;
		cin >> ch;
		if (ch == 'y') {
			cout << "Saving file..";
			voter_database.save(outfile);
		}
	}
}

void load_database(VoterDB &voter_database) {
	cout << "\nEnter the name (without extension) of the file you would like to load: ";
	string file = user_input() + ".csv";
	ifstream infile(file);
	if (!infile) {
		cout << "A file with that name does not exist.";
	}
	else {
		cout << "Loading file..";
		voter_database.populate(infile);
	}
}
