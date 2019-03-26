all: FlightApp

FlightApp: main.o City.o Time.o Graph.o
	g++ main.o City.o Time.o Graph.o -o Flight.exe
	
main.o: main.cpp
	g++ -c main.cpp

City.o: City.cpp
	g++ -c City.cpp
	
Time.o: Time.cpp
	g++ -c Time.cpp
	
Graph.o: Graph.cpp
	g++ -c Graph.cpp
	
clean:
	rm -f *.o Flight.exe

