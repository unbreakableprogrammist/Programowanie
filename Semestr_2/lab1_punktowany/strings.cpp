#include<string>
#include<iostream>
using namespace std;

int COMBINE_COUNT =0;
namespace strings{
    string combine_strings(string a,string b){
      COMBINE_COUNT++;
      string result=a+b;
    }

}