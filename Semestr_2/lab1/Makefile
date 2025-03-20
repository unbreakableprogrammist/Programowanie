COMPILATOR = g++ 

all : program1
program1 : program1.o vars.o
	${COMPILATOR} program1.o vars.o -o program1
program1.o : program_1.cpp
	${COMPILATOR} -c program_1.cpp -o program1.o
vars.o : vars.cpp 
	${COMPILATOR} -c vars.cpp -o vars.o

.PHONY: clean
clean : 
	rm -f program1.o vars.o program1
