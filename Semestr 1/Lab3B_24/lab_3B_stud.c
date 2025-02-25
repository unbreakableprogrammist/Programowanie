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

void fillTable(/*...*/); //0.5
void setInRow(/*...*/); //1.0
void printTable(/*...*/); //1.0
void christmasTree(/*...*/); //1.0
void rectangle(/*...*/); //1.5
void rightTriangle(/*...*/); //1.5
void transposition(/*...*/); //0.5

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
/*
	fillTable(tab, M, N, 1);
	setInRow(tab, M, N, 5, 3, 2, 4, 0);
	printTable(tab, M, N);
	system("pause");
	system("cls");
*/
	/********************ETAP 2*******************/
/*
	christmasTree(tab, M, N, tree);
	printTable(tab, M, N);
	system("pause");
	system("cls");
*/
	/********************ETAP 3*******************/
/*
	fillTable(tab, M, N, 1);
	rectangle(tab, M, N, 0);
	printTable(tab, M, N);
	system("pause");
	system("cls");
	animation(tab, M, N, rectangle);
	system("pause");
	system("cls");
*/
	/********************ETAP 4*******************/
/*
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
*/
	return 0;
}

/*
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
*/

/*
void bottomTriangle(int t[][N], int ilosc_w, int ilosc_k, int a)
{
	rightTriangle(t, ilosc_w, ilosc_k, a);
	transposition(t, ilosc_w);
}
*/