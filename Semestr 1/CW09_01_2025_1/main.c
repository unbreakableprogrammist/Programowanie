#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FL 5 //

// Deklaracja struktury listy jednokierunkowej:

struct node {
    int num;                // dane
    struct node *nextptr;   // nastepny wezel
} *first_list = NULL, *second_list = NULL;

typedef struct node sn;

// Deklaracje funkcji:

/* ETAP 1 */
int nodeInsertatEnd(sn **begin, int value);
void displayList(sn *begin);
void cleanList(sn **begin);
/* ETAP 2 */
//
/* ETAP 3 */
//

int main(void)
{
    int i, los, en;
    srand((unsigned)time(NULL));

    /* ETAP 1 */
    // dodawanie liczb i node'ow
    for (i = 0; i < FL; i++) {
        los = rand() % 10;
        nodeInsertatEnd(&first_list, los);
    }
    // wyswietlanie listy
    displayList(first_list);
    // zwalnianie pamieci
    cleanList(&first_list);


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
        printf("\nLista jest pusta\n");
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

