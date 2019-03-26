#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

#include "VoterDB.h"
#include "VoterMenu.h"

int main(int argc, char *argv[]) {
	int voters = 0;
	string file;
	if (argc == 1) {
		cout << "\nYou must supply a max voters parameter.\n";
		return 0;
	}
	if (argc > 1) {
		istringstream buf(argv[1]);
		buf >> voters;
		if (voters < 1 || voters > 1000) {
			cout << "You must supply a max voters parameter between 1 and 1000.\n";
			return 0;
		}
	}
	if (argc > 2) {
		istringstream buf(argv[2]);
		buf >> file;
	}
	VoterDB voter_database = VoterDB(voters);
	ifstream infile(file);
	if (infile) {
		voter_database.populate(infile);
	}
	
	string choice;
	do {
		cout
		<< "\n\nVoter Information Main Menu: Please select from the following\n"
		<< "Login\n"
		<< "New\n"
		<< "Report\n"
		<< "Save\n"
		<< "Load\n"
		<< "Quit\n";
		choice = user_input();
		
		if (choice == "Quit")
			break;
		else if (choice == "Login") {
			login_menu(voter_database);
		}
		else if (choice == "New") {
			create_new(voter_database);
		}
		else if (choice == "Report") {
			cout << voter_database;
		}
		else if (choice == "Save") {
			save_database(voter_database);
		}
		else if (choice == "Load") {
			load_database(voter_database);
		}
		else {
			cout << "\nInvalid input, please try again.";
			continue;
		}	
	} while (true);
}
