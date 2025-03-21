/*
1. operatorach `new`, `new[]`, `delete`, `delete[]`, ok

2. referencjach, ok

4. typach `enum class`,   ok

5. typie `std::byte`, ok 

6. funkcjach `memcpy`, `memmove`,  

7. `static_cast`.

*/
#include<iostream>
#include<iomanip>
#include <cstddef> // bytes
#include <cstring> // memcpy, memmove
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
    //cout<<pref;

    int x = 1234;
    std::byte* bytes= reinterpret_cast<std::byte*>(&x);
    for (size_t i = 0; i < sizeof(x); ++i) {
        cout << "Byte in decimal " << i << ": "<<static_cast<int>(bytes[i]) << "\n";
        //std::cout << "Byte " << i << ": "<< "0x" << std::hex << setw(2) << std::setfill('0')<< static_cast<int>(bytes[i]) << "\n";   
    }
    char src[] = "Hello, world!";
    char dest[50];

    memcpy(dest, src, strlen(src) + 1);  // Kopiuje tekst, w tym znak '\0'

    std::cout << "Copied string: " << dest << std::endl;
    char str2[] = "Hello, world!";

    // Zmieniamy tekst w miejscu
    memmove(str2 + 6, str2, 5);  // Kopiujemy pierwsze 5 znaków na pozycję 6

    std::cout << "Moved string: " << str2 << std::endl;

}



