#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BLANK	 177	//puste pole w krzyżówce
#define GWIAZDKA '*'


typedef struct krzyzowka {
	int m;			//liczba wierszy
	int n;			//liczba kolumn
	char* rozw;		//rozwiązana krzyzówka zapisana wierszami

	char* pusta;	//pusta krzyżówka przygotowana do rozwiązywania

	char* poziomo;	//opisy poziomo
	char* pionowo;	//opisy pionowo
} krzyzowka;

//ETAP 1
int start(krzyzowka* c, char* d, char* poziomo, char* pionowo);
void wypisz_opis(char* s);				//wypisuje opisy z podziałem na linie rozpoczynające się od *
void wypisz(krzyzowka c, int filled);	//filled: 0 (wypisz rozw) , 1 (wypisz pusta), ponadto wypisz sformatowane opisy

//ETAP 2
void opis_w_kropki(char* s, int i);		//zastępuje kropkami tekst i-go opis (gwiazdka zostaje)
										//gdy podano dobry wyraz
int szukaj_wyraz(krzyzowka c, char* wyraz); //zwraca 1 gdy znaleziono wyraz w wierszu, wpp 0

//ETAP 3
void transpozycja(krzyzowka* c);

//ETAP 4 (gotowy)
void zwolnij(krzyzowka* c);


//--------------------------------------------------------------------------------------------------
int main()
{
	char* d =    "1J1B1P1OZENEKAUREOLA1E1E1O1L1A1A2LAGERCIOTUCHNA1L1N1A2K1U1SPISAG1E1LOMOT1Z1K"
				 "RADZA1O1W2W1A1Y1DARMOZJADFOTKA2I1E1L1I1O1C1ILUZJONTARCZA1A1A1R1";
	char* poziomo = "*nie doszedl do skutku u Gogola*nad glowa swietego*piwo dolnej fermentacji"
						   "*ciotka, ciocia,...*bron drzewcowa, pika*odglos albo lanie*z rani u boku"
						   "*nic nie robi, ale apetyt ma*sweet focia, selfie*prakino*pawez";
	char* pionowo = "*wegiel olowkowy*stala w Weronie na balkonie*wydawca"
						   "*muzyka Kozidrak, Tyszkiewicz*autor podlogi z plytek*np miejski rynek"
						   "*czarny tez moze smieszyc*morska lub angielska*zlom, szmels"
						   "*najnizsze miejsce na statku*swobodny, niekompletny ubior"
					       "*dodatnia cecha*opiekun slonia";

	krzyzowka c = {11,13,NULL,NULL,NULL,NULL}; //11 - liczba wierszy; 13- liczba kolumn

	double r = 0;					//statystyka
	int liczba_wyrazow = c.m + c.n;	//liczba wyrazów w krzyżówce
	//---------------------------------------------------------------------------------------------

	if (!start(&c, d, poziomo, pionowo)) { printf("\nKONIEC");  return 0; }

	printf("\n\nROZWIAZANA KRZYZOWKA\n\n"); //tylko na początku wypisujemy kontrolnie
	wypisz(c, 1);

	printf("\n\nPUSTA KRZYZOWKA\n\n");
	wypisz(c, 0);


	printf("\n\nROZWIAZYWANIE\n");

	do
	{
		char wyraz[100] = { 0 };	//tablica do wczytywania wyrazu
		int k;

		printf("\n\nPodaj wyraz do wpisania \n(DUZYMI LITERAMI i bez polskich liter): ");
        scanf("%99s", wyraz, 100);

		if (strcmp(wyraz, "*") == 0) break;

		//szukamy wyrazu w wierszach
		k = szukaj_wyraz(c, wyraz);

		if (k == 0)
		{
			//teraz będziemy szukać wyrazu w kolumnach;
			//wykonujemy transpozycję krzyżówki i znowu szukamy wyrazu w wierszach
			transpozycja(&c);
			k = szukaj_wyraz(c, wyraz);
			transpozycja(&c);
		}

		wypisz(c, 0);
		r += k;

	} while (1);

	zwolnij(&c);

	printf("\n-------------------------------------");
	r /= liczba_wyrazow;
	r *= 100;
	printf("\nProcent=%.2lf%%\n",r);   //statystyka rozwiązania (ile procent ?)
	printf("\n-------------------------------------");


	printf("\n\n*** WESOLYCH SWIAT !!! ***\n\n");
	return 0;
}

//---------------------------------------------------
//poniżej zaimplementuj wymagane funkcje

//----------------------------------------------------------
void zwolnij(krzyzowka* c)	//gotowa
{
	free(c->rozw);
	free(c->pusta);
	free(c->poziomo);
	free(c->pionowo);
	c->rozw = c->pusta = c->poziomo = c->pionowo = NULL;
	c->m = c->n = 0;
}
//-----------------------------------------------------------

int start(krzyzowka* c, char* d, char* poziomo, char* pionowo) {
	int i, j, k, ilosc_znakow;

	// ------------ poziomo ------------
	c->poziomo = (char*)malloc(strlen(poziomo) * sizeof(char));

	if (c->poziomo == NULL) {
		return 0;
	}

	strcpy(c->poziomo, poziomo);

	// ------------- pionowo -------------
	c->pionowo = (char*)malloc(strlen(pionowo) * sizeof(char));

	if (c->pionowo == NULL) {
		return 0;
	}

	strcpy(c->pionowo, pionowo);

	// ---------------- rozw i pusta ---------------
	// liczymy ile potrzebujemy miejsca
	for (i = 0; d[i] != '\0'; i++) {
		if (isalpha(d[i])) {
			ilosc_znakow++;
		} else if(isdigit(d[i])) {
			ilosc_znakow += (d[i] - '0');
		}
	}

	c->rozw = (char*)malloc(sizeof(char) * ilosc_znakow);
	c->pusta = (char*)malloc(sizeof(char) * ilosc_znakow);

	if (c->rozw == NULL || c->pusta == NULL) {
		// jeśli alokacja się nie powiedzie zwraca 0
		return 0;
	}

	for (i = 0, j = 0; d[i] != '\0'; i++) {
		if (isalpha(d[i])) {
			c->rozw[j] = d[i];
			c->pusta[j] = '*';
			j++;
		} else if (isdigit(d[i])) {
			for (k = 0; k < (d[i] - '0'); k++) {
				c->rozw[j] = ' ';
				c->pusta[j] = ' ';
				j++;
			}
		}
	}

	return 1;
}

void wypisz_opis(char* s) {
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != '*') {
			printf("%c", s[i]);
		} else {
			printf("\n*");
		}
	}

	return;
}

void wypisz(krzyzowka c, int filled) {
	int i,j;

	for (i = 0; i < c.m; i++) {
		for (j = 0; j < c.n; j++) {
			if (filled) {
				if (c.rozw[i*c.n + j] == ' ') {
					printf("%c", BLANK);
				} else {
					printf("%c", c.rozw[i*c.n + j]);
				}
			} else {
				if (c.pusta[i*c.n + j] == ' ') {
					printf("%c", BLANK);
				} else {
					printf("%c", c.pusta[i*c.n + j]);
				}
			}
		}
		printf("\n");
	}

	printf("\nPOZIOMO");
	wypisz_opis(c.poziomo);
	printf("\nPIONOWO");
	wypisz_opis(c.pionowo);

	return;
}

int szukaj_wyraz(krzyzowka c, char* wyraz) {
	int i, j, indeks;
	char* znaleziony;

	// szukanie poziomych wyrazów:
	znaleziony = strstr(c.rozw, wyraz);

	if (znaleziony != NULL) {
		indeks = znaleziony - c.rozw;

		for (i = indeks, j = 0; wyraz[j] != '\0'; j++, i++) {
			c.pusta[i] = wyraz[j];
		}

		indeks = indeks/c.n;
		opis_w_kropki(c.poziomo, indeks);

		return 1;
	}

	return 0;
}

void opis_w_kropki(char* s, int i) {
	int j, licznik = 0;

	for (j = 0; s[j] != '\0'; j++) {
		if (s[j] == '*') {
			licznik++;
		}
		if (licznik == i+1) {
			break;
		}
	}

	for (j++; s[j] != '*' && s[j] != '\0'; j++) {
		s[j] = '.';
	}

	return;
}

void transpozycja(krzyzowka* c) {
	char* temp_rozw;
	char* temp_pusta;
	char* temp_opis;
	int i,j, temp;

	temp_rozw = (char*)malloc(strlen(c->rozw) * sizeof(char));
	temp_pusta = (char*)malloc(strlen(c->pusta) * sizeof(char));
	temp_opis = (char*)malloc(strlen(c->pionowo) * sizeof(char));

	if (temp_rozw == NULL || temp_pusta == NULL || temp_opis == NULL) {
		printf("Błąd alokacji pamięci");
		return;
	}

	// -------- zamiana pionowo i poziomo --------
	strcpy(temp_opis, c->pionowo);
	c->pionowo = (char*)realloc(c->pionowo, strlen(c->poziomo) * sizeof(char));
	if (c->pionowo == NULL) {
		printf("Błąd alokacji pamięci");
		return;
	}

	strcpy(c->pionowo, c->poziomo);
	c->poziomo = (char*)realloc(c->poziomo, strlen(temp_opis) * sizeof(char));
	if (c->poziomo == NULL) {
		printf("Błąd alokacji pamięci");
		return;
	}

	strcpy(c->poziomo, temp_opis);
	free(temp_opis);

	// -------- transpozycja rozw i pusta -------------
	for (i = 0; i < c->n; i++) {
		for (j = 0; j < c->m; j++) {
			temp_rozw[i*c->m + j] = c->rozw[j*c->n + i];
			temp_pusta[i*c->m + j] = c->pusta[j*c->n + i];
		}
	}

	temp = c->m;
	c->m = c->n;
	c->n = temp;

	strcpy(c->rozw, temp_rozw);
	strcpy(c->pusta, temp_pusta);

	free(temp_rozw);
	free(temp_pusta);

	return;
}