/* Para un digrafo dado, desarrollar un programa que genere la matriz de alcance R a partir de la
matriz A resultante del algoritmo de Floyd. */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

void cargaMatrizFloyd(int A[][DIM], int *N){
    int i, j;
    FILE *arch;
    arch = fopen("matrizFloyd.txt", "rt");
    fscanf(arch, "%d", N);
    for(i = 0; i < *N; i++)
        for(j = 0; j < *N; j++)
            fscanf(arch, "%d", &A[i][j]);
    fclose(arch);
}


void generaMatrizAlcance(int A[][DIM], int N, int matAlc[][DIM]){
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(A[i][j] != 9999)
                matAlc[i][j] = 1;
            else
                matAlc[i][j] = 0;
}


int main()
{
    int A[DIM][DIM], matAlc[DIM][DIM];
    int N;
    cargaMatrizFloyd(A, &N);
    generaMatrizAlcance(A, N, matAlc);
    return 0;
}

