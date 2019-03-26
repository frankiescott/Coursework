#include <iostream>
#include <string>
using namespace std;

#include "Time.h"

Time::Time() {
}

Time::Time(string time) {
	string hr = time.substr(0, 2);
	string min = time.substr(3, 5);
	string ampm = time.substr(5, 7);
	
	this->hour = stoi(hr);
	this->minute = stoi(min);
	this->ampm = ampm;
	
	if (ampm == "am" && this->hour == 12) {
		this->hour = 0;
	}
	else if (ampm == "pm" && this->hour != 12) {
		this->hour += 12; //convert to 24hr time
	}
}

int Time::minutes() {
	return (this->hour * 60) + this->minute;
}

int Time::greater(Time t) {
	if (this->minutes() > t.minutes()) {
		return 1;
	}
	else if (this->minutes() < t.minutes()) {
		return -1;
	}
	else {
		return 0; //equal
	}
}

ostream& operator<<(ostream &os, const Time &time) {
	string hr;
	if (time.ampm == "pm" && time.hour != 12) {
		hr = to_string(time.hour - 12); //convert back to 12h time
	}
	else if (time.ampm == "am" && time.hour == 0) {
		hr = "12";
	}
	else {
		hr = to_string(time.hour);
	}
	string min;
	if (time.minute < 10) {
		min = "0" + to_string(time.minute);
	}
	else {
		min = to_string(time.minute);
	}
	string output = hr + ":" + min + time.ampm;
	os << output;
	return os;
}
