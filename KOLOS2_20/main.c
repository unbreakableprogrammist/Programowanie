#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct Table {
    int *ptr;
    int size;
} Table;

typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Zadanie 2
char* repeat(const char* str, int n);
// Zadanie 3
Table* create_dynamic(int tab[N][N], int n, int i, int j);
void print_tab(Table *t);
// Zadanie 4
Node* create_node(char data);
void print_list(Node* L);
void append_node(Node **L, Node* new_node);
void join_list(Node **L1, Node **L2);

int main(void)
{
    // Zadanie 2
    const char *str = "idzie zima";
    char *new_str = repeat(str, 2);

    printf("\nwynik: %s\n", new_str);

    // Zadanie 3
    int tab[N][N] = {{5,-5,3,-4,2},{0,2,6,-1,3},{1,4,1,-2,4},{0,2,-4,0,5},{1,2,3,4,5}};
    Table *new_t;

    new_t = create_dynamic(tab, 4, 2, 2);

    print_tab(new_t);

    // Zadanie 4
    int i;
    Node *L1, *L2;

    L1 = create_node('a');
    L2 = create_node('b');

    char* alphabet = "cdefghij";

    for (i = 0; i < strlen(alphabet); i++) {
        if (i%2 == 0) {
            append_node(&L1, create_node(alphabet[i]));
        } else {
            append_node(&L2, create_node(alphabet[i]));
        }
    }

    append_node(&L2, create_node('k'));
    append_node(&L2, create_node('l'));
    append_node(&L2, create_node('m'));

    printf("\nL1 przed: ");
    print_list(L1);
    printf("\nL2 przed: ");
    print_list(L2);

    join_list(&L1, &L2);
    printf("\nPo mergowaniu: ");
    print_list(L1);

    return 0;
}

// Zadanie 2 ---------------------------------
char* repeat(const char* str, int n) {
    char *new_str;
    int i,j;

    new_str = (char*)malloc((n * strlen(str) + 1) * sizeof(char));

    if (new_str == NULL) {
        return NULL;
    }

    for (i = 0; i < strlen(str); i++) {
        for (j = 0; j < n; j++) {
            new_str[n*i + j] = str[i];
        }
    }

    new_str[strlen(str)*n] = '\0';

    return new_str;
}

// Zadanie 3 ---------------------------------
void print_tab(Table *t) {
    int i;

    printf("\n");
    for (i = 0; i < t->size; i++) {
        printf("%d ", t->ptr[i]);
    }
    printf("\n");

    return;
}

Table* create_dynamic(int tab[N][N], int n, int i, int j) {
    Table *new_ptr;
    int k, l, negative_i = 0, zero_i = 0;

    // sprawdzamy poprawność danych
    if (n >= N || i < 0 || j < 0 || i >= n || j >= n) {
        printf("\nerror");
        return NULL;
    }

    new_ptr = (Table*)malloc(sizeof(Table));

    if (new_ptr == NULL) {
        printf("\nerror");
        return NULL;
    }

    new_ptr->ptr = (int*)malloc(n*n*sizeof(int));

    if (new_ptr->ptr == NULL) {
        printf("\nerror");
        return NULL;
    }

    new_ptr->size = 0;

    // przepisywanie wartości
    for (k = 0; k < n*n; k++) {
        if (tab[i][j] < 0) {
            for (l = k; l > negative_i; l--) {
                new_ptr->ptr[l] = new_ptr->ptr[l-1];
            }
            new_ptr->ptr[negative_i] = tab[i][j];
            negative_i++;
            zero_i++;
        }
        else if (tab[i][j] == 0) {
            for (l = k; l > zero_i; l--) {
                new_ptr->ptr[l] = new_ptr->ptr[l-1];
            }
            new_ptr->ptr[zero_i] = tab[i][j];
            zero_i++;
        }
        else {
            new_ptr->ptr[k] = tab[i][j];
        }

        new_ptr->size++;
        j++;

        if (j >= n) {
            j = 0;
            i++;
        }

        if (i >= n) {
            i = 0;
        }
    }

    return new_ptr;
}
// Zadanie 4 ---------------------------------
Node* create_node(char data) {
    Node *new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void print_list(Node* L) {
    while (L) {
        printf("%c ", L->data);

        L = L->next;
    }

    return;
}

void append_node(Node **L, Node* new_node) {
    Node *i = *L;

    if (i == NULL) {
        *L = new_node;
        return;
    }

    while(i->next) {
        i = i->next;
    }

    i->next = new_node;

    return;
}

void join_list(Node **L1, Node **L2) {
    Node *i = *L1;
    Node *j = *L2;
    Node *temp;

    // jesli L1 puste to podmieniamy z L2
    if (i == NULL) {
        *L1 = *L2;
        return;
    }

    // jesli L2 puste to nic nie robimy
    if (j == NULL) {
        return;
    }

    // dodajemy elementy z L2 do L1 naprzemiennie
    while (i->next && j->next) {
        temp = j->next;
        j->next = i->next;
        i->next = j;

        j = temp;
        i = (i->next)->next;
    }

    // jesli zostaly jakies w L2 to dodajemy po kolei
    if (j) {
        i->next = j;
    }

    return;
}