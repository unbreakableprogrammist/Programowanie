#include<iostream>
#include<string>
static int HELLO_COUNT =0 ;

namespace HELLO{
    void print(std::string name){
        HELLO_COUNT++;
        std::cout<<HELLO_COUNT<<". Hello "<<name<<"\n";
    }
}

