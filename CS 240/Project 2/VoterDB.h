#include "Voter.h"

class VoterDB {
	public:
		VoterDB();
		VoterDB(int v);
		void populate(ifstream &infile);
		int user_exists(string userid);
		Voter& get_voter(int i);
		float sum_donations() const;
		bool is_full();
		void add_user(string last_name, string first_name, string userid, string password, string age, string street_number, string street_name, string town, string zip);
		void save(ofstream &outfile);
		friend ostream& operator<<(ostream& os, const VoterDB& db);
	private:
		Voter* voters;
		int max_size;
		int size;
};
