#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct array
{
	int* w;		//dynamiczna tablica n elementów
	int n;		//liczba elementów tablicy dynamicznej
				//jeśli tablica przechowuje wsp. dla wielomianu, to w[n-1] - wsp. przy najwyższej potędze, w[0]-wyraz wolny
} array;

//----------------------------------------------------------------------
//ETAP 1
void print(array w);
int polynomial_generator(array* w, int st, int a, int b);
int multiplication(array w1, array w2, array* w3);

//ETAP 2
int value(array* w, int x);
int find_roots(array w, array* roots);

//ETAP 3
int polyder(array w, array* w_prim);
int single_root(array w, int r);

//----------------------------------------------------------------------
int main()
{
	array roots = { NULL, 0};		//tablica całkowitych pierwiastków wielomianu
	array w1 = { NULL, 0 };		//tablica wsp. wielomianu w bazie potęgowej
										//w[n] - wsp. przy najwyższej potędze, w[0]-wyraz wolny
	array w2 = { NULL, 0 };
	array w3 = { NULL, 0 };

	array w_prim = {NULL, 0};

	int i;

	printf("\nETAP1-----------------------------------------------------------------\n");

	srand((unsigned)time(NULL));

	//srand(1640635484);
	int b = 5, a=-5;

	if (!polynomial_generator(&w1, 3, a, b) || !polynomial_generator(&w2, 5, a, b))
	{
		printf("NIE wylosowano wsp. dla wielomianu w1, w2!\n");
		free(w1.w);
		free(w2.w);
		return 1;
	}

	printf("Wylosowano wsp. dla wielomianu w1:\n");
	print(w1);

	printf("Wylosowano wsp. dla wielomianu w2:\n");
	print(w2);

	if (!multiplication( w1, w2, &w3))
	{
		printf("NIE zdefiniowano wsp. wielomianu w3!\n");
		free(w1.w);
		free(w2.w);
		return 1;
	}

	printf("Wsp. wielomianu w3=w1*w2 w bazie potegowej:\n");
	print(w3);


	printf("\n\nETAP2-----------------------------------------------------------------\n");

	if (!find_roots(w3, &roots))
	{
		printf("NIE znaleziono pierwiastkow calkowitych dla wielomianu w3!\n");
		free(w1.w);
		free(w2.w);
		free(w3.w);
		return 1;
	}

	printf("\nZnaleziona lista calkowitych pierwiastkow dla w3");
	print(roots);

	printf("\nSprawdzenie, czy to zera wielomianu?");
	for (i = 0; i < roots.n; i++)
		printf("\ndla x=r%d=%2d w(x)=%2d", i,roots.w[i], value(&w3, roots.w[i]));



	printf("\n\nETAP3-----------------------------------------------------------------\n");


	printf("Wsp. pochodnej wielomianu:\n");

	polyder(w3, &w_prim);
	print(w_prim);

	printf("\nCzy pojedyncze zero wielomianu? - przez sprawdzenie wartosci pochodnej:\n");

	for (i = 0; i < roots.n; i++)
		if (single_root(w3, roots.w[i]))
			printf("\n zero pojedyncze: r%d=%3d", i, roots.w[i]);



	//------------------------------------------------------------------------
	free(w1.w);
	free(w2.w);
	free(w3.w);
	free(roots.w);
	free(w_prim.w);

	printf("\n\nKONIEC\n");

	return 0;
}


//poniżej IMPLEMENTACJE FUNKCJI
//----------------------------------------------------------------------

void print(array w) {
	int i;

	printf("[ ");
	for (i = w.n-1; i >= 0; i--) {
		printf("%d ", w.w[i]);
	}
	printf("]\n");

	return;
}

int polynomial_generator(array* w, int st, int a, int b) {
	int i;

	// rezerwujemy pamięć
	w->w = (int*)malloc((st+1)*sizeof(int));
	if (w->w == NULL) {
		// jesli pamiec nie przydzielona to zwracamy 0
		return 0;
	}
	// ustawiamy wielkosc tablicy
	w->n = st+1;

	// losujemy wyraz wolny, jeśli zero to zmieniamy bo nie moze byc zero
	w->w[0] = a + rand() % (b-a+1);
	if (w->w[0] == 0) w->w[0] += 1;

	// wypelniamy zerami
	for (i = 1; i < st; i++) {
		w->w[i] = 0;
	}

	// wspolczynnik przy najwyzszej potedze = 1
	w->w[st] = 1;

	// jesli git to zwracamy 1
	return 1;
}

int multiplication(array w1, array w2, array* w3) {
	int i,j;

	// dlugosc wynikowego wielomianu
	w3->n = w1.n + w2.n - 1;

	// rezerwacja pamięci
	w3->w = (int*)malloc((w3->n)*sizeof(int));
	if (w3->w == NULL) {
		w3->n = 0;
		return 0;
	}

	// wypełniamy wartości zerami
	for (i = 0; i < w3->n; i++) {
		w3->w[i] = 0;
	}

	// mnożymy wielomiany przez siebie
	for (i = 0; i < w1.n; i++) {
		for (j = 0; j < w2.n; j++) {
			w3->w[i+j] += w1.w[i] * w2.w[j];
		}
	}

	// zwracamy 1 jeśli git
	return 1;
}

int value(array* w, int x) {
	int i, temp = w->w[w->n - 1];

	// tyle razy ile stopien wielomianu
	for (i = w->n - 1; i > 0; i--) {
		temp = temp*x + w->w[i-1];
	}

	return temp;
}

int find_roots(array w, array* roots) {
	int i;

	roots->n = 0;

	for (i = 1; i<=w.w[0]; i++) {
		// jeśli i podzielnikiem wyrazu wolnego
		if (w.w[0] % i == 0) {
			// dla dodatniego podzielnika
			if (value(&w, i) == 0) {
				roots->n++;
				roots->w = (int*)realloc(roots->w, roots->n*sizeof(int));

				if (roots->w == NULL) {
					return 0;
				}

				roots->w[roots->n-1] = i;
			}
			// dla ujemnego podzielnika
			if (value(&w, -1*i) == 0) {
				roots->n++;
				roots->w = (int*)realloc(roots->w, roots->n*sizeof(int));

				if (roots->w == NULL) {
					return 0;
				}

				roots->w[roots->n-1] = -1*i;
			}
		}
	}

	if (roots->n == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int polyder(array w, array* w_prim) {
	int i;

	w_prim->w = (int*)malloc((w.n-1)*sizeof(int));

	if (w_prim->w == NULL) {
		return 0;
	}

	w_prim->n = w.n-1;

	for (i = 1; i < w.n; i++) {
		w_prim->w[i-1] = w.w[i]*i;
	}

	return 1;
}

int single_root(array w, int r) {
	array w_prim1 = {NULL, 0};

	polyder(w, &w_prim1);

	if (value(&w_prim1, r) != 0) {
		return 1;
	}
	else {
		return 0;
	}
}