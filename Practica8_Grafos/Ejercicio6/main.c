/*Dado un vértice determinado de un digrafo representado en una lista de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

typedef struct nodo{
    int vertice;
    struct nodo *sig;}nodo;
typedef struct nodo *TLista;

void agregarArista(TLista digrafo[], int origen, int destino);
void iniciaListasAdy(TLista digrafo[], int N);
int gradoEntrada(TLista digrafo[], int N, int vertice);
int gradoSalida(TLista digrafo[], int N, int vertice);
int verificaBucle(TLista digrafo[], int N, int vertice);
int gradoTotal(TLista digrafo[], int N, int vertice);


int main()
{
    TLista digrafo[DIM];
    int N = 4, vertice; //Cantidad de vertices.
    iniciaListasAdy(digrafo, N);
    agregarArista(digrafo, 0, 1);
    agregarArista(digrafo, 0, 2);
    agregarArista(digrafo, 0, 0);
    agregarArista(digrafo, 1, 3);
    agregarArista(digrafo, 2, 0);
    agregarArista(digrafo, 2, 1);
    agregarArista(digrafo, 3, 2);
    printf("Ingrese vertice (0-4): ");
    scanf("%d", &vertice);
    printf("El grado de entrada del vertice %d es: %d\n", vertice, gradoEntrada(digrafo, N, vertice));
    printf("El grado de salida del vertice %d es: %d\n", vertice, gradoSalida(digrafo, N, vertice));
    printf("El grado total del vertice %d es: %d", vertice, gradoTotal(digrafo, N, vertice));
    return 0;
}

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

//Ejercicio a)
int gradoEntrada(TLista digrafo[], int N, int vertice){
    int i, cont = 0;
    TLista aux;
    for(i = 0; i < N; i++){
        aux = digrafo[i];
        while(aux != NULL){
            if(aux->vertice == vertice)
                cont++;
            aux = aux->sig;
        }
    }
    return cont;
}

//Ejercicio B)
int gradoSalida(TLista digrafo[], int N, int vertice){
    int cont = 0;
    TLista aux;
    aux = digrafo[vertice];
    while(aux != NULL){
        cont++;
        aux = aux->sig;
    }
    return cont;
}

//Ejercicio C)
int verificaBucle(TLista digrafo[], int N, int vertice){
    TLista aux;
    aux = digrafo[vertice];
    while(aux != NULL && aux->vertice != vertice)
        aux = aux->sig;
    if(aux != NULL && aux->vertice == vertice)
        return 1;
    else
        return 0;
}

int gradoTotal(TLista digrafo[], int N, int vertice){
    if(verificaBucle(digrafo, N, vertice))
        return gradoEntrada(digrafo, N, vertice) + gradoSalida(digrafo, N, vertice) - 1;
    else
        return gradoEntrada(digrafo, N, vertice) + gradoSalida(digrafo, N, vertice);
}
