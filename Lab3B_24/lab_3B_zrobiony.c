#include <stdlib.h>
#include <stdio.h>
#include <windows.h> 

HANDLE hOut;

#define M 21 //iloœæ wierszy
#define N 21 //iloœæ kolumn
#define OPOZNIENIE 40

void setCzerwony() { SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY); } //czerwony
void setZolty() { SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); } //¯ó³ty
void setDomyslny() { SetConsoleTextAttribute(hOut, 0x0007); } //Domyœlny

void fillTable(int tab[M][N], int m, int n, int value); //0.5
void setInRow(int tab[M][N], int m, int n, int row, int q1, int v1, int q2, int v2); //1.0
void printTable(int tab[M][N], int m, int n); //1.0
void christmasTree(int tab[M][N], int m, int n, int tree[][3]); //1.0
void rectangle(int tab[M][N], int m, int n, int index); //1.5
void rightTriangle(int tab[M][N], int m, int n, int index); //1.5
void transposition(int tab[M][N], int m); //0.5

void bottomTriangle(int t[][N], int ilosc_w, int ilosc_k, int a);
void animation(int[][N], int ilosc_w, int ilosc_k, void(int[][N], int, int, int));

int main()
{
	int tab[M][N];
	int tree[][3] = { {0,10,1},{1,9,3},{2,8,5},{3,9,3},{4,7,7},{5,5,11},{6,3,15},{7,9,3},{8,7,7},{9,5,11},{10,3,15},
					 {11,1,19},{12,9,3},{13,7,7},{14,5,11},{15,3,15},{16,1,19},{17,0,21},{18,8,4},{19,8,4},{20,8,4} };
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	/********************ETAP 0*******************/
	//Zmiana koloru czcionki
	setZolty();
	printf("Kolor czcionki zolty\n");
	setDomyslny();
	printf("Kolor domyslny...\n\n\n");
	system("pause");
	system("cls");

	/********************ETAP 1*******************/

	fillTable(tab, M, N, 1);
	setInRow(tab, M, N, 5, 3, 2, 4, 0);
	printTable(tab, M, N);
	system("pause");
	system("cls");

	/********************ETAP 2*******************/

	christmasTree(tab, M, N, tree);
	printTable(tab, M, N);
	system("pause");
	system("cls");

	/********************ETAP 3*******************/

	fillTable(tab, M, N, 1);
	rectangle(tab, M, N, 0);
	printTable(tab, M, N);
	system("pause");
	system("cls");
	animation(tab, M, N, rectangle);
	system("pause");
	system("cls");

	/********************ETAP 4*******************/

	fillTable(tab, M, N, 1);
	rightTriangle(tab, M, N, 0);
	printTable(tab, M, N);
	system("pause");
	system("cls");
	animation(tab, M, N, rightTriangle);
	system("pause");
	system("cls");
	fillTable(tab, M, N, 1);
	bottomTriangle(tab, M, N, 0);
	printTable(tab, M, N);
	system("pause");
	system("cls");
	animation(tab, M, N, bottomTriangle);
	system("pause");
	system("cls");

	return 0;
}

void animation(int t[][N], int ilosc_w, int ilosc_k, void funkcja(int t[][N], int w, int k, int a))
{
	int i;
	for (i = 0; i < ilosc_w / 2 + 1; i++)
	{
		system("cls");
		fillTable(t, ilosc_w, ilosc_k, 1);
		funkcja(t, ilosc_w, ilosc_k, i);
		printTable(t, ilosc_w, ilosc_k);
		Sleep(OPOZNIENIE);
	}
	for (i = ilosc_w / 2 - 1; i >= -1; i--)
	{
		system("cls");
		fillTable(t, ilosc_w, ilosc_k, 1);
		funkcja(t, ilosc_w, ilosc_k, i);
		printTable(t, ilosc_w, ilosc_k);
		Sleep(OPOZNIENIE);
	}
}

void bottomTriangle(int t[][N], int ilosc_w, int ilosc_k, int a)
{
	rightTriangle(t, ilosc_w, ilosc_k, a);
	transposition(t, ilosc_w);
}


void fillTable(int tab[M][N], int m, int n, int value) {
	int i, j;

	// wypelniamy tablice jedna wartoscia po kolei wierszami
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			tab[i][j] = value;
		}
	}

	return;
}

void setInRow(int tab[M][N], int m, int n, int row, int q1, int v1, int q2, int v2) {
	int i;

	// ustawiamy pierwsze q1 elementow na podana wartosc v1
	for (i = 0; i < q1; i++) {
		tab[row][i] = v1;
	}
	// ustawiamy kolejne q2 elementow na podana wartosc v2
	for (; i < q1 + q2; i++) {
		tab[row][i] = v2;
	}

	return;
}

void printTable(int tab[M][N], int m, int n) {
	int i, j;

	// drukujemy wartosci po kolei wierszami
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			// jesli zero zmieniamy kolor na czerwony
			if (tab[i][j] == 0) {
				setCzerwony();
			}
			else {
				setDomyslny();
			}
			printf("%d",tab[i][j]);
		}
		printf("\n");
	}

	// resetujemy kolor na koniec
	setDomyslny();
	return;
}

void christmasTree(int tab[M][N], int m, int n, int tree[][3]) {
	int i;

	// wykorzystujac funkcje setInRow drukujemy wierszami odpowiednie ilosc zer i jedynek
	for (i = 0; i < m; i++) {
		setInRow(tab, m, n, tree[i][0], tree[i][1], 1, tree[i][2], 0);
	}

	return;
}

void rectangle(int tab[M][N], int m, int n, int index) {
	int i;

	// sprawdzamy poprawnosc indeksu
	if (index < 0 || index >= N) {
		return;
	}

	setInRow(tab, m, n, index, index, 1, n - (2*index), 0); // drukujemy gorny bok prostokata
	setInRow(tab, m, n, m - index - 1, index, 1, n - (2 * index), 0); // drukujemy dolny bok prostokata

	for (i = index; i < m - index; i++) {
		tab[i][index] = 0; // drukujemy lewy bok
		tab[i][m - index - 1] = 0; // drukujemy prawy bok
	}

	return;
}

void rightTriangle(int tab[M][N], int m, int n, int index) {
	int i, j;

	// sprawdzamy poprawnosc indeksu
	if (index < 0 || index >= N) {
		return;
	}

	// drukujemy trojkat kolumnami zaczynajac od prawej podstawy idac w strone srodka
	for (i = n - index - 1; i >= N/2; i--) {
		for (j = index; j < m - index; j++) {
			tab[j][i] = 0;
		}
		index++;
	}

	return;
}
void transposition(int tab[M][N], int m) {
	int i, j, temp;

	// zamieniamy miejscami po kolei elementy z 0 wiersza i 0 kolumny, potem z 1 wiersza i 1 kolumny etc.
	for (i = 0; i < m; i++) {
		for (j = i+1; j < m; j++) {
			temp = tab[j][i];
			tab[j][i] = tab[i][j];
			tab[i][j] = temp;
		}
	}

	return;
}