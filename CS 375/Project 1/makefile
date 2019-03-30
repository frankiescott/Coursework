all: program1 program2 program3

program1: program1.o 
	g++ program1.o -o program1
	
program1.o: program1.cpp
	g++ -c program1.cpp
	
program2: program2.o 
	g++ program2.o -o program2
	
program2.o: program2.cpp
	g++ -c program2.cpp

program3: program3.o 
	g++ program3.o -o program3
	
program3.o: program3.cpp
	g++ -c program3.cpp

clean:
	rm -f *.o program1
	rm -f *.o program2
	rm -f *.o program3

run: p1 p2 p3
p1:
	./program1 filex.txt filey.txt output1.txt
p2:
	./program2 filex.txt filey.txt output2.txt
p3:
	./program3 filex.txt filey.txt output3.txt
