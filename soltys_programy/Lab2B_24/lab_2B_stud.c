#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

//ETAP 1 (2 pkt)
void fill_partially(/* uzupelnij parametry*/);
void fill_random(/* uzupelnij parametry*/);
void print(/* uzupelnij parametry*/);

//ETAP 2 (1 pkt)
int sum(/* uzupelnij parametry*/);

//ETAP 3 (1 pkt)
void fibonacci(/* uzupelnij parametry*/);

//ETAP 4 (1 pkt)
int check(/* uzupelnij parametry*/);

//ETAP 5 (1 pkt)
void fibonacci_deepth(/* uzupelnij parametry*/);

//ETAP 6 (1 pkt)
void merge(/* uzupelnij parametry*/);

//-------------------------------------------------------
int main()
{
	int C1[N], C2[N], C3[N];
	int n1 = 10, n2 = 20, n3 = 0;	//odpowiednia liczba wlasciwych elementow w powy�szych tablicach


	srand((unsigned)time(NULL));

	printf("\n---------------   ETAP 1 (2 pkt)   ---------------\n");

	// printf("\nCorrect run, C1: ");
	// fill_partially(C1, n1, 0, 1, 1);
	// print(C1, n1);
	// printf("\nFill for wrong input, should print error: \n");
	// fill_partially(C1, n1, 0, n1 + 1, 1);

	// printf("\nFilling C2 with random, C2: ");
	// fill_random(C2, n2, 10);
	// print(C2, n2);

	printf("\n---------------   ETAP 2 (1 pkt)   ---------------\n");

	// int result_3 = sum(C1, n1, 0, 4);
	// printf("\nSum for C1 that should be 3: %d \n", result_3);
	// int result_wrong = sum(C1, n1, 5, 2);
	// printf("\nSum for C1 for wrong input, should print error and return 0: %d ", result_wrong);


	printf("\n---------------   ETAP 3 (1 pkt)   ---------------\n");

	// printf("\nFibonacci for C1: ");
	// fibonacci(C1, n1);
	// print(C1, n1);
	// printf("\nFibonacci for C3: ");
	// fibonacci(C3, n3);
	// print(C3, n3);

	printf("\n---------------   ETAP 4 (1 pkt)   ---------------\n");

	// int k = 0;
	// printf("\nIs C1 fibonacci: %d ", check(C1, n1));
	// printf("\nIs C2 fibonacci: %d ", check(C2, n2));
	// printf("\nIs C3 fibonacci: %d ", check(C3, n3));
	printf("\n---------------   ETAP 5 (1 pkt)   ---------------\n");

	// printf("\nFibonacci for deepth 2: ");
	// fibonacci_deepth(C2, n2, 2);
	// print(C2, n2);

	// printf("\nFibonacci for deepth 3: ");
	// fibonacci_deepth(C2, n2, 3);
	// print(C2, n2);

	// printf("\nFibonacci for deepth 4: ");
	// fibonacci_deepth(C2, n2, 4);
	// print(C2, n2);

	// printf("\nFibonacci for wrong input: ");
	// fibonacci_deepth(C2, n2, n2 + 1);

	printf("\n---------------   ETAP 6 (1 pkt)   ---------------\n");

	// printf("\nMerge elements 1-3 from C1 and 2-4 from C2");
	// n3 = 10;
	// merge(C1, 1, 3, C2, 2, 4, C3, n3);

	// printf("\nC1: ");
	// print(C1, n1);
	// printf("\nC2: ");
	// print(C2, n2);
	// printf("\nC3: ");
	// print(C3, n3);

	// printf("\nMerge function for wrong input:");
	// merge(C1, 1, 3, C2, 2, 4, C3, 0);

	printf("\n---------------   KONIEC   ---------------\n");

	return 0;
}
