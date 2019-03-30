#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>
using namespace std;

int ** lcs_table(string x, string y, int m, int n) {
	int ** t = new int*[m];
	for (int i = 0; i < m; ++i) {
		t[i] = new int[n];
	}

	for (int i = 0; i < n; ++i) {
		t[0][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		t[i][0] = 0;
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (x[i] == y[j]) {
				t[i][j] = 1 + t[i - 1][j - 1];
			}
			else if (t[i - 1][j] >= t[i][j - 1]) {
				t[i][j] = t[i - 1][j];
			}
			else {
				t[i][j] = t[i][j - 1];
			}
		}
	}
	return t;
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
	
	x = " " + x;
	y = " " + y;
	int i = x.length();
	int j = y.length();

	hrc::time_point t1 = hrc::now();
	int **t = lcs_table(x, y, i, j);
	hrc::time_point t2 = hrc::now();
	auto elapsed = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

	ofstream out;
	out.open(output);

	if (i <= 10 && j <= 10) {
		for (int a = 0; a < i; ++a) {
			for (int b = 0; b < j; ++b) {
				out << t[a][b] << " ";
			}
			out << "\n";
		} 
	}
	int length = t[i-1][j-1];
	out << "Length of LCS:\t" << length << "\nRunning time:\t" << elapsed << " microseconds";
	return 0;
}

