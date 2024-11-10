#include <stdio.h>
/*
Jak działa algorytm?
Dla każdej pozycji w tablicy:
Znajdź najmniejszy element w nieposortowanej części tablicy.
Zamień go z pierwszym elementem tej części.
Powtarzaj, aż cała tablica będzie posortowana.
 */

const int N = 10;

int main(void) {
    int tab[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &tab[i]);
    }
    for (int i = 0; i < N; i++) {
        // czyli teraz szukamy najmniejszego elementu na pozycji i - N-1
        int mini = tab[i];
        int indx = i;
        for (int j = i + 1; j < N; j++) {
            if (tab[j] < mini) {
                mini=tab[j];
                indx = j;
            }
        }
        tab[indx] = tab[i];
        tab[i] = mini;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", tab[i]);
    }
}