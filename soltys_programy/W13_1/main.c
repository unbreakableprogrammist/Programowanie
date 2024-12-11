#include <stdio.h>
#include <stdlib.h>

int main() {
    struct element_listy {
        int value;
        struct element_listy * next;
    };
    typedef struct element_listy el_ls;

    int n,i;
    el_ls *head, *p, *q, *r;

    // wczytujemy zakres szukanych liczb
    scanf("%d", &n);

    // wpisujemy w pamięć wartości od 2 do n, zaczynając "od tyłu"
    head = NULL;
    for (i=n; i>1; i--) {
        q = (el_ls *)malloc(sizeof(el_ls));
        q->next = head;
        q->value = i;
        head = q;
    }

    // pierwszy element z pamięci czyli struktura z value 2
    p = head;

    do {
        // bierzemy aktualną wartość
        i = p->value;
        // zapisujemy strukturę p do q
        q = p;
        // kolejna struktura po q
        r = q->next;
        while(NULL!=r) {
            // usuwamy wszystkie liczby podzielne przez naszą wartość (np. wszystkie liczby podzielne przez 2)
            if (0 == r->value % i) {
                q->next = r->next;
                // zwalniamy element r
                free(r);
                // zapisujemy do r, kolejny element
                r = q->next;
            }
            // jeśli nie podzielna to idziemy dalej
            else {
                q = r;
                r = q->next;
            }
        }
        p = p->next;
    }
    while (NULL!=p);

    p = head;

    do {
        printf("%d\n", p->value);
        p = p->next;
    }
    while (NULL!=p);

    return 0;
}
