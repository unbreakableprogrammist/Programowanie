#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 50

typedef struct Student {
    char name[M];
    char surname[M];
    int index;
} Student;

typedef struct Node {
    Student data;
    int priority;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

// --------------------------------------------------------------------------

// ETAP 1
List* init_list();
int add_student(List *L, Student s, int priority);
void print_list(List *L);

// ETAP 2
Node* find_student(List *L, int index);
int remove_student(List *L, int index);

// ETAP 3
int change_priority(List *L, int index, int new_priority);
void reverse_list(List *L);

// ETAP 4
void clear_list(List *L);

// --------------------------------------------------------------------------

int main() {

    int idx1 = 313085, idx2 = 339521, idx3 = 305178, idx4 = 312467;
    int idx5 = 313131;
    Student s1 = { "Alicja", "W.", idx1 };
    Student s2 = { "Jakub", "T.", idx2 };
    Student s3 = { "Weronika", "P.", idx3 };
    Student s4 = { "Joanna", "Z.", idx4 };


    printf("\n****************** ETAP 1 ******************\n");

    List* L = init_list();
    add_student(L, s1, 1);
    add_student(L, s2, 3);
    add_student(L, s3, 3);
    add_student(L, s4, 4);
    
    print_list(L);

    printf("\n****************** ETAP 2 ******************\n");

    printf("Finding student with a given index\n\n");
    printf("Example 1\n");
    Node* n = find_student(L, idx3);
    if (n) {
        printf("%s %s (%d), priority: %d\n", n->data.name, n->data.surname, n->data.index, n->priority);
    } else {
        printf("Student not found.\n");
    }
    
    printf("\nExample 2\n");
    n = find_student(L, idx5);
    if (n) {
        printf("%s %s (%d), priority: %d\n", n->data.name, n->data.surname, n->data.index, n->priority);
    } else {
        printf("Student not found.\n");
    }
    
    printf("\nRemoving student with a given index\n\n");
    remove_student(L, idx2);
    print_list(L);


    printf("\n****************** ETAP 3 ******************\n");

    printf("Changing priority of student\n\n");
    change_priority(L, idx3, 5);
    print_list(L);
    
    printf("\nReversing list:\n");
    reverse_list(L);
    print_list(L);


    printf("\n****************** ETAP 4 ******************\n");

    clear_list(L);
    printf("Should print empty list\n");
    print_list(L);
    
    free(L);

    return 0;
}

// --------------------------------------------------------------------------

// ETAP 1
List* init_list() {
    List* new_list;

    new_list = (List*)malloc(sizeof(List));

    if (new_list == NULL) {
        return NULL;
    }

    new_list->head = NULL;

    return new_list;
}

int add_student(List* L, Student s, int priority) {
    Node* i = L->head;
    // ------------- inicjulizujemy nowego node'a -----------------
    Node* new_node;

    new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL) {
        return 0;
    }

    new_node->data = s;
    new_node->priority = priority;
    new_node->next = NULL;
    // ----------------------------------------------------------------

    // jesli lista pusta to na początek
    if (i == NULL) {
        L->head = new_node;
        return 1;
    }

    // jesli jest element to wstawiamy na poczatek i przesuwamy
    if (i->priority > priority) {
        new_node->next = i;
        L->head = new_node;
        return 1;
    }

    // jesli w srodku to szukamy miejsca i tam wstawiamy
    while (i->next) {
        // jesli kolejny elemeny ma nizszy priorytet to wstawiamy w tym miejscu
        if ((i->next)->priority > priority) {
            new_node->next = i->next;
            i->next = new_node;
            return 1;
        }

        i = i->next;
    }

    // jesli doszlismy do konca bez wstawiania to dodajemy na koniec
    if (i->next == NULL) {
        i->next = new_node;
    }

    return 1;
}

void print_list(List* L) {
    Node* i = L->head;

    if (i == NULL) {
        printf("\nList is empty\n");
    }

    while (i) {
        printf("%s %s (%d), priority: %d\n", i->data.name, i->data.surname, i->data.index, i->priority);

        i = i->next;
    }

    return;
}

// ETAP 2
Node* find_student(List* L, int index) {
    Node* i = L->head;

    // jesli lista pusta to zwracamy null
    if (i == NULL) {
        return NULL;
    }

    // szukamy do skutku
    while (i) {
        // jesli znajdziemy to zwracamy index
        if (i->data.index == index) {
            return i;
        }

        i = i->next;
    }

    // jesli nie znajdziemy to null
    return NULL;
}

int remove_student(List* L, int index) {
    Node* i = L->head;
    Node* prev = NULL;

    if (i == NULL) {
        return 1;
    }

    // jesli na poczatku to zmieniamy glowe i usuwamy
    if (i->data.index == index) {
        L->head = i->next;

        free(i);

        return 0;
    }

    // szukamy i jak znajdziemy to usuwamy
    while (i) {
        if (i->data.index == index) {
            prev->next = i->next;

            free(i);

            break;
        }

        prev = i;
        i = i->next;
    }

    return 0;
}

// ETAP 3
int change_priority(List* L, int index, int new_priority) {
    int changed = 1;
    Node* i = L->head;
    Node* prev = NULL;
    Node* s = find_student(L, index);
    Node* next;

    // jesli nie ma studenta lub lista pusta return 1;
    if (s == NULL || i == NULL) {
        return 1;
    }
    
    // zmieniamy priorytet
    s->priority = new_priority;

    // wstawiamy na odpowiednie miejsce
    while (changed) {
        // resetujemy zmienne i zaczynamy od poczatku listy
        prev = NULL;
        i = L->head;
        changed = 0;

        while (i && i->next) {
            if (i->priority > (i->next)->priority) {
                // zamiana miejscami
                next = i->next;
                i->next = next->next;
                next->next = i;

                // jesli na poczatku to zmieniamy heada
                if (prev == NULL) {
                    L->head = next;
                }
                // jesli dalej to zmieniamy poprzednika
                else {
                    prev->next = next;
                }

                // były zmiany więc flaga = 1
                changed = 1;

                // przesuwamy sie poprzednikiem 
                if (prev != NULL) {
                    prev = prev->next;
                }
                else {
                    prev = L->head;
                }
            }
            // jesli nie ma potrzeby zmiany to po prostu idziemy dalej
            else {
                prev = i;
                i = i->next;
            }
        }
    }

    return 0;
}

void reverse_list(List* L) {
    int changed = 1;
    Node* i = L->head;
    Node* prev = NULL;
    Node* next;

    if (i == NULL) {
        return;
    }

    while (changed) {
        // resetujemy zmienne i zaczynamy od poczatku listy
        prev = NULL;
        i = L->head;
        changed = 0;

        while (i && i->next) {
            if (i->priority < (i->next)->priority) {
                // zamiana miejscami
                next = i->next;
                i->next = next->next;
                next->next = i;

                // jesli na poczatku to zmieniamy heada
                if (prev == NULL) {
                    L->head = next;
                }
                // jesli dalej to zmieniamy poprzednika
                else {
                    prev->next = next;
                }

                // były zmiany więc flaga = 1
                changed = 1;

                // przesuwamy sie poprzednikiem 
                if (prev != NULL) {
                    prev = prev->next;
                }
                else {
                    prev = L->head;
                }
            }
            // jesli nie ma potrzeby zmiany to po prostu idziemy dalej
            else {
                prev = i;
                i = i->next;
            }
        }
    }

    return;
}

// ETAP 4
void clear_list(List* L) {
    Node* i = L->head;

    while (i) {
        L->head = (L->head)->next;

        free(i);

        i = L->head;
    }

    return;
}
