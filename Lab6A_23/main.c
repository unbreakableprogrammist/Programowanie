#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FL 18 //liczba elementow w tworzonej liscie, potem ulegnie zmianie!

struct node
{
    int num;                    //dane
    struct node *nextptr;       //nastepny wezel
} *first_list = NULL, *second_list = NULL;
typedef struct node sn;

/* ETAP 1 */
int nodeInsertatEnd(sn **begin, int value);
void displayList(sn *begin);
void cleanList(sn **begin);
/* ETAP 2 */
void sortRange(sn **begin, int end);
void swapNodes(sn **first, sn **second, sn **previous); // funkcja pomocnicza do zamiany node'ów miejscami
/* ETAP 3 */
void sweepList(sn **begin);

int main()
{
    int i,los,en;
    srand((unsigned)time(NULL));
    //ETAP 1
    for (i =0; i<FL; i++)
    {
        los = rand()%10; //przykladowy zakres losowanych wartosci
        nodeInsertatEnd(&first_list,los);
    }
    printf("Singly linked list:\n");
    printf("-----------------------------------------------\n");
    displayList(first_list);
    cleanList(&first_list);
    displayList(first_list);

    // ETAP 2
    printf("Singly linked list (new one):\n");
    printf("-----------------------------------------------\n");
    for (i =0; i<FL; i++)
    {
        los = rand()%5;//przykladowy zakres losowanych wartosci do listy
        nodeInsertatEnd(&first_list,los);
    }
    displayList(first_list);
    en = 5;//FL-1//5//0 testowane beda rozne poprawne zakresy
    printf("Singly linked list after sorting on the interval [0,%d]: \n",en);
    sortRange(&first_list,en);
    sortRange(&first_list,en); //celowe powtorzenie
    displayList(first_list);

    // ETAP 3
    printf("Singly linked list without duplicates: \n");
    printf("-----------------------------------------------\n");
    sweepList(&first_list);
    sweepList(&first_list); //celowe powtorzenie
    displayList(first_list);
    //sprzatanie
    cleanList(&first_list);
    displayList(first_list);
    cleanList(&second_list);
    displayList(second_list);

    return 0;
}

// definicje funkcji:

int nodeInsertatEnd(sn **begin, int value) {
    sn *newnode, *tmp;

    // inicjalizacja nowego node'a
    newnode = (sn*)malloc(sizeof(sn));

    if (newnode == NULL) {
        printf("\nBłąd alokacji pamięci\n");
        return 1;
    }

    newnode->num = value;
    newnode->nextptr = NULL;

    // jesli lista pusta to dodajemy na poczatek
    if (*begin == NULL) {
        *begin = newnode;
        return 0; // jesli wszystko git
    }

    // inaczej szukamy aktualnego ostatniego node'a
    tmp = *begin;

    while (tmp->nextptr) {
        tmp = tmp->nextptr;
    }

    tmp->nextptr = newnode;

    return 0; // jeśli wszystko git
}

void displayList(sn *begin) {
    int i;

    // jesli lista pusta to info dla usera
    if (begin == NULL) {
        printf("\nNo data found in the empty list.\n");
        return;
    }

    // drukowanie listy
    // kreska
    printf("\n");
    for (i = 0; i < FL; i++) {
        printf("-----");
    }
    printf("\n");

    // elementy
    while (begin) {
        printf("%d -> ", begin->num);
        begin = begin->nextptr;
    }

    // kreska
    printf("\n");
    for (i = 0; i < FL; i++) {
        printf("-----");
    }
    printf("\n");

    return;
}

void cleanList(sn **begin) {
    // **begin - adres pointera do pierwszego node'a

    sn *tmp = *begin;   // adres pierwszego node'a listy

    while (tmp) {
        (*begin) = (*begin)->nextptr;   // bierzemy adres kolejnego node'a
        free(tmp);                      // usuwamy z pamięci całego node'a
        //printf("%p\n", tmp);
        tmp = *begin;                   // bierzemy adres do kolejnego node'a listy
                                        // jesli NULL to nie ma kolejnego elementu i while sie konczy
                                        // jesli jest to usuwamy do skutku

    }

    return;
}

void sortRange(sn **begin, int end) {
    int i,j;
    sn *next, *first, *previous;

    // bubble sort
    for (i = 0; i < end+1-i; i++) { // dla całej listy byłoby FL zamiast end+1
        first = *begin;
        next = (*begin)->nextptr;
        previous = NULL;

        for(j = 0; j < end; j++) { // dla całej listy byłoby while(next) {}
            if (first->num > next->num) {
                if (previous == NULL) {
                    *begin = next;
                }

                swapNodes(&first, &next, &previous);

                // przed zamiana: prev -> first -> next -> x
                // po zamianie: prev -> next -> first -> x
                previous = next;
                next = first->nextptr;
            } else {
                // bez zamiany: prev -> first -> next -> x
                previous = first;
                first = next;
                next = next->nextptr;
            }
        }
    }

    return;
}

void swapNodes(sn **first, sn **second, sn **previous) {
    // jeśli zmiany na początku listy
    if (*previous == NULL) {
        (*first)->nextptr = (*second)->nextptr;
        (*second)->nextptr = *first;
        *first = *second;
    }
    else {
        (*previous)->nextptr = *second;
        (*first)->nextptr = (*second)->nextptr;
        (*second)->nextptr = *first;
    }

    return;
}

void sweepList(sn **begin) {
    sn *value = *begin;
    sn *prev, *first, *next;

    while (value) {
        if (value->nextptr == NULL) {
            break;
        } else {
            prev = value;
            first = value->nextptr;

            while(first) {
                next = first->nextptr;

                if (first->num == value->num) {
                    prev->nextptr = next;
                    free(first);

                    first = next;
                } else {
                    prev = first;
                    first = next;
                }
            }
        }

        value = value->nextptr;
    }

    return;
}
