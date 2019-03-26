class Time {
	public:
		Time();
		Time(string time);
		int greater(Time t);
		int minutes();
		int hour;
		int minute;
		string ampm;
		friend ostream& operator<<(ostream &os, const Time &time);

};
