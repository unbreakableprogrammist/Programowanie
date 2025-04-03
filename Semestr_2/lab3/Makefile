CXX=g++


.PHONY: all clean

all: program
	./program
program: main.o 
	$(CXX) main.o -o main

main.o: main.cpp SongDuration.hpp
	$(CXX) -c main.cpp -o main.o

clean:
	rm -f *.o main