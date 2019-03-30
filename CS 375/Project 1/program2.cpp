#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>
using namespace std;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
	return 0;
}

int lcs(string x, string y, int i, int j) {
	if (i == 0 || j == 0) {
		return 0;
	}
	if (x[i-1] == y[j-1]) {
		return lcs(x, y, i-1, j-1) + 1;
	}
	else {
		return max( lcs(x, y, i, j-1), lcs(x, y, i-1, j) );
	}
}

using hrc = chrono::high_resolution_clock;
int main(int argc, char *argv[]) { 
	string filex, filey, output;
	if (argc > 1) {
		istringstream buf(argv[1]);
		buf >> filex;
	}
	if (argc > 2) {
		istringstream buf(argv[2]);
		buf >> filey;
	}
	if (argc > 3) {
		istringstream buf(argv[3]);
		buf >> output;
	}

	ifstream infilex(filex);
	ifstream infiley(filey);
	string x, y;
	for (string line; getline(infilex, line);) {
		stringstream ss(line);
		ss >> x;
	}
	for (string line; getline(infiley, line);) {
		stringstream ss(line);
		ss >> y;
	}
	
	int i = x.length();
	int j = y.length();

	hrc::time_point t1 = hrc::now();
	int length = lcs(x, y, i, j);
	hrc::time_point t2 = hrc::now();
	auto elapsed = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	
	ofstream out;
	out.open(output);
	out << "Length of LCS:\t" << length << "\nRunning time:\t" << elapsed << " microseconds";

	return 0;
}

