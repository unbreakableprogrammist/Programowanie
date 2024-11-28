#include <stdio.h>

#define rozmiarTablicy 1000
// sito erastotenesa
int main()
{
    int tablica[rozmiarTablicy];
    tablica[0] = 0;
    tablica[1] = 0;
    for(int k = 2; k< rozmiarTablicy; k++)
    {
        tablica[k] = 2;
    }
    for(int i = 2; i< rozmiarTablicy; i++)
    {
        if (tablica[i]==2)
        {
            tablica[i] = 1;
            for(int j = i*i;j<rozmiarTablicy; j += i)
            {
                tablica[j] = 0;
            }
        }
    }
    for(int i = 0; i<rozmiarTablicy; i++){
        printf("liczba %d tablica: %d\n", i, tablica[i]);
    }
    return 0;
    // for(int i = 2; i< rozmiarTablicy; i++){
    //     if(tablica[i])
    // }
}