#include <iostream>
using namespace std;

int global_extern =0;
static int global_static =0;

void inc_vars(){
    global_extern++;
    global_static++;
}

void print_vars(){
    cout<<"global extern "<<global_extern<<endl;
    cout<<"global static "<<global_static;
}