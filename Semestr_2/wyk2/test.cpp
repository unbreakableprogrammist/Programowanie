/*
1. operatorach `new`, `new[]`, `delete`, `delete[]`,

2. referencjach,

4. typach `enum class`,  

5. typie `std::byte`,

6. funkcjach `memcpy`, `memmove`,

7. `static_cast`.

*/
#include<iostream>
#include<iomanip>
#include <cstddef> // bytes
using namespace std;

enum class owoce{jablko , pomarancza , sliwka };

int main(){
    owoce owoc = owoce::jablko;
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
    std::byte* bytes= reinterpret_cast<std::byte*>(&x);
    for (size_t i = 0; i < sizeof(x); ++i) {
        std::cout << "Byte " << i << ": "
                  << "0x" << std::hex << setw(2) << std::setfill('0')
                  << static_cast<int>(bytes[i]) << "\n";
    }

}



