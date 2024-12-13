#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define WYM 2
#define ILE_RESTAURACJI 6
#define TYMCZASOWE_ILE_RESTAURACJI 4
#define MAX_OPINII 10
#define DLUGOSC_OPISU 50
#define PROG 4

enum budzet {tanio = 0, umiarkowanie = 1, drogo = 2};

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
void wypisz_recenzje(recenzja* tab, int ile);
void znajdz_najdalsza(float w[WYM], restauracja* szukane, int ile);
void sprzataj(restauracja* tab, int ile);
void sortuj_recenzje(restauracja* tab, int ile);
void usun_negatywne_recenzje(restauracja* tab, int ile, int prog);

int main(int argc, const char * argv[]) {
    float w1[] = { 52.215049, 21.097538 };
    float w2[] = { 52.23049, 21.01532 };

    /*Etap 1 2pkt*/
    restauracja* spis_restauracji = NULL;
    //spis_restauracji = inicjuj(TYMCZASOWE_ILE_RESTAURACJI);
    //wypisz_restauracje(spis_restauracji, TYMCZASOWE_ILE_RESTAURACJI);
    //sprzataj(spis_restauracji, TYMCZASOWE_ILE_RESTAURACJI);

    spis_restauracji = inicjuj(ILE_RESTAURACJI);
    wypisz_restauracje(spis_restauracji, ILE_RESTAURACJI);

    /*Etap 2 1pkt*/
    printf("\nSzukanie najdalszej restauracji:\n");
    znajdz_najdalsza(w1, spis_restauracji, ILE_RESTAURACJI);
    znajdz_najdalsza(w2, spis_restauracji, ILE_RESTAURACJI);

    /*Etap 3 2pkt*/
    printf("\nPo usunieciu negatywnych recenzji:\n");
    usun_negatywne_recenzje(spis_restauracji, ILE_RESTAURACJI, PROG);
    wypisz_restauracje(spis_restauracji, ILE_RESTAURACJI);

    /*Etap 4 2pkt*/
    printf("\nPo posortowaniu recenzji:\n");
    sortuj_recenzje(spis_restauracji, ILE_RESTAURACJI);
    wypisz_restauracje(spis_restauracji, ILE_RESTAURACJI);

    sprzataj(spis_restauracji, ILE_RESTAURACJI);

    return 0;
}

restauracja* inicjuj(int ile) {
    char* wejscie_recenzja_opis[] = { "Smaczne", "OK","Brudno","Mila obsluga","Stare ziemniaki","Nie ok", "Za drogo","wszystko fajnie","super","opinia negatywna" };
    char* wejscie_nazwa[MAX_OPINII] = { "Smaki ludowe","Kuchnia fusion","Tanie sushi","Bar mleczny","Szybki kes","Slow food" };
    enum budzet wejscie_budzet[] = { tanio,tanio,umiarkowanie,drogo,umiarkowanie,tanio };
    float wejscie_wspolrzedne[][WYM] = { { 52.237049, 21.017532 },{ 52.237049, 21.087538 },{ 52.215049, 21.087538 },{ 52.215049, 21.037538 },{ 52.215049, 21.097538 },{ 52.215449, 21.073530 } };
    //kontynuuj od tego miejsca nie usuwajac powyzszych deklaracji
    //uwaga: aktualnie w funkcji brakuje "return"

    int i, j;
    restauracja* tab = (restauracja*)malloc(ile*sizeof(restauracja));

    srand((unsigned)time(NULL));

    for (i = 0; i < ile; i++) {
        tab[i].wspolrzedne[0] = wejscie_wspolrzedne[i][0];
        tab[i].wspolrzedne[1] = wejscie_wspolrzedne[i][1];

        tab[i].nazwa = (char*)malloc((strlen(wejscie_nazwa[i]) + 1) * sizeof(char));
        strcpy(tab[i].nazwa, wejscie_nazwa[i]);

        tab[i].ile_opinii = 1 + rand() % (MAX_OPINII-1); // losowanie od 1 do 9
        tab[i].opinie_klientow = (recenzja*)malloc(tab[i].ile_opinii * sizeof(recenzja));

        for (j = 0; j < tab[i].ile_opinii; j++) {
            strcpy(tab[i].opinie_klientow[j].opis, wejscie_recenzja_opis[rand() % (MAX_OPINII)]);
            tab[i].opinie_klientow[j].gwiazdki = 1 + rand() % (5); // losowanie od 1 do 5
        }

        tab[i].b = wejscie_budzet[i];
    }

    return tab;
}

void wypisz_restauracje(restauracja* tab, int ile) {
    int i;
    char* polka_cenowa[3] = {"tania", "umiarkowana", "droga"};

    for (i = 0; i < ile; i++) {
        printf("\nRestauracja o nazwie %s, polozona w (%f, %f), polka cenowa: %s\n", tab[i].nazwa, tab[i].wspolrzedne[0], tab[i].wspolrzedne[1], polka_cenowa[tab[i].b]);
        wypisz_recenzje(tab[i].opinie_klientow, tab[i].ile_opinii);
    }

    return;
}

void wypisz_recenzje(recenzja* tab, int ile) {
    int i;

    for (i = 0; i < ile; i++) {
        printf("Recenzja nr %d: %s, gwiazdki: %d\n", i+1, tab[i].opis, tab[i].gwiazdki);
    }

    return;
}

void sprzataj(restauracja* tab, int ile) {
    int i;

    for (i = 0; i < ile; i++) {
        free(tab[i].nazwa);
        free(tab[i].opinie_klientow);
    }

    free(tab);

    return;
}

void znajdz_najdalsza(float w[WYM], restauracja* szukane, int ile) {
    int i, indeks = 0;

    float odleglosc = sqrt(pow((w[0] - szukane[0].wspolrzedne[0]), 2) + pow((w[1] - szukane[0].wspolrzedne[1]), 2));

    for (i = 1; i < ile; i++) {
        if (sqrt(pow((w[0] - szukane[i].wspolrzedne[0]), 2) + pow((w[1] - szukane[i].wspolrzedne[1]), 2)) > odleglosc) {
            odleglosc = sqrt(pow((w[0] - szukane[i].wspolrzedne[0]), 2) + pow((w[1] - szukane[i].wspolrzedne[1]), 2));
            indeks = i;
        }
    }

    printf("Najdalsza restauracja odlegla o %f stopni to %s\n", odleglosc, szukane[indeks].nazwa);

    return;
}

void usun_negatywne_recenzje(restauracja* tab, int ile, int prog) {
    int i, j, k;

    for (i = 0; i < ile; i++) {
        for (j = 0; j < tab[i].ile_opinii; j++) {
            if (tab[i].opinie_klientow[j].gwiazdki < prog) {

                for (k = j; k < tab[i].ile_opinii-1; k++) {
                    memcpy(&tab[i].opinie_klientow[k], &tab[i].opinie_klientow[k+1], sizeof(recenzja));
                }

                j--;
                tab[i].ile_opinii--;
            }
        }

        tab[i].opinie_klientow = (recenzja*)realloc(tab[i].opinie_klientow, (tab[i].ile_opinii)*sizeof(recenzja));
    }

    return;
}

void sortuj_recenzje(restauracja* tab, int ile) {
    int i, j, k, temp;

    for (i = 0; i < ile; i++) {
        for (j = 0; j < tab[i].ile_opinii; j++) {
            for (k = 0; k < tab[i].ile_opinii-j-1; k++) {
                if (tab[i].opinie_klientow[k].gwiazdki > tab[i].opinie_klientow[k+1].gwiazdki) {
                    temp = tab[i].opinie_klientow[k].gwiazdki;
                    tab[i].opinie_klientow[k].gwiazdki = tab[i].opinie_klientow[k+1].gwiazdki;
                    tab[i].opinie_klientow[k+1].gwiazdki = temp;
                }
            }
        }
    }

    return;
}