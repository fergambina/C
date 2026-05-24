/*Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente. */

#include <stdio.h>
#include <stdlib.h>
#include DIM 30

void cargaMatrizAdyDigrafo(int matAdy[][DIM], int *N);

int main()
{
    int matAdy[DIM][DIM];
    return 0;
}

void cargaMatrizAdyDigrafo(int matAdy[][DIM], int *N){
    FILE *arch;
    arch = fopen("digrafo.txt", "rt");
    fscanf(arch, "%d", N);
    for(i = 0; i < *N; i++)
        for(j = 0; j < *N; j++)
            fscanf(arch, "%d", mat[i][j]);
    fclose(arch);
}

void grafo_subyacente(int matAdy[][DIM], int N){
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(matAdy[i][j] == 1 && matAdy[j][i] != 1)
                matAdy[j][i] = 1;
}

void mostrar_matAdy(int matAdy[][DIM], int N){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            printf("%d\t", matAdy[i][j]);
        printf("\n");
    }
}
