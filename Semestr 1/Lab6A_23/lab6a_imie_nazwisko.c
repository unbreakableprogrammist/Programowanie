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

//sygnatury funkcji tutaj
 
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

//deklaracje funkcji tutaj
