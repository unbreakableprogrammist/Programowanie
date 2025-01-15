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
int add_student(List *L, Student student, int priority);
void print_list(List *L);

// ETAP 2
Node* find_student(List *L, int index);
int remove_student(List *L, int index);

// ETAP 3
int change_priority(/*...*/);
void reverse_list(/*...*/);

// ETAP 4
void clear_list(/*...*/);

// --------------------------------------------------------------------------

int main() {

    int idx1 = 313095, idx2 = 329541, idx3 = 306179, idx4 = 321476;
    int idx5 = 313131;
    Student s1 = {"Zuzanna", "O.", idx1};
    Student s2 = {"Jacek", "Z.", idx2};
    Student s3 = {"Piotr", "S.", idx3};
    Student s4 = {"Bartosz", "W.", idx4};


    printf("\n****************** ETAP 1 ******************\n");

    List* L = init_list();
    add_student(L, s1, 2);
    add_student(L, s2, 2);
    add_student(L, s3, 4);
    add_student(L, s4, 5);

    print_list(L);

    printf("\n****************** ETAP 2 ******************\n");

    printf("Finding student with a given index\n\n");
    printf("Example 1\n");
    Node* n = find_student(L, idx3);
    if (n) {
        printf("Priority: %d, %s %s, index: %d\n", n->priority, n->data.name, n->data.surname, n->data.index);
    } else {
        printf("Student not found.\n");
    }

    printf("\nExample 2\n");
    n = find_student(L, idx5);
    if (n) {
        printf("Priority: %d, %s %s, index: %d\n", n->priority, n->data.name, n->data.surname, n->data.index);
    } else {
        printf("Student not found.\n");
    }

    printf("\nRemoving student with a given index\n\n");
    remove_student(L, idx1);
    print_list(L);


    printf("\n****************** ETAP 3 ******************\n");

//    printf("Changing priority of student\n\n");
//    change_priority(L, idx3, 1);
//    print_list(L);
//
//    printf("\nReversing list:\n");
//    reverse_list(L);
//    print_list(L);

    printf("\n****************** ETAP 4 ******************\n");

//    clear_list(L);
//    printf("Should print empty list\n");
//    print_list(L);
//
//    free(L);

    return 0;
}

// --------------------------------------------------------------------------

List* init_list() {
    List *new_list;

    new_list = (List*)malloc(sizeof(List));

    if (new_list == NULL) {
        return NULL;
    }

    return new_list;
}

int add_student(List *L, Student student, int priority) {
    Node *i = L->head;
    Node *new_node;

    new_node = (Node*)malloc(sizeof(Node));

    // jesli sie nie udalo to return 0
    if (new_node == NULL) {
        return 0;
    }

    new_node->data = student;
    new_node->priority = priority;
    new_node->next = NULL;

    // lista pusta dodaje na początek
    if (i == NULL) {
        L->head = new_node;
    }
    // jesli nie to w odpowiednim miejscu
    else {
        // tez wstawiamy na poczatek ale przesuwamy element
        if (i->priority < priority) {
            new_node->next = i;
            L->head = new_node;
        }
        else {
            while (i->next) {
                if ((i->next)->priority < priority) {
                    new_node->next = i->next;
                    i->next = new_node;

                    break;
                }

                i = i->next;
            }

            // jesli nie wstawimy wczesniej to wstawiamy na koniec
            if (i->next == NULL) {
                i->next = new_node;
            }
        }
    }

    // jesli sukces to return 1
    return 1;
}

void print_list(List *L) {
    Node *i = L->head;

    while (i) {
        printf("\nPriority:  %d, %s %s, index: %d", i->priority, i->data.name, i->data.surname, i->data.index);

        i = i->next;
    }

    return;
}

Node* find_student(List *L, int index) {
    Node *i = L->head;

    if (i == NULL) {
        return NULL;
    }

    while (i) {
        if (i->data.index == index) {
            return i;
        }

        i = i->next;
    }

    return NULL;
}

int remove_student(List *L, int index) {
    Node *i = L->head;
    Node *prev = NULL;

    // jesli lista pusta to nic nie usuwamy
    if (i == NULL) {
        return 1;
    }

    // jesli na poczatku to zmieniamy glowe
    if (i->data.index == index) {
        L->head = i->next;

        free(i);

        return 1;
    }

    // jesli dalej to szukamy i usuwamy
    while (i) {
        if (i->data.index == index) {
            prev->next = i->next;

            free(i);

            return 1;
        }

        prev = i;
        i = i->next;
    }

    return 1;
}