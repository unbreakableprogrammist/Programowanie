#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

//ETAP 1 (2 pkt)
void fill_partially(int C[N], int n, int value1, int n1, int value2);
void fill_random(int C[N], int n, int range);
void print(int C[N], int n);

//ETAP 2 (1 pkt)
int sum(int C[N], int n, int from, int to);

//ETAP 3 (1 pkt)
void fibonacci(int T[N], int n);

//ETAP 4 (1 pkt)
int check(int T[N], int n);

//ETAP 5 (1 pkt)
void fibonacci_deepth(int T[N], int n, int d);

//ETAP 6 (1 pkt)
void merge(int T1[N], int n1_from, int n1_to, int T2[N], int n2_from, int n2_to, int T3[N], int n3);

//-------------------------------------------------------
int main()
{
	int C1[N], C2[N], C3[N];
	int n1 = 10, n2 = 20, n3 = 0;	//odpowiednia liczba wlasciwych elementow w powy�szych tablicach

	srand((unsigned)time(NULL));

	printf("\n---------------   ETAP 1 (2 pkt)   ---------------\n");

	printf("\nCorrect run, C1: ");
	fill_partially(C1, n1, 0, 1, 1);
	print(C1, n1);
	printf("\nFill for wrong input, should print error: \n");
	fill_partially(C1, n1, 0, n1 + 1, 1);

	printf("\nFilling C2 with random, C2: ");
	fill_random(C2, n2, 10);
	print(C2, n2);

	printf("\n---------------   ETAP 2 (1 pkt)   ---------------\n");

	int result_3 = sum(C1, n1, 0, 4);
	printf("\nSum for C1 that should be 3: %d \n", result_3);
	int result_wrong = sum(C1, n1, 5, 2);
	printf("\nSum for C1 for wrong input, should print error and return 0: %d \n", result_wrong);


	printf("\n---------------   ETAP 3 (1 pkt)   ---------------\n");

	printf("\nFibonacci for C1: ");
	fibonacci(C1, n1);
	print(C1, n1);
	printf("\nFibonacci for C3: ");
	fibonacci(C3, n3);
	print(C3, n3);

	printf("\n---------------   ETAP 4 (1 pkt)   ---------------\n");

	int k = 0;
	printf("\nIs C1 fibonacci: %d ", check(C1, n1));
	printf("\nIs C2 fibonacci: %d ", check(C2, n2));
	printf("\nIs C3 fibonacci: %d \n", check(C3, n3));

	printf("\n---------------   ETAP 5 (1 pkt)   ---------------\n");

	printf("\nFibonacci for deepth 2: ");
	fibonacci_deepth(C2, n2, 2);
	print(C2, n2);

	printf("\nFibonacci for deepth 3: ");
	fibonacci_deepth(C2, n2, 3);
	print(C2, n2);

	printf("\nFibonacci for deepth 4: ");
	fibonacci_deepth(C2, n2, 4);
	print(C2, n2);

	printf("\nFibonacci for wrong input: ");
	fibonacci_deepth(C2, n2, n2 + 1);

	printf("\n---------------   ETAP 6 (1 pkt)   ---------------\n");

	printf("\nMerge elements 1-3 from C1 and 2-4 from C2\n");
	n3 = 10;
	merge(C1, 1, 3, C2, 2, 4, C3, n3);

	printf("\nC1: ");
	print(C1, n1);
	printf("\nC2: ");
	print(C2, n2);
	printf("\nC3: ");
	print(C3, n3);

	printf("\nMerge function for wrong input:");
	merge(C1, 1, 3, C2, 2, 4, C3, 0);

	printf("\n---------------   KONIEC   ---------------\n");

	return 0;
}

void fill_random(int C[N], int n, int range) {
	int i;

	// losujemy wartosci calkowite z przedzialu: [0, range-1]
	for (i = 0; i < n; i++) {
		C[i] = rand() % range;
	}

	return;
}

void fill_partially(int C[N], int n, int value1, int n1, int value2) {
	int i;

	if (n1 > n) {
		// jesli n1 jest poza zakresem C, to wypisujemy error
		
		printf("Error, wrong parameters.\n");
	}
	else {
		// uzupelniamy value1 dla indeksow do n1-1
		for (i = 0; i < n1; i++) {
			C[i] = value1;
		}
		// uzupelniamy value2 dla indeksow od n1 do n-1
		for (i = n1; i < n; i++) {
			C[i] = value2;
		}
	}

	return;
}

void print(int C[N], int n) {
	int i;

	printf("[ ");

	// drukujemy wszystkie wartosci w formacie [ x x x ]
	for (i = 0; i < n; i++) {
		printf("%d ", C[i]);
	}

	printf("]\n");

	return;
}

int sum(int C[N], int n, int from, int to) {
	int i, sum = 0;

	if (from >= to) {
		// jesli podany zly zakres, to wypisujemy error i zwracamy 0
		
		printf("\nError, wrong parameters.\n");
		return 0;
	}
	else {
		// liczymy sume elementow z zakresu o indeksach [from, to-1]
		for (i = from; i < to; i++) {
			sum += C[i];
		}
	}

	// zwracamy obliczona sume
	return sum;
}

void fibonacci(int T[N], int n) {
	int i;

	for (i = 0; i < n; i++) {
		// pierwszy element ciagu to 0
		if (i == 0) {
			T[0] = 0;
		}
		// drugi element ciagu to 1
		else if (i == 1) {
			T[1] = 1;
		}
		// kazdy kolejny wedlug wzoru: T[i] = T[i-1] + T[i-2]
		else {
			T[i] = T[i - 1] + T[i - 2];
		}
	}

	return;
}

int check(int T[N], int n) {
	int i;

	if (n <= 0) {
		// jesli dlugosc tablicy rowna 0, zwracamy -1
		
		return -1;
	}

	for (i = 0; i < n; i++) {
		// sprawdzamy czy pierwszy element ciagu to 0, inaczej zwracamy -1
		if (i == 0) {
			if (T[i] != 0) {
				return -1;
			}
		}
		// sprawdzamy czy drugi element ciagu to 1, inaczej zwracamy -1
		else if (i == 1) {
			if (T[i] != 1) {
				return -1;
			}
		}
		// sprawdzamy kazdy kolejny element czy jest czescia ciagu fibonacciego, jesli jakis nie jest to zwracamy -1
		else {
			if (T[i] != (T[i - 1] + T[i - 2])) {
				return -1;
			}
		}
	}

	// jesli wszystko bedzie okej, to zwracamy ostatni element T
	return T[i - 1];
}

void fibonacci_deepth(int T[N], int n, int d) {
	int i, j;

	if (d > n) {
		// sprawdzamy czy d nie wychodzi poza indeksy T
		
		printf("\nError, wrong parameters.\n");
	}
	else {
		for (i = 0; i < n; i++) {
			// wypelniamy poczatkowe wartosci zerami
			if (i < d - 1) {
				T[i] = 0;
			}
			// wartosc na indeksie d - 1 = 1
			else if (i == d - 1) {
				T[i] = 1;
			}
			// kazda kolejna wartosc na podstawie wzoru: T[i] = T[i-1] + T[i-2] + ... + T[i-d]
			else {
				T[i] = 0;

				for (j = 1; j <= d; j++) {
					T[i] += T[i - j];
				}
			}
		}
	}

	return;
}

void merge(int T1[N], int n1_from, int n1_to, int T2[N], int n2_from, int n2_to, int T3[N], int n3) {
	int i = 0, j;

	if ((((n1_to - n1_from + 1) + (n2_to - n2_from + 1)) > n3) || n1_from > n1_to || n2_from > n2_to) {
		// sprawdzamy czy ilosc elementow do wpisania nie jest wieksza niz ilosc miejsc w tablicy T3
		// oraz czy zakresy n1 i n2 sa poprawnie okreslone

		printf("\nError, wrong parameters.\n");
	}
	else {
		// wypelniamy tablice T3 elementami z T1
		for (j = n1_from; j <= n1_to; j++) {
			T3[i] = T1[j];
			i++;
		}
		// wypelniamy tablice T3 elementami z T2
		for (j = n2_from; j <= n2_to; j++) {
			T3[i] = T2[j];
			i++;
		}
		// wypelniamy tablice T3 wartosciami 0 jesli zostaly puste pola
		for (; i < n3; i++) {
			T3[i] = 0;
		}
	}

	return;
}