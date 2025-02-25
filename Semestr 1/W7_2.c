#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 7


int main(int argc, char *argv[]) 
{
    int i, j, ind[M], imax, imin;
    int p;
    int m[M][N];
    int v[M];
    int vmax, vmin;
    srand((unsigned)time(NULL));

    for (i = 0; i< M; i++)
    {
        for (j=0; j<N; j++)
        {
            m[i][j] = rand() %20;
        }
    }
    for (i = 0; i< M; i++)
    {
        for (j=0; j<N; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
        
        

    for(i=0; i<M; i++)
    {
        v[i] = m[i][0];
        ind[i] = 0;
        for(j=1;j<N;j++)
        {
            if (v[i] < m[i][j])
            {
                v[i] = m[i][j];
                ind[i]=j;
            }
        
        }
    }
    vmin = v[0];
    imin = 0;
    for (i= 1; i < M; i++)
    {
        if(vmin > v[i])
        {
            vmin = v[i];
            imin = i;
        }
    }
    vmax = v[0];
    imax = 0;
    for (i= 1; i < M; i++)
    {
        if(vmax < v[i])
        {
            vmax = v[i];
            imax = i;
        }
    }
    for (j = 0; j<N; j++)
    {
        p = m[imax][j];
        m[imax][j] = m[imin][j];
        m[imin][j]= p;
    }
    printf("\n");
    for (i = 0; i< M; i++)
    {
        for (j=0; j<N; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}