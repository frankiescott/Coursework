all: War

War: Main.o LLC.o PlayingCard.o Player.o Game.o Tournament.o
	g++ Main.o LLC.o PlayingCard.o Player.o Game.o Tournament.o -o war.exe
	
Main.o: Main.cpp
	g++ -c Main.cpp

LLC.o: LLC.cpp
	g++ -c LLC.cpp
	
PlayingCard.o: PlayingCard.cpp
	g++ -c PlayingCard.cpp

Player.o: Player.cpp
	g++ -c Player.cpp
	
Game.o: Game.cpp
	g++ -c Game.cpp

Tournament.o: Tournament.cpp
	g++ -c Tournament.cpp
	
clean:
	rm -f *.o war.exe
