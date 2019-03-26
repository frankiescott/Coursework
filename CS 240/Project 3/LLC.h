#include <string>
using namespace std;

struct Node {
	string data;
	Node* next;
};
		
class LLC {
	public:
		LLC();
		LLC(const LLC &source);
		~LLC();
		bool insert(const string &s);
		void head(int n);
		friend ostream& operator<<(ostream &os, const LLC &list);
		int len();
		bool contains(const string &s);
		string tail();
		bool remove(const string &s);
		bool join(LLC other);
		LLC& operator+=(const int &n);
		LLC& operator=(const LLC &source);
		LLC operator+(const LLC &rightlist);
		void shuffle();
	private:
		Node *first;
		Node *last;
		int size;
};
