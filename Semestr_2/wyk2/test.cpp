/*
1. operatorach `new`, `new[]`, `delete`, `delete[]`,

2. referencjach,

4. typach `enum class`,  

5. typie `std::byte`,

6. funkcjach `memcpy`, `memmove`,

7. `static_cast`.

*/
#include<iostream>
#include <cstddef> // bytes
using namespace std;

enum class owoce{jakblko , pomarancza , sliwka };

int main(){
    owoce owoc = owoce::jakblko;
    int *ptr = new int;   
    int *tab = new int[10];
    *ptr = 10;
    for(int i=0;i<10;i++){
        tab[i]=i*10;
        //cout<<tab[i]<<' ';
    }

    delete ptr;
    delete[] tab;
    int p= 1030;
    int& pref = p;
    cout<<pref;

    int x = 1234;
    byte* bytes= reinterpret_cast<byte*>(&x);
    

}



