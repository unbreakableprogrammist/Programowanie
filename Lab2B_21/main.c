#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

//ETAP 1 (1,5p)
void fill1(int tab[N], int n, int k);
void print(int tab[N], int n);

//ETAP 2 (1p)
void fill2(int tab[N], int n, int a, int b);

//ETAP 3 (1p)
int test(int tab[N], int n);

//ETAP 4 (1p)
int sum(int tab1[N], int n1, int tab2[N], int n2, int tab3[2*N]);

//ETAP 5 (1p)
void rotation(int tab[N], int n, int k);

//ETAP 6 (1,5p)
int pair_single(int tab[N], int n);

//-------------------------------------------------------
int main()
{
	int tab1[N], tab2[N], tab3[N], tab4[2*N];
	int n1 = 8, n2 = N, n3=N, n4=0;	//odpowiednia liczba właściwych elementów w powyższych tablicach

	srand((unsigned)time(NULL));
	//srand(5);	//przykładowe wyniki dla wartości 5

	printf("\n---------------   ETAP 1 (1 pkt)   ---------------\n");

	fill1(tab1, n1, 2);
	printf("\ntab1: ");
	print(tab1, n1);

	fill1(tab2, n2, 4);
	printf("tab2: ");
	print(tab2, n2);

	printf("\n---------------   ETAP 2 (1,5 pkt)   ---------------\n");

	fill2(tab3, n3, 2, 20);
	printf("tab3: ");
	print(tab3, n3);

	printf("\n---------------   ETAP 3 (1 pkt)   ---------------\n");

	int k1 = test(tab1, n1);
	int k2 = test(tab3, n3);

	if (k1)
		printf("\n tab1 - ciag Fibonacciego ");
	else
		printf("\n tab1 - to NIE jest ciag Fibonacciego \n");

	if (k2)
		printf("\n tab3 - ciag Fibonacciego ");
	else
		printf("\n tab3 - to NIE jest ciag Fibonacciego \n");

	printf("\n---------------   ETAP 4 (1 pkt)   ---------------\n");

	printf("\nUporzadkowana suma tab4 dla tablic tab2 i tab3\n");
	n4=sum(tab2, n2, tab3, n3, tab4);
	printf("\ntab4: ");
	print(tab4, n4);

	printf("\n---------------   ETAP 5 (1 pkt)   ---------------\n");

	printf("\nRotacja tab2\n");
	printf("\ntab2: ");
	print(tab2, n2);

	rotation(tab2, n2, 3);

	printf("\ntab2: ");
	print(tab2, n2);

	printf("\n---------------   ETAP 6 (1,5 pkt)   ---------------\n");

	int tab5[2*N] = { 3, 2, 5, 7, 3, 6, 4, 7, 7, 8, 2, 8, 6, 6, 2, 3, 2, 5, 9, 1};
	int tab6[2*N] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	int tab7[2*N];
	int ile_par;

	//odkomentuj dla losowych danych
	//fill2(tab5,2*N,2,20);

	printf("\nSingle i pary: tab5\n");
	printf("\ntab5: ");
	print(tab5, 2*N);

	ile_par = pair_single(tab5, 2*N);
	printf("\nliczba par: %d", ile_par);
	printf("\ntab5: ");
	print(tab5, 2*N);

	//----------------------------------------
	printf("\nPary i Single: tab6\n");
	printf("\ntab6: ");
	print(tab6, 2 * N);

	ile_par = pair_single(tab6, 2 * N);
	printf("\nliczba par: %d", ile_par);
	printf("\ntab6: ");
	print(tab6, 2 * N);

	//----------------------------------------
	for (int i = 0; i < 2 * N; i++) tab7[i] = i + 1;

	printf("\nPary i Single: tab7\n");
	printf("\ntab7: ");
	print(tab7, 2 * N);

	ile_par = pair_single(tab7, 2 * N);
	printf("\nliczba par: %d", ile_par);
	printf("\ntab7: ");
	print(tab7, 2 * N);

	printf("\nKONIEC\n");
	return 0;
}

//-------------------------------------------------------
//poniżej zaimplementuj wymagane funkcje

void fill1 (int tab[N], int n, int k) {
	int i;

	for (i = 0; i < n; i++) {
		if (i < k) {
			tab[i] = i+1;
		} else {
			int j, suma = 0;

			for (j = 1; j <= k; j++) {
				suma += tab[i-j];
			}

			tab[i] = suma;
		}
	}
}

void print(int tab[N], int n) {
	int i;

	printf("[ ");
	for (i = 0; i < n; i++) {
		printf("%d ", tab[i]);
	}
	printf("]\n");
}

void fill2(int tab[N], int n, int a, int b) {
	int i,j, temp;

	for (i = 0; i < n; i++) {
		tab[i] = (rand() % (b - a)) + a;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (tab[j] > tab[j+1]) {
				temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp;
			}
		}
	}
}

int test(int tab[N], int n) {
	int czy_ciag = 0, i;

	for (i = 0; i <= n; i++) {
		if (i == 0) {
			if (tab[i] != 1) {
				break;
			}
		} else if (i == 1) {
			if (tab[i] != 2) {
				break;
			}
		} else if (i < n) {
			if (tab[i] != (tab[i-1] + tab[i-2])) {
				break;
			}
		} else if (i == n) {
			czy_ciag = 1;
			break;
		}
	}

	return czy_ciag;
}

int sum(int tab1[N], int n1, int tab2[N], int n2, int tab3[2*N]) {
	int i, j = 0, k = 0;

	for (i = 0; i < (n1+n2); i++) {
		if ((j < n1 && k < n2 && tab1[j] <= tab2[k]) || (j < n1 && k>= n2)) {
			tab3[i] = tab1[j];
			j++;
		} else if ((j < n1 && k < n2 && tab2[k] < tab1[j]) || (j >= n1 && k < n2)) {
			tab3[i] = tab2[k];
			k++;
		}
	}

	return n1 + n2;
}

void rotation(int tab[N], int n, int k) {
	int i,j, temp;

	for (i = 0; i < k; i++) {
		for (j = n-k+i; j > i; j--) {
			temp = tab[j];
			tab[j] = tab[j-1];
			tab[j-1] = temp;
		}
	}
}

int pair_single(int tab[N], int n) {
	int i,temp, pocz = 0, kon = n-1, ile_par = 0;

	while (pocz < kon) {
		for (i = pocz+1; i <= kon; i++) {
			if (tab[pocz] == tab[i]) {
				temp = tab[i];
				tab[i] = tab[pocz+1];
				tab[pocz+1] = temp;
				ile_par++;
				break;
			}
		}

		if (tab[pocz] == tab[pocz+1]) {
			pocz += 2;
		} else {
			temp = tab[kon];
			tab[kon] = tab[pocz];
			tab[pocz] = temp;
			kon--;
		}
	}

	return ile_par;
}