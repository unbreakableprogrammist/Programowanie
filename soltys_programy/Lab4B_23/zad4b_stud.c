#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WYM 2
#define ILE_RESTAURACJI 6
#define TYMCZASOWE_ILE_RESTAURACJI 4
#define MAX_OPINII 10
#define DLUGOSC_OPISU 50
#define PROG 4


enum budzet { tanio = 0, umiarkowanie = 1, drogo = 2 };

struct recenzja {
    char opis[DLUGOSC_OPISU];
    int gwiazdki;
};
struct restauracja {
    float wspolrzedne[WYM];
    char* nazwa;
    int ile_opinii;
    struct recenzja* opinie_klientow;
    enum budzet b;
};
typedef struct recenzja recenzja;
typedef struct restauracja restauracja;


restauracja* inicjuj(int ile);
void wypisz_restauracje(restauracja* tab, int ile);
void znajdz_najdalsza(float w[WYM], restauracja* szukane, int ile);
void sprzataj(restauracja* tab, int ile);
void sortuj_recenzje(restauracja* tab, int ile);
void usun_negatywne_recenzje(restauracja* tab, int ile, int prog);

int main(int argc, const char * argv[]) {
    float w1[] = { 52.215049, 21.097538 };
    float w2[] = { 52.23049, 21.01532 };
    /*Etap 1 2pkt*/
    restauracja* spis_restauracji = NULL;
    spis_restauracji = inicjuj(TYMCZASOWE_ILE_RESTAURACJI);
    //wypisz_restauracje(spis_restauracji, TYMCZASOWE_ILE_RESTAURACJI);
    //sprzataj(spis_restauracji, TYMCZASOWE_ILE_RESTAURACJI);
    //spis_restauracji = inicjuj(ILE_RESTAURACJI);
    //wypisz_restauracje(spis_restauracji, ILE_RESTAURACJI);
    
    /*Etap 2 1pkt*/
    //printf("Szukanie najdalszej restauracji:\n");
    //znajdz_najdalsza(w1, spis_restauracji, ILE_RESTAURACJI);
    //znajdz_najdalsza(w2, spis_restauracji, ILE_RESTAURACJI);
    
    /*Etap 3 2pkt*/
    //printf("Po usunieciu negatywnych recenzji:\n");
    //usun_negatywne_recenzje(spis_restauracji, ILE_RESTAURACJI, PROG);
    //wypisz_restauracje(spis_restauracji, ILE_RESTAURACJI);
    
    /*Etap 4 2pkt*/
    //printf("Po posortowaniu recenzji:\n");
    //sortuj_recenzje(spis_restauracji, ILE_RESTAURACJI);
    //wypisz_restauracje(spis_restauracji, ILE_RESTAURACJI);
   
    //sprzataj(spis_restauracji, ILE_RESTAURACJI);
    system("PAUSE");
    return 0;
}


restauracja* inicjuj(int ile)
{
    char* wejscie_recenzja_opis[] = { "Smaczne", "OK","Brudno","Mila obsluga","Stare ziemniaki","Nie ok", "Za drogo","wszystko fajnie","super","opinia negatywna" };
    char* wejscie_nazwa[MAX_OPINII] = { "Smaki ludowe","Kuchnia fusion","Tanie sushi","Bar mleczny","Szybki kes","Slow food" };
    enum budzet wejscie_budzet[] = { tanio,tanio,umiarkowanie,drogo,umiarkowanie,tanio };
    float wejscie_wspolrzedne[][WYM] = { { 52.237049, 21.017532 },{ 52.237049, 21.087538 },{ 52.215049, 21.087538 },{ 52.215049, 21.037538 },{ 52.215049, 21.097538 },{ 52.215449, 21.073530 } };
    //kontynuuj od tego miejsca nie usuwajac powyzszych deklaracji
    //uwaga: aktualnie w funkcji brakuje "return"
}

