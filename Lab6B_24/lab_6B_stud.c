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
List* init_list(/*...*/);
int add_student(/*...*/);
void print_list(/*...*/);

// ETAP 2
Node* find_student(/*...*/);
int remove_student(/*...*/);

// ETAP 3
int change_priority(/*...*/);
void reverse_list(/*...*/);

// ETAP 4
void clear_list(/*...*/);

// --------------------------------------------------------------------------

int main() {

    int idx1 = 313085, idx2 = 339521, idx3 = 305178, idx4 = 312467;
    int idx5 = 313131;
    Student s1 = {"Alicja", "W.", idx1};
    Student s2 = {"Jakub", "T.", idx2};
    Student s3 = {"Weronika", "P.", idx3};
    Student s4 = {"Joanna", "Z.", idx4};


    printf("\n****************** ETAP 1 ******************\n");

//    List* L = init_list();
//    add_student(L, s1, 1);
//    add_student(L, s2, 3);
//    add_student(L, s3, 3);
//    add_student(L, s4, 4);
//
//    print_list(L);

    printf("\n****************** ETAP 2 ******************\n");

//    printf("Finding student with a given index\n\n");
//    printf("Example 1\n");
//    Node* n = find_student(L, idx3);
//    if (n) {
//        printf("%s %s (%d), priority: %d\n", n->data.name, n->data.surname, n->data.index, n->priority);
//    } else {
//        printf("Student not found.\n");
//    }
//
//    printf("\nExample 2\n");
//    n = find_student(L, idx5);
//    if (n) {
//        printf("%s %s (%d), priority: %d\n", n->data.name, n->data.surname, n->data.index, n->priority);
//    } else {
//        printf("Student not found.\n");
//    }
//
//    printf("\nRemoving student with a given index\n\n");
//    remove_student(L, idx2);
//    print_list(L);


    printf("\n****************** ETAP 3 ******************\n");

//    printf("Changing priority of student\n\n");
//    change_priority(L, idx3, 5);
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