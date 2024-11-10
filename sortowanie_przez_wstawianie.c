#include <stdio.h>

const int N = 10;

// tu pewnie na lekcji warto bedzie dac to int main(int argc,const char* argv )

// sortowanie przez wstawianie , to algorytm ze idziemy po kolei od 2 elementu i ewentualnie przesuwamy w lewo dopoki jest wiekszy od elementow na lewo


int main(void) {
    int tab[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &tab[i]);
    }
    /*
     teraz jak to dziala :  idziemy forem od 2 elementu i ustawiamy sobie j na poprzedni element , pozniej robimy przepychanie
     tzn , jesli element z lewej jest wiekszy od naszego to przesuwamy ten element z lewej w prawo o jedno czyli nasz element na pozycji w j idzie na pozycje j+1
     warto zauwazyc ze tutaj odejmiemy 1 od j o jeden raz za duzo (bo odejmujemy na kocu wiec jak juz nie dziala to oznacza ze juz nasz key jest mniejszy od elementu j a wiec musimy go wstawic w j+1
     */
    for(int i = 1; i < N; i++) {
        int key = tab[i];
        int j =i-1;
        while (tab[j]>key && j>=0) {
            tab[j+1] = tab[j];
            j-=1;
        }
        tab[j+1] = key;
    }
    for(int i = 0; i < N; i++) {
        printf("%d ", tab[i]);
    }
}