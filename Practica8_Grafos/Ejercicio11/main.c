/* Para un grafo almacenado en una matriz de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad
b) mostrar todos sus vértices mediante recorrido en amplitud
c) devolver la cantidad de componentes conexas */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"
#define DIM 30

void cargaMatrizAdyGrafo(int matAdy[][DIM], int *N);
void recorridoProfundidad(int matAdy[][DIM], int N);

int main()
{
    int matAdy[DIM][DIM];
    int N;
    cargaMatrizAdyGrafo(matAdy, &N);
    recorridoProfundidad(matAdy, N);
    return 0;
}

//Carga matriz de adyacencia de un grafo desde un archivo de texto.
void cargaMatrizAdyGrafo(int matAdy[][DIM], int *N){
    int i, j;
    FILE *arch;
    arch = fopen("grafo.txt", "rt");
    fscanf(arch, "%d", N);
    for(i = 0; i < *N; i++)
        for(j = 0; j < *N; j++)
            fscanf(arch, "%d", &matAdy[i][j]);
    fclose(arch);
}

int todosVisitados(int VV[], int N){
    int i = 0;
    while(i < N && VV[i] != 0)
        i++;
    if(i == N)
        return 1;
    else
        return 0;
}

void recorridoProfundidad(int matAdy[][DIM], int N){
    TPila P;
    TElementoP vertice = 0;
    int j;
    int VV[N];
    for(j = 0; j < N; j++){
        VV[j] = 0;
    }
    iniciaP(&P);
    VV[vertice] = 1;
    poneP(&P, vertice);
    printf("%d\t", vertice);
    while(!todosVisitados(VV, N)){
        vertice = consultaP(P);
        j = 0;
        while(j < N && (matAdy[vertice][j] == 0 || VV[j] == 1))
            j++;
        if(j < N){
            poneP(&P, j);
            VV[j] = 1;
            printf("%d\t", j);
        }
        else
            sacaP(&P, &vertice);
    }
}


void recorridoAmplitud(int matAd)
