COMPILATOR = g++ 
all: program
	./program
test.o : test.cpp
	${COMPILATOR} -c test.cpp -o test.o
program : test.o
	${COMPILATOR} test.o -o program

.PHONY: clean
clean : 
	rm -f *.o program
