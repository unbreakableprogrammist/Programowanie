#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct tekst
{
	int ilosc_znakow;
	char* lancuch;
} tekst;

void wyswietl(char *T[], int ilosc_wierszy);
tekst* tekst_2_struktura(char *T[], int ilosc_wierszy);
void przetwarzanie_wstepne(tekst *T, char *znaki_do_usuniecia);
void male(tekst *T);
void zamiana_dwuznakow(tekst *T, char *DW, char z);

int main(void)
{
	unsigned int ilosc_wierszy = 0;
	char *do_usuniecia = ".,!@#$%^&*()-+—_?<>:;'%%\"\\/–\n";
	tekst *T_0;

	char *azazel[] = {
	"Joseph Heller - Paragraf 22",
	"_____________________________",
	"1 Teksańczyk",
	"Była to miłość od pierwszego wejrzenia.",
	"Kiedy Yossarian po raz pierwszy ujrzał kapelana, natychmiast zapałał do niego szalonym uczuciem.",
	"Yossarian leżał w szpitalu z bólami wątroby, które jakoś nie mogły się przerodzić w pospolitą",
	"żółtaczkę. Lekarzy zbijało to z tropu. Gdyby to była żółtaczka, mogliby przystąpić do leczenia.",
	"Gdyby to nie była żółtaczka i bóle ustąpiłyby same, mogliby go wypisać ze szpitala. Tymczasem fakt,",
	"że było to cały czas takie ni to, ni owo, wprawiał ich w zakłopotanie.",
	"Codziennie rano przychodziło trzech energicznych, poważnych dżentelmenów, wygadanych i krótkowzrocznych,",
	"w asyście równie energicznej i poważnej siostry Duckett, jednej z pielęgniarek,",
	"które nie lubiły Yossariana. Oglądali kartę choroby wiszącą w nogach łóżka i wypytywali go",
	"niecierpliwie o bóle. Denerwowało ich, kiedy mówił, że bóle są takie same jak dotychczas." };

	setlocale(LC_ALL, "pl_PL.UTF-8"); //polskie znaki w konsoli

	ilosc_wierszy = sizeof(azazel) / sizeof(char*);

	//Etap 1
	printf("--------------");
	printf("\n--==ETAP 1==--\n");
	printf("--------------\n\n");
	wyswietl(azazel, ilosc_wierszy);

	////Etap 2
	printf("\n--------------");
	printf("\n--==ETAP 2==--\n");
	printf("--------------");
	T_0 = tekst_2_struktura(azazel, ilosc_wierszy);
	printf("\n\n%s\n", T_0->lancuch);
	printf("\nIlość znaków: %d", T_0->ilosc_znakow);

	////Etap 3
	printf("\n\n--------------");
	printf("\n--==ETAP 3==--\n");
	printf("--------------");
	male(T_0);
	przetwarzanie_wstepne(T_0, do_usuniecia);
	printf("\n\n%s\n", T_0->lancuch);
	printf("\nIlość znaków: %d", T_0->ilosc_znakow);

	////Etap 4
	printf("\n\n--------------");
	printf("\n--==ETAP 4==--\n");
	printf("--------------");
	zamiana_dwuznakow(T_0, "rz", 'Z');
	zamiana_dwuznakow(T_0, "sz", 'S');
	zamiana_dwuznakow(T_0, "cz", 'C');
	zamiana_dwuznakow(T_0, "dz", 'D');
	zamiana_dwuznakow(T_0, "ch", 'h');
	printf("\n\n%s\n", T_0->lancuch);
	printf("\nIlość znaków: %d", T_0->ilosc_znakow);

	free(T_0);
	printf("\n\n");
	//system("pause");
	return 0;
}

void wyswietl(char *T[], int ilosc_wierszy) {
	int i;

	for (i = 0; i < ilosc_wierszy; i++) {
		printf("%s\n", T[i]);
	}

	return;
}

tekst* tekst_2_struktura(char *T[], int ilosc_wierszy) {
	int i, ilosc_znakow;
	tekst *T0 = (tekst*)malloc(sizeof(tekst));

	if (T0 == NULL) {
		return NULL;
	}

	for (i = 0; i < ilosc_wierszy; i++)
	{
		ilosc_znakow += strlen(T[i]) + 1;
	}
	ilosc_znakow--; // odejmujemy koncową spację

	T0->lancuch = (char*)malloc(sizeof(char) * (ilosc_znakow + 1)); // dodajemy 1 dla '\0'

	if (T0->lancuch == NULL) {
		return T0;
	}

	T0->ilosc_znakow = ilosc_znakow;

	for (i = 0; i < ilosc_wierszy; i++)
	{
		strcat(T0->lancuch, T[i]);
		if (i!=ilosc_wierszy-1) {
			strcat(T0->lancuch, " ");
		}
	}

	return T0;
}

void przetwarzanie_wstepne(tekst *T, char *znaki_do_usuniecia) {
	int i, j, k, temp, ilosc_usunietych = 0;

	for (i = 0; znaki_do_usuniecia[i] != '\0'; i++) {
		for (j = 0; T->lancuch[j] != '\0'; j++) {
			if (znaki_do_usuniecia[i] == T->lancuch[j]) {
				for (k = j; T->lancuch[k] != '\0'; k++) {
					T->lancuch[k] = T->lancuch[k+1];
				}
				ilosc_usunietych += 1;

				j--;
			}
		}
	}

	T->ilosc_znakow -= ilosc_usunietych;
	T->lancuch = (char*)realloc(T->lancuch, (T->ilosc_znakow) * sizeof(char));

	if (T->lancuch == NULL) {
		T->ilosc_znakow = 0;
		return;
	}

	return;
}

void male(tekst *T) {
	int i;

	for (i = 0; i < T->ilosc_znakow; i++) {
		T->lancuch[i] = tolower(T->lancuch[i]);
	}

	return;
}

void zamiana_dwuznakow(tekst *T, char *DW, char z) {
	int i, k;
	char arr[] = "  ";

	for (i = 0; i < T->ilosc_znakow-1; i++) {
		// sprawdzamy wszystkie dwuznaki po kolei
		arr[0] = T->lancuch[i];
		arr[1] = T->lancuch[i+1];

		if (strcmp(arr, DW) == 0) {
			T->lancuch[i] = z;

			for(k = i+1; T->lancuch[k] != '\0'; k++) {
				T->lancuch[k] = T->lancuch[k+1];
			}

			T->ilosc_znakow--;
			i--;
		}
	}

	T->lancuch = (char*)realloc(T->lancuch, T->ilosc_znakow * sizeof(char));

	if (T->lancuch == NULL) {
		T->ilosc_znakow = 0;
		return;
	}

	return;
}