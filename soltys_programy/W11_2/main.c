#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 11
#define N 100

enum podstawaSystemu {bin, dec, hex};

struct dane {
    int wartosc;
    char hex[M];
    char dec[M];
    char bin[3*M];
};

void konwertuj(struct dane tablica[N]);
void sortuj(struct dane tablica[N], enum podstawaSystemu);
void num2bin(int wartosc, char buf[3*M]);
void num2dec(int wartosc, char buf[M]);
void num2hex(int wartosc, char buf[M]);

int main(int argc, char* argv[]) {
    int i;
    struct dane tablica[N];
    for (i = 0; i < N; i++)
        tablica[i].wartosc = i;
    konwertuj(tablica);
    sortuj(tablica, dec);
    for(i=0;i<N;i++) {
        printf("%s ", tablica[i].dec);
    }
    printf("\n");
    sortuj(tablica, hex);
    for(i=0;i<N;i++) {
        printf("%s ", tablica[i].hex);
    }
    printf("\n");
    sortuj(tablica, bin);
    for(i=0;i<N;i++) {
        printf("%s ", tablica[i].bin);
    }
    printf("\n");
    return 0;
}

void konwertuj(struct dane tablica[N]) {
    int i;
    for (i=0; i<N; i++) {
        num2hex(tablica[i].wartosc, tablica[i].hex);
        num2dec(tablica[i].wartosc, tablica[i].dec);
        num2bin(tablica[i].wartosc, tablica[i].bin);
    }
}

void num2dec(int wartosc, char buf[M]) {
    char pom[M];
    int i=0, j;

    while(0!=wartosc) {
        pom[i] = '0' + wartosc % 10;
        wartosc/=10;
        i++;
    }

    if (!i) {
        pom[i] ='0';
        i++;
    }

    for (j=0, i--; 0<=i; j++,i--) {
        buf[j] = pom[i];
    }

    buf[j] = 0;
    return;
}

void num2hex(int wartosc, char buf[M]) {
    char pom[M];
    int i=0, j;

    while(0!=wartosc) {
        j = wartosc - ((wartosc>>4)<<4);
        pom[i] = (10>j) ? ('0'+j) : ('A'+(j-10));
        wartosc >>= 4;
        i++;
    }

    if (!i) {
        pom[i] = '0';
        i++;
    }

    for (j=0, i--; 0<=i; j++,i--) {
        buf[j] = pom[i];
    }

    buf[j] = 0;
    return;
}

void num2bin(int wartosc, char buf[M]) {
    char pom[3*M];
    int i=0, j;

    while(0!=wartosc) {
        pom[i] = '0' + (wartosc - ((wartosc>>1)<<1));
        wartosc >>= 1;
        i++;
    }

    if (!i) {
        pom[i] = '0';
        i++;
    }

    for (j=0, i--; 0<=i; j++,i--) {
        buf[j] = pom[i];
    }

    buf[j] = 0;
    return;
}

void sortuj(struct dane tablica[N], enum podstawaSystemu ps) {
    int i, j, zmien;
    char buf[sizeof(struct dane)];

    for (i=N-1; 1<i; i--) {
        for (j=0; j<i; j++) {
            switch (ps) {
                case bin:
                    zmien = strcmp(tablica[j].bin, tablica[j+1].bin);
                    break;
                case dec:
                    zmien = strcmp(tablica[j].dec, tablica[j+1].dec);
                    break;
                case hex:
                    zmien = strcmp(tablica[j].hex, tablica[j+1].hex);
                    break;
            }
            if (0<zmien) {
                memcpy((void*)buf,(void*)&tablica[j],sizeof(tablica[j]));
                memcpy((void*)&tablica[j],(void*)&tablica[j+1],sizeof(tablica[j]));
                memcpy((void*)&tablica[j+1],(void*)buf,sizeof(tablica[j]));
            }
        }
    }
    return;
}