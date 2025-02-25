#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 17

typedef struct karta {
	char* nazwa;
	struct karta* nast;
} karta;

typedef struct gracz {
	karta* glowa;
	karta* ogon;
} gracz;

//-----------------------------------------------------
//ETAP1 - 2pkt
karta* tworz_karte(char* nazwa);
int wstaw(gracz* g, karta* k); //na koniec
int init(gracz* g, char* karty_startowe[N]); //gotowa
void wypisz(gracz g);
void zwolnij(gracz* g);

//ETAP2 - 1,5pkt
void tasuj(gracz* g);
void rozdaj(gracz* karty, gracz* g1, gracz* g2);

//ETAP3 - 1,5pkt
void usuwaj_pary(gracz* g);

//ETAP4 - 2pkt
void usuwaj_karte(gracz* g, char* nazwa);
void wyciagnij_karte(gracz* g1, gracz* g2);

//----------------------------
int gra(gracz* g1, gracz* g2); //gotowa

//-----------------------------------------------------
int main()
{
	char* karty_startowe[N] = { "zyrafa","papuga","lew","kot","pies","tygrys","pantera","motyl","goryl",
								"puchacz","krokodyl","kaczka","szczur","mysz","bocian","krecik","piotrek" };

	gracz talia = { NULL,NULL }, g1 = { NULL,NULL }, g2 = { NULL,NULL };


	printf("\nETAP1------------------------------------------------\n");
	printf("\nKARTY:\n");
	if(!init(&talia,karty_startowe))
	{
		printf("\nNie ma kart do grania !!!\n");
		zwolnij(&talia);
		return 1;
	}
	wypisz(talia);

	printf("\nETAP2------------------------------------------------\n");
	//srand(1642611350);
	srand((unsigned)time(NULL));

	printf("\nPOTASOWANE:\n");
	tasuj(&talia);
	tasuj(&talia);	//ETAP3: zakomentuj, żeby nie było par u gracza
	wypisz(talia);

	rozdaj(&talia, &g1, &g2);
	printf("\nKARTY G1\n");
	wypisz(g1);
	printf("\nKARTY G2\n");
	wypisz(g2);

	printf("\nETAP3------------------------------------------------\n");
	usuwaj_pary(&g1);
	printf("\nKARTY G1 ( po USUWANIU par )\n");
	wypisz(g1);
	usuwaj_pary(&g2);
	printf("\nKARTY G2 ( po USUWANIU par )\n");
	wypisz(g2);

	printf("\nETAP4------------------------------------------------\n");
	//gra
	if (gra(&g1, &g2))
		printf("\nWygrywa G1 !!!\n");
	else
		printf("\nWygrywa G2 !!!\n");

	zwolnij(&talia);
	zwolnij(&g1);
	zwolnij(&g2);

	return 0;
}

//IMPLEMENTACJE
//----------------------------------------------
karta* tworz_karte(char* nazwa)
{
	// tworzymy nową kartę
	karta* nowa_karta;
	// alokujemy na nią pamięć
	nowa_karta = (karta*)malloc(sizeof(karta));

	// jeśli się nie uda zwraca NULL
	if (nowa_karta == NULL) {
		return NULL;
	}

	// alokujemy pamięć na nazwę, długość + 1 dla '\0'
	nowa_karta->nazwa = (char*)malloc((strlen(nazwa)+1)*sizeof(char));

	// jeśli się nie uda zwraca NULL
	if (nowa_karta->nazwa == NULL) {
		return NULL;
	}

	// kopiujemy nazwę do karty
	strcpy(nowa_karta->nazwa, nazwa);

	// na starcie karta nie wskazuje na nic dalej
	nowa_karta->nast = NULL;

	// jeśli wszystko git, zwracamy utworzona kartę
	return nowa_karta;
}
//----------------------------------------------
int wstaw(gracz* g, karta* k) //na koniec
{
	// jesli karta nie istnieje to zwracamy błąd
	if (k == NULL) {
		return 0;
	}

	// jesli struktura gracza jest pusta to wstawiamy pierwszą kartę na początek
	// glowa i ogon to ta sama karta bo jest tylko jedna
	if (g->glowa == NULL) {
		g->glowa = k;
		g->ogon = k;
	}
	// w przeciwnym wypadku wstawiamy na koniec
	else {
		(g->ogon)->nast = k;
		g->ogon = k;
		// upewniamy się, że ogon jest ostatnią kartą
		(g->ogon)->nast = NULL;
	}

	return 1;
}
//----------------------------------------------
int init(gracz* g, char* karty_startowe[N])  //gotowa
{
	// inicjalizujemy talie kart
	for (int i = 0; i < N - 1; i++)
	{
		// wstawiamy karty parami
		if (!wstaw(g, tworz_karte(karty_startowe[i]))) return 0;
		if (!wstaw(g, tworz_karte(karty_startowe[i]))) return 0;
	}

	//ostatnia karta pojedyncza (piotrek)
	if (!wstaw(g, tworz_karte(karty_startowe[N - 1]))) return 0;

	// jesli wszystko git, zwracamy 1
	return 1;
}
//------------------------------------------------
void wypisz(gracz g)
{
	// bierzemy pierwsza kartę
	karta* k = g.glowa;

	// drukujemy aż dojdziemy do końca listy
	while(k) {
		printf("%s ", k->nazwa);
		k = k->nast;
	}
	printf("\n");

	return;
}
//-----------------------------------------------
void zwolnij(gracz* g)
{
	// zaczynamy od pierwszej karty
	karta* i = g->glowa;

	while(i) {
		// zapisujemy kolejny element
		g->glowa = (g->glowa)->nast;

		// zwalniamy pamięć dla nazwy i karty
		free(i->nazwa);
		free(i);

		// bierzemy kolejną kartę
		i = g->glowa;
	}

	// resetujemy pointery gracza
	g->glowa = NULL;
	g->ogon = NULL;

	return;
}
//-----------------------------------------------
void tasuj(gracz* g)
{
	int j; // do losowania
	karta* i = g->glowa;
	karta* prev = g->glowa;

	// glowa pozostaje na początku, więc zaczynamy od kolejnego elementu
	if (i != NULL) {
		i = i->nast;
	}
	// jesli glowa pusta, to koniec
	else {
		return;
	}

	// lecimy po elementach do końca listy
	while(i) {
		j = rand()%8;

		switch (j) {
			case 1:
			case 2:
			case 3:
				prev->nast = i->nast;
				i->nast = g->glowa;
				g->glowa = i;

				// jesli przestawiamy ostatni element to zmieniamy ogon
				if (i->nast == NULL) {
					g->ogon = prev;
				}

				i = prev->nast;
				break;
			case 0:
			case 4:
			case 5:
			case 6:
			case 7:
				// przesuwamy sie do kolejnej karty
				prev = i;
				i = i->nast;
				break;
		}
	}

	return;
}
//------------------------------------------------
void rozdaj(gracz* talia, gracz* g1, gracz* g2)
{
	karta* i = talia->glowa; // zaczynamy od poczatku talii
	karta* tmp;
	int n = 1; // pomocnicza do dodawania na przemian

	while (i) {
		// zapamietujemy kolejny element
		tmp = i->nast;

		// dodajemy karte na koniec, wiec upewniamy się, że na nic nie wskazuje
		i->nast = NULL;

		// wstawiamy na przemian
		if (n % 2 == 1) {
			wstaw(g1, i);
		} else {
			wstaw(g2, i);
		}

		// nastepny element
		i = tmp;
		n++;
	}

	// resetujemy wskazniki talii, bo przenieslismy karty do g1 i g2
	talia->glowa = NULL;
	talia->ogon = NULL;

	return;
}
//--------------------------------------------------
void usuwaj_pary(gracz* g)
{
	karta* value = g->glowa; // szukana wartosc do sprawdzania
	karta *i, *prev_i; // tym bedziemy sie poruszac po liscie i porównywać
	karta* prev_value = NULL; // do usuwania value

	// jesli pusta lista - koniec
	if (value == NULL) {
		return;
	}

	// bedziemy sprawdzac wartosci po kolei czy wystepują w dalszej części
	while(value) {
		// zaczynamy sprawdzanie od nastepnej wartosci
		i = value->nast;
		prev_i = value;

		while(i) {
			// jesli takie same to usuwamy
			if (strcmp(value->nazwa, i->nazwa) == 0) {
				// usuwamy i
				prev_i->nast = i->nast;

				// jesli i jest na koncu to zmieniamy ogon
				if (i->nast == NULL) {
					g->ogon = prev_i;
				}

				// usuwamy value
				// jesli value jest na poczatku listy to zmieniamy glowe
				if (prev_value == NULL) {
					g->glowa = value->nast;
				}
				// jesli value jest w środku listy to po prostu usuwamy
				else {
					prev_value->nast = value->nast;
				}

				// zwalniamy pamięć usuniętych kart
				free(i->nazwa);
				free(i);
				free(value->nazwa);
				free(value);
				// resetujemy pointery
				value = NULL;
				i = NULL;
			}
			// jesli różne nazwy to idziemy dalej
			else {
				prev_i = i;
				i = i->nast;
			}
		}

		// jesli value NULL to znaczy, że została usunięta
		if (value == NULL) {
			// jesli usunieta z początku to zaczynamy znowu od początku
			if (prev_value == NULL) {
				value = g->glowa;
			}
			// jeśli usunięta ze środka to od kolejnej wartości
			else {
				value = prev_value->nast;
			}
		}
		// jesli nie jest NULL, to nie została znaleziona druga taka sama i idziemy dalej
		else {
			prev_value = value;
			value = value->nast;
		}
	}

	return;
}
//--------------------------------------------------
void usuwaj_karte(gracz* g, char* nazwa)	//usuwaj 1 karte o podanej nazwie
{
	karta* i = g->glowa;
	karta* prev_i = NULL;

	// jesli g - pusta
	if (i == NULL) {
		return;
	}

	while (i) {
		// jesli wystepuje to usuwamy
		if (strcmp(i->nazwa, nazwa) == 0) {
			// jesli na początku to zmianiamy głowę
			if (prev_i == NULL) {
				g->glowa = i->nast;

				// sprawdzamy czy nie na koncu i zmieniamy ogon
				if (i->nast == NULL) {
					g->ogon = NULL;
				}

				free(i->nazwa);
				free(i);
				i = g->glowa;
			}
			// jesli w środku to usuwamy po prostu
			else {
				prev_i->nast = i->nast;

				// sprawdzamy czy nie na koncu i zmieniamy ogon
				if (i->nast == NULL) {
					g->ogon = prev_i;;
				}

				free(i->nazwa);
				free(i);
				i = prev_i->nast;
			}
		}
		// jesli nie to idziemy dalej
		else {
			prev_i = i;
			i = i->nast;
		}
	}

	return;
}
//--------------------------------------------------
void wyciagnij_karte(gracz* g1, gracz* g2)
{
	karta* k = g2->glowa; // wylosowana karta
	char* p = "piotrek"; // do porównania

	printf("\n- wyciagnieto: %s", k->nazwa);

	// jeśli piotrek to usuwamy z g2 i wstawiamy do g1
	if (strcmp(k->nazwa, p) == 0) {
		g2->glowa = k->nast;
		wstaw(g1, k);
	}
	// jesli nie piotrek to usuwamy z g1 i g2
	else {
		usuwaj_karte(g1, k->nazwa);
		usuwaj_karte(g2, k->nazwa);
	}

	return;
}
//---------------------------------------------------
int gra(gracz* g1, gracz* g2) //gotowa
{
	int gra_g1=1;
	int starcie = 1;

	// aż nie zostanie ktoś z Piotrkiem (czyli ktoś nie ma już kart) - ciągnij na zmianę
		while(g1->glowa && g2->glowa)
		{
			printf("\nSTARCIE %d", starcie++);
			//if (starcie > 100) break;

			if (gra_g1)
			{
				wyciagnij_karte(g1,g2);		//G1 bierze kartę od G2
				gra_g1 = 0;
			}
			else
			{
				wyciagnij_karte(g2,g1);		//G2 bierze kartę od G1
				gra_g1 = 1;
			}

			// wyświetl karty
			printf("\nkarty G1: ");
			wypisz(*g1);
			printf("\nkarty G2: ");
			wypisz(*g2);
		}

	if (g1->glowa) return 0;

	return 1;

}
//----------------------------------------------------











