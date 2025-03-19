#include<iostream>
#include "vars.hpp"
using namespace std;

int main(){
    print_vars();
    inc_vars();
    print_vars();
    cout<<"global_extern : " << global_extern ;
    return 0;
}