#include <stdio.h>

int main(){
    // formatowanie printf: printf("opcjonalny tekst %[flaga][szerokosc][.precyzja]specyfikator opcjonalny tekst", arg1, arg2...)
    int wrt = 7;
    char znk = 'x';
    int wrt2 = -9;
    printf("wartosc = %d, znak=%c\n", wrt,znk);
    printf("wartosc = %8d\n", wrt);
    printf("wartosc = %.8d\n", wrt);
    printf("wartosc = %-d\n", wrt); // wyrownanie do lewej
    printf("wartosc = %+d\n", wrt); // dana liczbowa ma byc poprzedzona znakiem
    printf("wartosc = %+d\n", wrt2);
    printf("%#06x\n",81); // x-hex, 6-6 miejsc, 0-poprzedz zeramie, nie spacjami, #- poprzedz 0x
}