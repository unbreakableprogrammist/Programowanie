#include <stdio.h>

#define N 50

void fib(int tab[N]);

int main() {
    int tab[N] = {0};
    int i;

    fib(tab);

    for(i = 0; i < N; i++) {
        printf("%d ", tab[i]);
    }
    return 0;
}

void fib(int tab[N]) {
    int a = 0, b = 1, c;
    int index = 0;

    tab[index] = -1;
    index += b+1;
    tab[index] = -1;

    do {
        c = a+b;
        a = b;
        b = c;

        index += c+1;

        if(index < N) tab[index] = -1;

    } while (index < N);

    return;
}