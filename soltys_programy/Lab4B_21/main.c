#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct array
{
	int *w;		//dynamiczna tablica n elementów
	int n;		//liczba elementów tablicy dynamicznej
				//jeśli tablica przechowuje wsp. dla wielomianu, to w[n-1] - wsp. przy najwyższej potędze, w[0]-wyraz wolny
} array;


//----------------------------------------------------------------------
//ETAP 1
void print(array);
int polynomial_generator(array*, int st, int a, int b);
int multiplication(array , array , array* );

//ETAP 2
//int value(array* , int );
//int find_roots(array , array* );

//ETAP 3
//int polyder(array w, array* w_prim);
//int single_root(array w, int i);

//----------------------------------------------------------------------
int main()
{
	array roots = { NULL, 0};		//tablica całkowitych pierwiastków wielomianu
	array w1 = { NULL, 0 };		//tablica wsp. wielomianu w bazie potęgowej
										//w[n] - wsp. przy najwyższej potędze, w[0]-wyraz wolny
	array w2 = { NULL, 0 };
	array w3 = { NULL, 0 };

	int i;

	printf("\nETAP1-----------------------------------------------------------------\n");

	//srand((unsigned)time(NULL));

	srand(1640635484);
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

	// if (!multiplication( w1, w2, &w3))
	// {
	// 	printf("NIE zdefiniowano wsp. wielomianu w3!\n");
	// 	free(w1.w);
	// 	free(w2.w);
	// 	return 1;
	// }
	//
	// printf("Wsp. wielomianu w3=w1*w2 w bazie potegowej:\n");
	// print(w3);


	printf("\n\nETAP2-----------------------------------------------------------------\n");

	// if (!find_roots(w3, &roots))
	// {
	// 	printf("NIE znaleziono pierwiastkow calkowitych dla wielomianu w3!\n");
	// 	free(w1.w);
	// 	free(w2.w);
	// 	free(w3.w);
	// 	return 1;
	// }
	//
	// printf("\nZnaleziona lista calkowitych pierwiastkow dla w3");
	// print(roots);
	//
	// printf("\nSprawdzenie, czy to zera wielomianu?");
	// for (i = 0; i < roots.n; i++)
	// 	printf("\ndla x=r%d=%2d w(x)=%2d", i,roots.w[i], value(&w3, roots.w[i]));



	printf("\n\nETAP3-----------------------------------------------------------------\n");


	// printf("Wsp. pochodnej wielomianu:\n");
	//
	// //pokaż, jak wywołać polyder oraz print, dla pokazania obliczonych wsp. pochodnej wielomianu w3
	//
	// printf("\nCzy pojedyncze zero wielomianu? - przez sprawdzenie wartosci pochodnej:\n");
	//
	// for (i = 0; i < roots.n; i++)
	// 	if (single_root(w3, roots.w[i]))
	// 		printf("\n zero pojedyncze: r%d=%3d", i, roots.w[i]);
	//


	//------------------------------------------------------------------------
	free(w1.w);
	free(w2.w);
	free(w3.w);
	free(roots.w);
	//free(w_prim.w);

	printf("\n\nKONIEC\n");

	return 0;
}


//poniżej IMPLEMENTACJE FUNKCJI
//----------------------------------------------------------------------

void print(array) {

}

int polynomial_generator(array*, int st, int a, int b) {
	int *w = array->w;

}