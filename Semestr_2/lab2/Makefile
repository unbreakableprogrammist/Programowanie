COMPILER = g++


all : main_program
main_program: main_program libhello.so
	$(COMPILER) main_program.o -L. -lhello -o main_program
main_program.o: main_program.cpp
	$(COMPILER) -c main_program.cpp -o main_program.o
hello.o: hello.cpp
	$(COMPILER) -c -fPIC hello.cpp -o hello.o
libhello.so: hello.o
	$(COMPILER) -shared -o libhello.so hello.o

.PHONY : clean
clean :
	rm -rf main_program.o hello.o main_program libhello.so