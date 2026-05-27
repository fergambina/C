/*Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
a) una lista de adyacencia
b) una matriz de adyacencia
c) media matriz (triángulo superior)*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 20

typedef struct nodo{
    int vertice;
    struct nodo *sig;}nodo;
typedef struct nodo *TLista;

void iniciaListasAdy(TLista grafo[], int N);
void agregarArista(TLista grafo[], int origen, int destino);
int gradoListaAdy(TLista grafo[], int vertice);
void cargaMatrizAdyGrafo(int matAdy[][DIM], int N);
int gradoMatAdy(int matAdy[][DIM], int N, int vertice);
int gradoMediaMatriz(int matAdy[][DIM], int N, int vertice);

int main()
{
    TLista grafo[DIM];
    int N = 4, vertice;
    int matAdy[DIM][DIM];
    iniciaListasAdy(grafo, N);
    agregarArista(grafo, 0, 0);
    agregarArista(grafo, 0, 1);
    agregarArista(grafo, 0, 2);
    agregarArista(grafo, 1, 0);
    agregarArista(grafo, 1, 3);
    agregarArista(grafo, 1, 2);
    agregarArista(grafo, 2, 0);
    agregarArista(grafo, 2, 3);
    agregarArista(grafo, 2, 1);
    agregarArista(grafo, 3, 1);
    agregarArista(grafo, 3, 2);

    printf("Ingrese vertice (0 - 4): ");
    scanf("%d", &vertice);
    printf("El grado del vertice %d es: %d\n", vertice, gradoListaAdy(grafo, vertice));

    //Para el ejercicio B)
    cargaMatrizAdyGrafo(matAdy, N);
    printf("El grado del vertice %d es: %d\n", vertice, gradoMatAdy(matAdy, N, vertice));
    //Ejercicio C)
    printf("El grado del vertice %d es: %d\n", vertice, gradoMediaMatriz(matAdy, N, vertice));

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

//Ejercicio A0
int gradoListaAdy(TLista grafo[], int vertice){
    TLista aux;
    int cont = 0;
    aux = grafo[vertice];
    while(aux != NULL){
        cont++;
        aux = aux->sig;
    }
    return cont;
}

//Carga matriz de adyacencia de un grafo desde un archivo de texto.
void cargaMatrizAdyGrafo(int matAdy[][DIM], int N){
    int i, j;
    FILE *arch;
    arch = fopen("grafo.txt", "rt");
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            fscanf(arch, "%d", &matAdy[i][j]);
    fclose(arch);
}

//Ejercicio B)
int gradoMatAdy(int matAdy[][DIM], int N, int vertice){
    int cont = 0, i;
    for(i = 0; i < N; i++)
        if(matAdy[i][vertice] == 1)
            cont++;
    return cont;
}

//Ejercicio C)
int gradoMediaMatriz(int matAdy[][DIM], int N, int vertice){
    int i, j, gr = 0;
    for(i = 0; i <= vertice; i++)
        gr += matAdy[i][vertice];
    for(j = vertice + 1; j < N; j++)
        gr += matAdy[vertice][j];
    return gr;
}
