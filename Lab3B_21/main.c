#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // for usleep

#define M 21 // number of rows
#define N 21 // number of columns
#define OPOZNIENIE 40000 // 40ms in microseconds

// ANSI escape codes for terminal text colors
void setCzerwony() { printf("\033[1;31m"); }   // Red
void setZielony() { printf("\033[1;32m"); }   // Green
void setNiebieski() { printf("\033[1;34m"); } // Blue
void setZolty() { printf("\033[1;33m"); }     // Yellow
void setFioletowy() { printf("\033[1;35m"); } // Purple
void setTurkusowy() { printf("\033[1;36m"); } // Cyan
void setSzary() { printf("\033[1;30m"); }     // Gray
void setBialy() { printf("\033[1;37m"); }     // White
void setDomyslny() { printf("\033[0m"); }     // Reset to default

void wypelnijTablice(int tab[M][N], int m, int n, int value);
void ustawKolumne(int tab[M][N], int m, int n, int col, int value);
void wypiszTablice(int tab[M][N], int m, int n);
void choinka(int tab[M][N], int m, int n, int drzewko[][2]);
void prostokat(int tab[M][N], int m, int n, int index);
void trojkatPrawy(int tab[M][N], int m, int n, int index);
void trojkatDolny(int tab[M][N], int m, int n, int index);
void transpozycja(int tab[M][N], int m, int n);
void przejscie(int[][N], int ilosc_w, int ilosc_k, void(int[][N], int, int, int));

int main()
{
    /* fill in missing variables */

    int drzewko[][2] = { {0,1},{1,3},{2,7},{3,3},{4,7},{5,11},{6,15},{7,3},{8,7},{9,11},{10,15},
                         {11,19},{12,3},{13,7},{14,11},{15,15},{16,19},{17,21},{18,5},{19,5},{20,5} };

    int tab[M][N];

    /********************ETAP 0*******************/
    // Change text color
    setZolty();
    printf("Kolor czcionki zolty\n");
    setDomyslny();
    printf("Kolor domyslny...\n\n\n");
    system("clear"); // Clear terminal on macOS and Linux

    /********************ETAP 1*******************/

    wypelnijTablice(tab, M, N, 1);
    ustawKolumne(tab, M, N, 4, 0);
    wypiszTablice(tab, M, N);
    system("clear");
    printf("\n\n");

    /********************ETAP 2*******************/

    wypelnijTablice(tab, M, N, 1);
    choinka(tab, M, N, drzewko);
    wypiszTablice(tab, M, N);
    system("clear");
    printf("\n\n");

    /********************ETAP 3*******************/

    wypelnijTablice(tab, M, N, 1);
    prostokat(tab, M, N, 0);
    wypiszTablice(tab, M, N);
    system("clear");
    printf("\n\n");

    przejscie(tab, M, N, prostokat);
    system("clear");
    printf("\n\n");

    /********************ETAP 4*******************/

    wypelnijTablice(tab, M, N, 1);
    trojkatPrawy(tab, M, N, 0);
    wypiszTablice(tab, M, N);
    system("clear");
    printf("\n");
    przejscie(tab, M, N, trojkatPrawy);
    printf("\n");
    system("clear");

    /********************ETAP 5*******************/

    wypelnijTablice(tab, M, N, 1);
    trojkatDolny(tab, M, N, 0);
    wypiszTablice(tab, M, N);
    printf("\n");
    system("clear");
    przejscie(tab, M, N, trojkatDolny);
    printf("\n");
    system("clear");

    return 0;
}


void przejscie(int t[][N], int ilosc_w, int ilosc_k, void funkcja(int t[][N], int w, int k, int a))
{
    int i;
    for (i = 0; i < ilosc_w / 2 + 1; i++)
    {
        printf("\n");
        system("clear");
        wypelnijTablice(t, ilosc_w, ilosc_k, 1);
        funkcja(t, ilosc_w, ilosc_k, i);
        wypiszTablice(t, ilosc_w, ilosc_k);
        usleep(OPOZNIENIE); // Pause for OPOZNIENIE microseconds
    }
    for (i = ilosc_w / 2 - 1; i > -1; i--)
    {
        printf("\n");
        system("clear");
        wypelnijTablice(t, ilosc_w, ilosc_k, 1);
        funkcja(t, ilosc_w, ilosc_k, i);
        wypiszTablice(t, ilosc_w, ilosc_k);
        usleep(OPOZNIENIE);
    }
}

// Implement missing functions here
void wypelnijTablice(int tab[M][N], int m, int n, int value) {
    int i,j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            tab[i][j] = value;
        }
    }

    return;
}

void ustawKolumne(int tab[M][N], int m, int n, int col, int value) {
    int i;

    for (i = 0; i < N; i++) {
        tab[i][col] = value;
    }

    return;
}

void wypiszTablice(int tab[M][N], int m, int n) {
    int i, j;


    for (i = 0; i < m; i++) {
        printf("\n");
        for(j = 0; j < n; j++) {
            if (tab[i][j] == 0) {
                setCzerwony();
            } else {
                setDomyslny();
            }
            printf("%d", tab[i][j]);
        }
    }

    return;
}

void choinka(int tab[M][N], int m, int n, int drzewko[][2]) {
    int i,j;

    for (i = 0; i < m; i++) {
        for (j = ((n-1)/2) - ((drzewko[i][1]-1)/2);j <= ((n-1)/2) + ((drzewko[i][1]-1)/2); j++) {
            tab[i][j] = 0;
        }
    }

    return;
}

void prostokat(int tab[M][N], int m, int n, int index) {
    int i,j;

    for (i = index, j = index; j < n-index; j++) {
        tab[i][j] = 0;
    }
    for (i = index, j = index; i < m-index; i++) {
        tab[i][j] = 0;
    }
    for (i = m-index-1, j = index; j < n-index; j++) {
        tab[i][j] = 0;
    }
    for (i = index, j = n-index-1; i < m-index; i++) {
        tab[i][j] = 0;
    }

    return;
}

void trojkatPrawy(int tab[M][N], int m, int n, int index) {
    int i,j;

    for (j = n-index-1; j >= (n-1)/2; j--) {
        for (i = index; i < m-index; i++) {
            tab[i][j] = 0;
        }
        index += 1;
    }

    return;
}

void trojkatDolny(int tab[M][N], int m, int n, int index) {
    trojkatPrawy(tab, m, n, index);

    transpozycja(tab, m ,n);

    return;
}

void transpozycja(int tab[M][N], int m, int n) {
    int i, j, temp;

    for (j = 0; j < n; j++) {
        for (i = j+1; i < m; i++) {
            temp = tab[i][j];
            tab[i][j] = tab[j][i];
            tab[j][i] = temp;
        }
    }

    return;
}



