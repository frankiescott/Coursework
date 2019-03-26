class Voter {
	public:
		Voter();
		Voter(string last_name, string first_name, string userid, string password, string age, string street_number, string street_name, string town, string zip, string donated);
		string get_userid();
		string get_password();
		string get_last_name();
		string get_first_name();
		int get_age();
		int get_street_number();
		string get_street_name();
		string get_town();
		string get_zip();
		string info_line();
		void set_last_name(string last_name);
		void set_first_name(string first_name);
		void set_age(int age);
		void set_street_number(int street_number);
		void set_street_name(string street_name);
		void set_town(string town);
		void set_zip(string zip); 
		float get_donation_amount();
		void change_password(string new_password);
		string view();
		void donate(float amount);
		friend ostream& operator<<(ostream& os, const Voter& v);
	private:
		string last_name;
		string first_name;
		string userid;
		string password;
		int age;
		int street_number;
		string street_name;
		string town;
		string zip;
		float donated;
};
