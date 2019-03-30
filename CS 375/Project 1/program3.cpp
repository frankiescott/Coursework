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

int sub_problem(int ** t, string x, string y, int i, int j) {
	if (x[i] == '\0' || y[j] == '\0') {
		return 0;
	}
	if (t[i][j] != -1) {
		return t[i][j];
	}
	else if (x[i] == y[j]) {
		t[i][j] = 1 + sub_problem(t, x, y, i+1, j+1);
	}
	else {	
		int a = sub_problem(t, x, y, i+1, j);
		int b = sub_problem(t, x, y, i, j+1);
		t[i][j] = max(a, b);
	}
	return t[i][j];
}

int lcs_length(string x, string y, int m, int n) {
	int ** t = new int*[m];
	for (int i = 0; i < m; ++i) {
		t[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			t[i][j] = -1;
		}
	}
	return sub_problem(t, x, y, 0, 0);
}

using hrc = chrono::high_resolution_clock;
int main(int argc, char *argv[]) { 
	string filex, filey, output;
	string x, y;
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
	int t = lcs_length(x, y, i, j);
	hrc::time_point t2 = hrc::now();
	auto elapsed = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

	ofstream out;
	out.open(output);

	out << "Length of LCS:\t" << t << "\nRunning time:\t" << elapsed << " microseconds";
	return 0;
}

