#include <stdio.h>
#include <stdbool.h>
// syntax definiowania stałych:
#define Pi 3.14
#define square(a) (a*a)

int main()
{
    // wyrazenie a instrukcja: "x=5" to wyrazenie, instrukcja to np: "x = 5;"
    printf("1234g\n");
    printf("square 7: %d\n", square(7));
    printf("pi to: %f\n", Pi);

    int a = 7;
    int b = 8;
    int z;
    z = (a>b) ? a : b; // syntax krotki warunkowy
    printf("z jest rowne: %d\n", z);


    // prosty while:

    bool i = true;
    int x = 10;
    while(i){
        printf("%d\n", x);
        --x;
        if(x == 0){
            i = false;
        }
    }

    // prosty for

    for(int p = 0; p<10; ++p){
        printf("p to: %d\n", p);
    }

    /*
    Operatory:
        arytmetyczne: (+,-,*,/,%) normalnie
        logiczne: (||, &&, !)
        relacyjne: (<,>,<=,>=,==,!=)
        bitowe:
            ~a - negacja wszystkich bitow
            a & b - koniunkcja bitowa
            a | b - alternatywa bitowa
            a ^ b - XOR (0 i 0 lub 1 i 1)
            a << b - przesuniecie bita w lewo o b
            a >> b - przesuniecie bita w prawo o a
        przypisania:
            a=b
            a+=b
            a-=b
            a*=b
            a/=b
            a%=b
            a&=b
            a|=b
            a^=b
            a<<=b
            a>>=b
        pozostale:
            ++a
            --a
            a++
            a--

            a[b]
            *a
            &a
            a->b
            a.b

            a(...)
            a, b
            (type) a
            ? :
            sizeof(...)
    
    */
}