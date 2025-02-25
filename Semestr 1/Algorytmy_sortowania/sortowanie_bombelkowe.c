#include <stdio.h>

/*
argc to jest to liczba argumentów przekazanych do programu z terminala.
argv to tablica wskaźników (czyli tablica ciągów znaków) czyli to co się pisze w terminalu.
np dla ./program costam1 costam 2 to
argcc = 3
argv to wskazniki wskazujace na kolejne miejsca w termianlu
int main(int argc ,const char* argv[]) {  <-- tak chce zebysmy pisali na zajecuach i wtedy tablica to argv[1]
*/

const int N = 10;


int main(void) {
    int tab[N];
    for (int i = 0; i < N; i++) {   // wczytanie liczb po ludzku
        scanf("%d", &tab[i]);
        //printf("%d\n", tab[i]);
    }
    // sortowanie bombelkowe to że porównujemy następne 2 elementy tak że " przepychamy w każdym przejsciu najwiekszy element na koniec

    for(int i = 0; i < N; i++) {
        bool czy_jakas_zmaiana = false ; // ta zmienna mowi czy zamienilismy jakies 2 liczby w przejsciu petli , jesli nie to znaczy ze mamy posortowany ciag
        for(int j = 1; j < N-i; j++) {  // teraz taki trik że nie sprawdzamy do przedostatniego elementu
            if(tab[j-1] > tab[j]) {
                int temp =tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = temp;
                czy_jakas_zmaiana = true;
            }
        }
        if(!czy_jakas_zmaiana) {
            break;
        }
    }
    for(int i = 0; i < N; i++) {
        printf("%d ", tab[i]);
    }
    return 0;
}
