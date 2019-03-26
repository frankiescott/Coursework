all: VoterApp

VoterApp: VoterDB.o Voter.o VoterMenu.o VoterMain.o 
	g++ Voter.o VoterDB.o VoterMenu.o VoterMain.o -o voter.exe
	
VoterMain.o: VoterMain.cpp
	g++ -c VoterMain.cpp

VoterMenu.o: VoterMenu.cpp
	g++ -c VoterMenu.cpp
	
Voter.o: Voter.cpp
	g++ -c Voter.cpp
	
VoterDB.o: VoterDB.cpp
	g++ -c VoterDB.cpp

clean:
	rm -f *.o voter

