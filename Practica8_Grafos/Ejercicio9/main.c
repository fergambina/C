/*Hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia. */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

typedef struct nodo{
    int vertice;
    struct nodo *sig;
}nodo;
typedef struct nodo *TLista;

void iniciaListasAdy(TLista digrafo[], int N);
void agregarArista(TLista digrafo[], int origen, int destino);
int calculaGradoEntrada(TLista digrafo[], int N, int vertice);
int verticeMayorGradoEntrada(TLista digrafo[], int N);


int main()
{
    TLista digrafo[DIM];
    int N = 4;
    iniciaListasAdy(digrafo, N);
    agregarArista(digrafo, 0, 0);
    agregarArista(digrafo, 0, 1);
    agregarArista(digrafo, 0, 2);
    agregarArista(digrafo, 1, 3);
    agregarArista(digrafo, 1, 0);
    agregarArista(digrafo, 2, 0);
    agregarArista(digrafo, 2, 1);
    agregarArista(digrafo, 2, 1);
    agregarArista(digrafo, 3, 2);
    agregarArista(digrafo, 3, 1);
    printf("El vertice con mayor grado de entrada en el digrafo es: %d", verticeMayorGradoEntrada(digrafo, N));
    return 0;
}


//Carga el diggrafo en una lista de adyacencia
void iniciaListasAdy(TLista digrafo[], int N){
    int i;
    for(i = 0; i < N; i++)
        digrafo[i] = NULL;
}

void agregarArista(TLista digrafo[], int origen, int destino){
    TLista nuevo;
    nuevo = (TLista)malloc(sizeof(nodo));
    nuevo->vertice = destino;
    nuevo->sig = digrafo[origen];
    digrafo[origen] = nuevo;
}

int calculaGradoEntrada(TLista digrafo[], int N, int vertice){
    TLista aux;
    int i, gr = 0;
    for(i = 0; i < N; i++){
        aux = digrafo[i];
        while(aux != NULL){
            if(aux->vertice == vertice)
                gr++;
            aux = aux->sig;
        }
    }
    return gr;
}

int verticeMayorGradoEntrada(TLista digrafo[], int N){
    int i, gradoVertice, verticeMaxGrado, gradoMax = -1;
    for(i = 0; i < N; i++){
        gradoVertice = calculaGradoEntrada(digrafo, N, i);
        if(gradoVertice > gradoMax){
            gradoMax = gradoVertice;
            verticeMaxGrado = i;
        }
    }
    return verticeMaxGrado;
}
