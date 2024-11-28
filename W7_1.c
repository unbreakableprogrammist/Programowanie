#include <stdio.h>
#define WIER 2
#define KOL 3

int main()
{
    // basicowa petla for
    // for(int licznik = 1; licznik <= 20; licznik++)
        // printf("%4d",licznik);
    // for(inicjalizacja; wyrazenie; aktualizacja) wyrazenie moze byc puste


    // tablice 1-wymiarowe
    // deklaracja i w nawiasach liczba elementow
    int potegi[4] ={1,2,4,8};
    float tablica[123]; 
    int potegi2[6] ={1,2,4,8}; // uzupelni miejsca zerami

    // for(int i = 0;i<4;i++)
    //     printf("%d\n", potegi[i]);
    // for(int i = 0;i<6;i++)
    //     printf("%d\n", potegi2[i]);    

    // tablice 2-wymiarowe
    // int WIER = 2;
    // int KOL = 3; // nie zadziala

    int kk[WIER][KOL] = {{1,2,3},{5}};

    for( int i = 0; i< WIER; i++)
    {
        for( int j = 0; j<KOL; j++)
            printf("%d",kk[i][j]);
        printf("\n");
    }

    const int G = 89; // G jest niezmienialne
    printf("%d\n", G);
    const int potegi[4] = {1,2,4,8}; // w przeciwienstwie do define mozemy tworzyc stale tablice
}