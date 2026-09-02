/* Para un grafo almacenado en una lista de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad
b) mostrar todos sus vértices mediante recorrido en amplitud
c) devolver la cantidad de componentes conexas */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"
#include "Cola.h"
#define DIM 30


typedef struct nodo{
    int vertice;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

void iniciaListasAdy(TLista grafo[], int N);
void agregarArista(TLista grafo[], int origen, int destino);
int todosVisitados(int VV[], int N);
void recorridoProfundidad(TLista grafo[], int N);
void recorridoAmplitud(TLista grafo[], int N);
int cantComponentesConexasProf(TLista grafo[], int N);
int cantComponentesConexasAmp(TLista grafo[], int N);

int main()
{
    TLista grafo[DIM];
    int N = 10; //Declaro un grafo de 7 vertices
    iniciaListasAdy(grafo, N);
    agregarArista(grafo, 0, 1);
    agregarArista(grafo, 0, 2);
    agregarArista(grafo, 1, 0);
    agregarArista(grafo, 1, 2);
    agregarArista(grafo, 1, 3);
    agregarArista(grafo, 2, 3);
    agregarArista(grafo, 2, 0);
    agregarArista(grafo, 2, 1);
    agregarArista(grafo, 2, 4);
    agregarArista(grafo, 3, 4);
    agregarArista(grafo, 3, 2);
    agregarArista(grafo, 3, 1);
    agregarArista(grafo, 4, 2);
    agregarArista(grafo, 4, 3);
    agregarArista(grafo, 4, 5);
    agregarArista(grafo, 4, 6);
    agregarArista(grafo, 5, 4);
    agregarArista(grafo, 6, 4);
    agregarArista(grafo, 7, 8);
    agregarArista(grafo, 8, 7);
    //printf("Recorrido en profundidad del grafo...\n");
    //recorridoProfundidad(grafo, N);
    //printf("\n");
    //printf("Recorrido en amplitud del grafo...\n");
    //recorridoAmplitud(grafo, N);
    //printf("\n");
    printf("Cantidad de componentes conexas: %d\n", cantComponentesConexasProf(grafo, N));
    printf("Cantidad de componentes conexas: %d", cantComponentesConexasAmp(grafo, N));
    return 0;
}


//Carga el grafo en una lista de adyacencia
void iniciaListasAdy(TLista grafo[], int N){
    int i;
    for(i = 0; i < N; i++)
        grafo[i] = NULL;
}

void agregarArista(TLista grafo[], int origen, int destino){
    TLista nuevo;
    nuevo = (TLista)malloc(sizeof(nodo));
    nuevo->vertice = destino;
    nuevo->sig = grafo[origen];
    grafo[origen] = nuevo;
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

void recorridoProfundidad(TLista grafo[], int N){
    int VV[N], i, vertice;
    TLista act;
    TPila P;
    iniciaP(&P);
    for(i = 0; i < N; i++)
        VV[i] = 0;
    vertice = 0; //Selecciono vertice inicial;
    printf("%d\t", vertice);
    poneP(&P, vertice);
    VV[vertice] = 1;
    while(!todosVisitados(VV, N)){
        vertice = consultaP(P);
        act = grafo[vertice];
        while(act != NULL && VV[act->vertice] == 1)
            act = act->sig;
        if(act != NULL){
            printf("%d\t", act->vertice);
            poneP(&P, act->vertice);
            VV[act->vertice] = 1;
        }
        else
            sacaP(&P, &vertice);
    }
}

void recorridoAmplitud(TLista grafo[], int N){
    TCola C;
    int VV[N], i, vertice;
    TLista act;
    iniciaC(&C);
    for(i = 0; i < N; i++)
        VV[i] = 0;
    vertice = 0;
    printf("%d\t", vertice);
    poneC(&C, vertice);
    VV[vertice] = 1;
    while(!todosVisitados(VV, N)){
        sacaC(&C, &vertice);
        act = grafo[vertice];
        while(act != NULL){
            if(VV[act->vertice] == 0){
                printf("%d\t", act->vertice);
                poneC(&C, act->vertice);
                VV[act->vertice] = 1;
            }
            act = act->sig;
        }
    }
}

//Ejercicio C)
int cantComponentesConexasProf(TLista grafo[], int N){
    int cont = 0;
    int VV[N], i, vertice;
    TPila P;
    TLista act;
    iniciaP(&P);
    for(i = 0; i < N; i++)
        VV[i] = 0;
    while(!todosVisitados(VV, N)){
        i = 0;
        while(VV[i])
            i++;
        cont++;
        VV[i] = cont;
        poneP(&P, i);
        while(!vaciaP(P) && !todosVisitados(VV, N)){
            vertice = consultaP(P);
            act = grafo[vertice];
            while(act != NULL && VV[act->vertice] != 0)
                act = act->sig;
            if(act != NULL){
                poneP(&P, act->vertice);
                VV[act->vertice] = cont;
            }
            else
                sacaP(&P, &vertice);
        }
    }
    return cont;
}


int cantComponentesConexasAmp(TLista grafo[], int N){
    int cont = 0;
    int VV[N], i, vertice;
    TCola C;
    TLista act;
    iniciaC(&C);
    for(i = 0; i < N; i++)
        VV[i] = 0;
    while(!todosVisitados(VV, N)){
        i = 0;
        while(VV[i])
            i++;
        cont++;
        poneC(&C, i);
        VV[i] = cont;
        while(!vaciaC(C) && !todosVisitados(VV, N)){
            sacaC(&C, &vertice);
            act = grafo[vertice];
            while(act != NULL){
                if(VV[act->vertice] == 0){
                    poneC(&C, act->vertice);
                    VV[act->vertice] = cont;
                }
                act = act->sig;
            }
        }
    }
    return cont;
}
