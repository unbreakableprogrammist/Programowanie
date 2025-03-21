/*
1. operatorach `new`, `new[]`, `delete`, `delete[]`,

2. referencjach,

3. `private`, `public` w strukturach i klasach,

4. typach `enum class`,  

5. typie `std::byte`,

6. funkcjach `memcpy`, `memmove`,

7. `static_cast`.

*/
#include<iostream>
using namespace std;

enum class owoce{jakblko , pomarancza , sliwka };

int main(){
    owoce owoc = owoce::jakblko;
    int *ptr = new int;   
    int *tab = new int[10];
    *ptr = 10;
    for(int i=0;i<10;i++){
        tab[i]=i*10;
        cout<<tab[i]<<' ';
    }
}



