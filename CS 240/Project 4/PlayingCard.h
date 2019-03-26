#include <string>
using namespace std;

class PlayingCard {
	public:
		PlayingCard();
		PlayingCard(int value, string suit);
		bool operator==(const PlayingCard &card);
		bool operator>(const PlayingCard &card);
		bool operator<(const PlayingCard &card);
		friend ostream& operator<<(ostream &os, const PlayingCard &card);
	//private:
		int value;
		string suit;
};


	
