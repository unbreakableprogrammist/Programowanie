#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void MacierzJednostkowa(int, double *);
void WypiszMacierz(int, double *);
void DodajMacierze(int, double *, double *);
double NastepnySkladnik(int, int, double *, double *, double *);
void expA(int, double, double *, double *, double *, double *);

int main(int argc, char* argv[]) {
    double eps, *A, *Wynik, *SklNp, *SklPr;
    int N, i, j;
    scanf("%d", &N);
    // N=3;
    A = (double * )malloc(N*N*sizeof(double));
    Wynik = (double * )malloc(N*N*sizeof(double));
    SklNp = (double * )malloc(N*N*sizeof(double));
    SklPr = (double * )malloc(N*N*sizeof(double));
    srand((unsigned)time(NULL));

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            *(A+i*N+j) = (rand()%10)/10.0;

    eps = 0.001;
    expA(N, eps, A, Wynik, SklNp, SklPr);
    WypiszMacierz(N, Wynik);
    free(SklPr);
    free(SklNp);
    free(A);
    free(Wynik);
    return 0;
}

void MacierzJednostkowa(int N, double A[]) {
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            A[i*N+j] = 0.0;
    for(i=0;i<N;i++)
        A[i*N+i] = 1.0;
    return;
}

void DodajMacierze(int N, double A[], double B[]) {
    int i,j;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            A[i*N+j] += B[i*N+j];
    return;
}

void WypiszMacierz(int N, double *Mat) {
    int i,j;
    for(i=0;i<N;i++) {
        printf("\n");
        for(j=0;j<N;j++)
            printf("%f\t",Mat[i*N+j]);
    }
    return;
}

double NastepnySkladnik(int N, int m, double *Nast, double *Pop, double *A) {
    int i, j, k;
    double suma, norma;
    norma = 0.0;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++) {
            suma =0.0;
            for(k=0;k<N;k++)
                suma += Pop[i*N+k]*A[k*N+j];
            suma /= m;
            Nast[i*N+j] = suma;
            if(norma<fabs(suma)) norma = suma;
        }
    return norma;
}
void expA(int N, double eps, double *A, double *Wynik, double *SklNp, double *SklPr) {
    short int m;
    double norma;
    MacierzJednostkowa(N, SklPr);
    MacierzJednostkowa(N, Wynik);
    m = 1;
    do {
        if(0x0001 & m) {
            norma = NastepnySkladnik(N,m,SklNp,SklPr,A);
            DodajMacierze(N,Wynik,SklNp);
        }
        else {
            norma = NastepnySkladnik(N,m,SklPr,SklNp,A);
            DodajMacierze(N,Wynik,SklPr);
        }
        m+=1;
    }
    while (norma >= eps);
    return;
}