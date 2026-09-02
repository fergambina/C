/* Para un grafo almacenado en una matriz de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad
b) mostrar todos sus vértices mediante recorrido en amplitud
c) devolver la cantidad de componentes conexas */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"
#include "Cola.h"
#define DIM 30

void cargaMatrizAdyGrafo(int matAdy[][DIM], int *N);
void recorridoProfundidad(int matAdy[][DIM], int N);
void recorridoAmplitud(int matAdY[][DIM], int N);
int cantComponentesConexasAmp(int matAdY[][DIM], int N);

int main()
{
    int matAdy[DIM][DIM];
    int N;
    cargaMatrizAdyGrafo(matAdy, &N);
    printf("Recorrido en profundidad...\n");
    //recorridoProfundidad(matAdy, N);
    printf("\nRecorrido en amplitud...\n");
    //recorridoAmplitud(matAdy, N);
    printf("Cantidad de componentes conexas: %d", cantComponentesConexasAmp(matAdy, N));
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

//Ejercicio A)
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


void recorridoAmplitud(int matAdY[][DIM], int N){
    TCola C;
    int VV[N];
    int j, vertice;
    iniciaC(&C);
    for(j = 0; j < N; j++)
        VV[j] = 0;
    vertice = 0;
    printf("%d\t", vertice);
    poneC(&C, vertice);
    VV[vertice] = 1;
    while(!todosVisitados(VV, N)){
        sacaC(&C, &vertice);
        for(j = 0; j < N; j++){
            if(matAdY[vertice][j] != 0 && VV[j] != 1){
                printf("%d\t", j);
                poneC(&C, j);
                VV[j] = 1;
            }
        }
    }
}

//Ejercicio C)
int cantComponentesConexasAmp(int matAdY[][DIM], int N){
    TCola C;
    int VV[N];
    int j, vertice, cont = 0;
    iniciaC(&C);
    for(j = 0; j < N; j++)
        VV[j] = 0;
    while(!todosVisitados(VV, N)){
        j = 0;
        while(VV[j])
            j++;
        cont++;
        poneC(&C, j);
        VV[j] = cont;
        while(!vaciaC(C) && !todosVisitados(VV, N)){
            sacaC(&C, &vertice);
            for(j = 0; j < N; j++)
                if(matAdY[vertice][j] != 0 && VV[j] == 0){
                    poneC(&C, j);
                    VV[j]= cont;
                }
        }
    }
    return cont;
}
