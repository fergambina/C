/*Generar una lista simplemente enlazada a partir del contenido de un arreglo de N enteros no
ordenados:
a) invirtiendo el orden de sus elementos (no se permite recorrer el arreglo comenzando por el
último elemento)
b) manteniendo el orden de sus elementos.
c) de forma ordenada*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 50

typedef struct nodo{
    int num;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

void cargaVector(int vec[], int *N);
void generaListaInvirtiendoOrden(TLista *L, int vec[], int N);
void generaListaManteniendoOrden(TLista *L, int vec[], int N);
void generaListaOrdenada(TLista *L , int vec[], int N);
void escribirLista(TLista L);

int main()
{
    int vec[DIM], N;
    TLista L = NULL;
    cargaVector(vec, &N);
    //generaListaInvirtiendoOrden(&L, vec, N);
    generaListaManteniendoOrden(&L, vec, N);
    //generaListaOrdenada(&L, vec, N);
    escribirLista(L);
    return 0;
}

void cargaVector(int vec[], int *N){
    FILE *arch;
    arch = fopen("numeros.txt", "rt");
    if (arch != NULL){
        *N = 0;
        while (fscanf(arch, "%d", &vec[*N]) == 1)
            (*N)++;
        fclose(arch);
    }else
        printf("El archivo no existe...");
}


void generaListaInvirtiendoOrden(TLista *L, int vec[], int N){
    TLista aux;
    int i;
    for(i = 0; i < N; i++){
        aux = (TLista)malloc(sizeof(nodo)); //Reserva espacio para un nuevo nodo y aux queda apuntando a el
        aux->num = vec[i];
        aux->sig = *L; //Al campo siguiente del nodo nuevo le asigno la dirección del nodo que era el primero de la lista y queda apuntando a el
        *L = aux;
    }
}

void generaListaManteniendoOrden(TLista *L, int vec[], int N){
    TLista act, nuevo;
    int i = 0;
    if(N > 0){
        act = (TLista)malloc(sizeof(nodo));
        act->num = vec[i];
        *L = act;
        act->sig = NULL;
        for(i = 1; i < N; i++){
            nuevo = (TLista)malloc(sizeof(nodo));
            nuevo->num = vec[i];
            nuevo->sig = NULL;
            act->sig = nuevo;
            act = nuevo;
        }
    }
}

/*void generaListaManteniendoOrden(TLista *L, int vec[], int N){
    TLista aux, ant;
    int i = 0;
    if(N > 0){
        aux = (TLista)malloc(sizeof(nodo)); //Agrego el primer nodo
        aux->num = vec[i];
        aux->sig = *L;
        *L = aux;
        for(i = 1; i < N; i++){   //Agrego los nodos restantes
            ant = aux;
            aux = (TLista)malloc(sizeof(nodo));      //aux cambia de significado... (no tiene un unico proposito)
            aux->num = vec[i];
            aux->sig = ant->sig;
            ant->sig = aux;
        }
    }
}*/

void generaListaOrdenada(TLista *L , int vec[], int N){
    TLista aux, ant, act;
    int i = 0;
    if(N > 0){
        aux = (TLista)malloc(sizeof(nodo));  //Coloco el primer dato
        aux->num = vec[i];
        aux->sig = *L;
        *L = aux;
        for(i = 1; i < N; i++){
            aux = (TLista)malloc(sizeof(nodo)); //
            aux->num = vec[i];
            ant = NULL;
            act = *L;
            while(act != NULL && aux->num > act->num){
                ant = act;
                act = act->sig;
            }
            if(ant == NULL){
                aux->sig = act;
                *L = aux;
            }
            else{
                aux->sig = act;
                ant->sig = aux;
            }
        }
    }
}


void escribirLista(TLista L){
    TLista aux;
    aux = L;
    while(aux != NULL){
        printf("%d\t", aux->num);
        aux = aux->sig;
    }
}
