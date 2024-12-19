#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//#include <windows.h>

#define z0 '-'  
#define z1 '|'  
#define z2 ' '
#define z3 '>'
#define z4 '^'
#define z5 0xFE

enum kolory { CZERWONY_B, CZARNY_B, TLO, STANDARD };

void ustawKolor(int k)
{
	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	// switch (k)
	// {
	// 	case CZERWONY_B:SetConsoleTextAttribute(h, 0x00FC); break;  //czerwony na białym tle
	// 	case CZARNY_B:  SetConsoleTextAttribute(h, 0x00F0); break;  //czarny na białym tle
	// 	case TLO:       SetConsoleTextAttribute(h, 0x00FF); break;  //biały na białym tle
	// 	case STANDARD:  SetConsoleTextAttribute(h, 0x0007); break;	//domyślny (jasny szary na czarnym tle)
	// }
}

typedef struct el {
	char z;			//znak wpisywany w tablicę
	int  kolor;		//kolory: CZERWONY_B, CZARNY_B, TLO, STANDARD
} el;

typedef struct tab {
	el** t;	// dynamiczna tablica 2-wymiarowa
	int w;	// wymiary: w wierszy, k kolumn 
	int k;
} tab;


//1 - 4p
tab init(int w, int k); //1,5p
void tlo(tab p); //0,5p
void uklad_wspolrzednych(tab p); //1p
void wypisz(tab p); //0,5p
void zwolnij_tab(tab p); //0,5p
//2 - 2p
int *wartosci_F1(int k); //1p
void wpisz_funkcje(tab p, int *f); //1p
void zwolnij_f(int* f); //0p
//3 - 1p
int obrot_90(tab* p); //1p

int F1(int);

int main()
{
	tab T; 
	int w, k, i;
	int *f1;

	w = 15;
	k = 21;

	/*__________________ETAP 1__________________*/
	T = init(w, k);
	if (!(T.t)) return 1;
	tlo(T);
	uklad_wspolrzednych(T);
	wypisz(T);
	//system("pause");
	/*__________________ETAP 2__________________*/
	//system("cls");
	f1 = wartosci_F1(k);
	wpisz_funkcje(T, f1);
	wypisz(T);
	zwolnij_f(f1);
	//system("pause");

	/*__________________ETAP 3__________________*/
	//system("cls");
	obrot_90(&T);
	wypisz(T);
	//system("pause");

	/*__________________DODATEK_________________*/
/*	system("cls");
	tab T1 = init(15, 15);
	f1 = wartosci_F1(15);
	wpisz_funkcje(T1, f1);
	tab T2 = init(15, 15);
	COORD c = { 0, 0 };
	for (i = 0; i < 32; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		tlo(T2);
		uklad_wspolrzednych(T2);
		wypisz(T2);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		obrot_90(&T1);
		wypisz(T1);
	}
	zwolnij_tab(T1);
	zwolnij_tab(T2);
*/
	/*__________________________________________*/
	zwolnij_tab(T);
	//system("pause");
	return 0;
}

int F1(int x)
{
	return abs(x);
}

tab init(int w, int k) {
	int i;
	tab tab;

	tab.t = (el**)malloc(w*sizeof(el*));

	if (tab.t == NULL) {
		return tab;
	}

	for (i = 0; i < k; i++) {
		tab.t[i] = (el*)malloc(k*sizeof(el));

		if (tab.t[i] == NULL) {
			tab.t = NULL;
			return tab;
		}
	}

	tab.w = w;
	tab.k = k;

	return tab;
}

void tlo(tab p) {
	int i,j;

	el znak;
	znak.z = z2;
	znak.kolor = TLO;

	for (i = 0; i < p.w; i++) {
		for (j = 0; j < p.k; j++) {
			p.t[i][j] = znak;
		}
	}

	return;
}

void wypisz(tab p) {
	int i,j;

	printf("\n");
	for (i = 0; i < p.w; i++) {
		for (j = 0; j < p.k; j++) {
			ustawKolor(p.t[i][j].kolor);
			printf("%c", p.t[i][j].z);
		}
		printf("\n");
	}

	ustawKolor(STANDARD);

	return;
}

void uklad_wspolrzednych(tab p) {
	int i,j;
	el kreska, strzalka_gora, strzalka_prawo, myslnik;

	myslnik.z = z0;
	kreska.z = z1;
	strzalka_prawo.z = z3;
	strzalka_gora.z = z4;

	myslnik.kolor = CZARNY_B;
	kreska.kolor = CZARNY_B;
	strzalka_gora.kolor = CZARNY_B;
	strzalka_prawo.kolor = CZARNY_B;

	p.t[0][p.k/2] = strzalka_gora;
	for (i = 1; i < p.w; i++) {
		p.t[i][p.k/2] = kreska;
	}

	p.t[p.w/2][p.k-1] = strzalka_prawo;
	for (i = 0; i < p.k-1; i++) {
		p.t[p.w/2][i] = myslnik;
	}

	return;
}

void zwolnij_tab(tab p) {
	int i;

	for (i = 0; i < p.k; i++) {
		free(p.t[i]);
	}

	free(p.t);

	return;
}

int* wartosci_F1(int k) {
	int min = -1*(k/2);
	int max = k/2;
	int* t;
	int i, j;

	t = (int*)malloc((max-min+1) * sizeof(int));

	if (t == NULL) {
		return NULL;
	}

	for (i = min, j = 0; i <= max; i++, j++) {
		t[j] = F1(i);
	}

	return t;
}

void wpisz_funkcje(tab p, int* f) {
	int i, w_index;
	el znak;

	znak.z = z5;
	znak.kolor = CZERWONY_B;

	for (i = 0; i < p.k; i++) {
		w_index = p.w/2 - f[i];

		if (w_index >= 0) {
			p.t[w_index][i] = znak;
		}
	}

	return;
}

void zwolnij_f(int* f) {
	free(f);
}

int obrot_90(tab* p) {

}
