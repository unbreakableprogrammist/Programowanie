#include "hello.hpp"
using namespace std;

int main(){
      //*zeby uruchomic ten program najpierw trzeba wykonac polecenie : make , nastepnie g++ -c main_program.cpp -o main_program.o , a nastepnie jeszcze raz wywolac make i na koncu dac linijke  LD_LIBRARY_PATH=. ./main_program"


    HELLO::print("Darius");
    HELLO::print("Xerxes");
    HELLO::print("Ataxerxes");
    return 0;
}