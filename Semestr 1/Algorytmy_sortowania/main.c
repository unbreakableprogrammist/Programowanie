#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // stała wielkość tablic
#define MAX 20 // największy element w tablicach

void create_tab(int tab[N]);
void print_tab(int tab[N]);
void bubble_sort(int tab[N]);
void insertion_sort(int tab[N]);
void selection_sort(int tab[N]);
void merge_sort(int tab[N]);
void merge(int tab[N], int l1, int r1, int l2, int r2); // funkcja pomocnicza do merge_sort
void quick_sort(int tab[N], int start, int end);
int partition(int tab[N], int start, int end); // funkcja pomocnicza do quick_sort

int main(void)
{
    int tab[N], choice;

    srand((unsigned)time(NULL)); // start generatora liczb losowych

    create_tab(tab);

    printf("Wybierz algorytm sortowania (wpisz odpowiedni numer):\n1 - bubble sort\n2 - insertion sort\n3 - selection sort\n4 - merge sort\n5 - quick sort\n");
    scanf("%d", &choice);

    printf("Before:\n");
    print_tab(tab);

    // Wybierz algorytm:
    switch (choice) {
        case 1:
            printf("\nBubble sort...\n");
            bubble_sort(tab);
            break;
        case 2:
            printf("\nInsertion sort...\n");
            insertion_sort(tab);
            break;
        case 3:
            printf("\nSelection sort...\n");
            selection_sort(tab);
            break;
        case 4:
            printf("\nMerge sort...\n");
            merge_sort(tab);
            break;
        case 5:
            printf("\nQuick sort...\n");
            quick_sort(tab, 0, N-1);
            break;
        default:
            printf("\nZła opcja!\n");
            break;
    }

    printf("\nAfter:\n");
    print_tab(tab);

    return 0;
}

void create_tab(int tab[N]) {
    int i;

    for (i = 0; i < N; i++) {
        tab[i] = rand() % (MAX+1); // zapełnianie tablicy losowymi wartościami
    }
}

void print_tab(int tab[N]) {
    int i;

    printf("[");
    for (i = 0; i < N-1; i++) {
        printf("%d, ", tab[i]);
    }
    printf("%d]\n", tab[N-1]);
}

void bubble_sort(int tab[N]) {
    int i, j, isOp, temp;

    for (i = 0; i < N-1; i++) {
        isOp = 0; // licznik operacji na 0
        for (j = 0; j < N - i - 1; j++) {
            if (tab[j] > tab[j+1]) {
                temp = tab[j]; // jeśli po lewej większy to zamieniamy miejscami
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                isOp = 1; // wykonaliśmy operację, więc isOp = 1;
                printf("\ni: %d, j: %d\n", i, j);
                print_tab(tab);
            }
        }
        if (isOp == 0) {
            break; // jeśli nie wykonano żadnych operacji w iteracji to tablica posortowana
        }
    }
}

void insertion_sort(int tab[N]) {
    int i, j, temp;

    for (i = 1; i < N; i++) {
        for (j = i; j > 0; j--) {
            if (tab[j] < tab[j-1]) {
                temp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = temp;
                printf("\ni: %d, j: %d\n", i, j);
                print_tab(tab);
            } else {
                break;
            }
        }
    }
}

void selection_sort(int tab[N]) {
    int i, j, temp, min_index;

    for (i = 0; i < N-1; i++) { // nie musimy sprawdzać ostatniego elementu dlatego N-1
        min_index = i;

        for (j = i+1; j < N; j++) {
            min_index = tab[j] < tab[min_index] ? j : min_index; // szukamy indeksu najmniejszego elementu po prawej
        }

        if (min_index != i) {
            temp = tab[i]; // przenosimy najmniejszy element na jego miejsce, jeśli jest po prawej
            tab[i] = tab[min_index];
            tab[min_index] = temp;
            printf("\ni: %d, j: %d\n", i, j);
            print_tab(tab);
        }
    }
}

void merge_sort(int tab[N]) {

    int i, j, e = 1, end; // e - ilość mergowanych elementów w danym powtórzeniu w podtablicach

    // wywołujemy mergowanie (N+1)/2 razy (np. dla N=6 - 3 razy oraz dla N=3 - 2 razy)
    for (i = 0; i < (N-1)/2; i++) {

        for (j = 0; j < N && j+e<N; j+=(e*2)) {
            end = j+e+e-1 < N ? j+e+e-1 : N-1;
            merge(tab, j, j+e-1, j+e, end);
            printf("\ni: %d, j: %d, e: %d, merge(%d,%d,%d,%d)\n", i, j, e, j, j+e-1, j+e, end );
            print_tab(tab);
        }
        // ilość elementów rośnie razy dwa po każdej turze scalania
        e *= 2;
    }
}

void merge(int tab[N], int l1, int r1, int l2, int r2) {
    int i, j, n, temp[(r1-l1+1)+(r2-l2+1)];

    // scalanie dwóch tablic do tablicy pomocniczej w dobrej kolejności
    // wejściowe tablice musza być posortowane
    for (i = l1, j = l2, n = 0; i <= r1 && j <= r2; n++) {
        if (tab[i] <= tab[j]) {
            temp[n] =  tab[i];
            i++;
        } else {
            temp[n] = tab[j];
            j++;
        }
    }
    // scalanie pozostałych wartości:
    for (; i <= r1; i++, n++) {
        temp[n] = tab[i];
    }
    for (; j <= r2; j++, n++) {
        temp[n] = tab[j];
    }

    // przepisanie z pomocniczej do dobrej tablicy
    for (i = l1, n = 0; i < l1+(r1-l1+1)+(r2-l2+1); i++, n++) {
        tab[i] = temp[n];
    }

    return;
}

int partition(int tab[N], int start, int end) {
    int pivot = start + rand() % (end - start + 1); // losujemy index pivota z naszej tablicy
    int i, temp;

    // wstawiamy wartosc pivota na koniec tablicy żeby było łatwiej poprzestawiać elementy
    temp = tab[pivot];
    tab[pivot] = tab[end];
    tab[end] = temp;

    // znajdziemy poprawna lokacje pivota potem, na razie zaczynamy od początku
    // bedziemy wstawiac mniejsze elementy na poczatek, wieksze dalej
    // pivot bedzie przechowywal indeks na ktorym powininen wyladowac kolejny mniejszy element
    // a na koniec bedzie to miejsce na ktorym powinien wyladowac wartosc wczesniej wybrana
    pivot = start;

    for (i = start; i < end; i++) {
        if (tab[i] < tab[end]) {
            temp = tab[i];
            tab[i] = tab[pivot];
            tab[pivot] = temp;
            pivot++;
        }
    }

    // wstawiamy wartosc pivota na swoje miejsce
    temp = tab[end];
    tab[end] = tab[pivot];
    tab[pivot] = temp;

    printf("\nPartition for pivot value: %d:\n", tab[pivot]);
    printf("\n[");
    for (i = start; i < end; i++) {
        printf("%d, ", tab[i]);
    }
    printf("%d]\n", tab[end]);

    return pivot; // zwracamy index pivota
}

void quick_sort(int tab[N], int start, int end) {
    int i;

    if (start < end) {
        i = partition(tab, start,end);

        quick_sort(tab, start, i - 1);
        quick_sort(tab, i + 1, end);
    }

    return;
}