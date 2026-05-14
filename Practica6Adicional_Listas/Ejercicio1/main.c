/*Dadas dos listas simplemente enlazadas de enteros L1 y L2:
a) verificar si son iguales. Considerar que están ordenadas.
b) añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de
L1. En otro caso, añadir L1 al final de L2.
c) eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada.  */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *sig;}nodo;
typedef struct nodo *TLista;

void cargaLista1(TLista *L);
void cargaLista2(TLista *L);
void verificaIgualdad(TLista L1, TLista L2, int *iguales);

int main()
{
    TLista L1, L2;
    int iguales;
    cargaLista1(&L1);
    cargaLista2(&L2);
    verificaIgualdad(L1, L2, &iguales);
    if(iguales)
        printf("Las listas son iguales");
    else
        printf("Las listas no son iguales");
    return 0;
}


void verificaIgualdad(TLista L1, TLista L2, int *iguales){
    TLista aux1, aux2;
    *iguales = 1;
    aux1 = L1;
    aux2 = L2;
    while(aux1 != NULL && aux2 != NULL && *iguales){
        if(aux1->num != aux2->num)
            *iguales = 0;
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }
    if(aux1 != NULL || aux2 != NULL)
        *iguales = 0;
}

void anadeLista(TLista L1, TLista L2){
    TLista aux1, aux2, nuevo;
    int ultElem1;
    aux1 = L1;
    aux2 = L2;
    while(aux1->sig != NULL)
        aux1 = aux1->sig;
    ultElem1 = aux1->num;
    if(aux2 != NULL){
        if(aux2->num > ultElem1)  //L2 al final de L1
            while(aux2 != NULL){
                nuevo = (TLista)malloc(sizeof(nodo));
                nuevo->num = aux2->num;
                nuevo->sig = NULL;
                aux1->sig = nuevo;
                aux1 = nuevo;
                aux2 = aux2->sig;
            }
        else{
            while(aux2->sig != NULL)
                aux2 = aux2->sig;
            aux1 = L1;
            while(aux1 != NULL){
                nuevo = (TLista)malloc(sizeof(nodo));
                nuevo->num = aux1->num;
                nuevo->sig = NULL;
                aux2->sig = nuevo;
                aux2 = nuevo;
                aux1 = aux1->sig;
            }
        }
    }
}

void eliminarNodos(TLista *L1, TLista L2){
    TLista ant, act, elim, aux2;
    ant = NULL;
    act = *L1;
    aux2 = L2;
    if(act != NULL){
        while(act != NULL && act->num < aux2->num){
            ant = act;
            act = act->sig;
        }
        if(act->num == aux2->num){
            if(ant == NULL)
                *L1 = NULL;
            else
                ant->sig = NULL;
            while(act != NULL){
                elim = act;
                act = act->sig;
                free(elim);
            }
        }
    }
}

void cargaLista1(TLista *L){
    FILE *arch;
    int num;
    TLista nuevo;
    *L = NULL;  //incializar en NULL en main o funcion??
    arch = fopen("lista1.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%d", &num) == 1){
            nuevo = (TLista)malloc(sizeof(nodo));
            nuevo->num = num;
            nuevo->sig = *L;   //Inserto al inicio (caso de la pila)
            *L = nuevo;
        }
        fclose(arch);
    }
    else
        printf("Archivo no existente...");
}

void cargaLista2(TLista *L){
    FILE *arch;
    int num;
    TLista nuevo;
    *L = NULL;  //incializar en NULL en main o funcion??
    arch = fopen("lista2.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%d", &num) == 1){
            nuevo = (TLista)malloc(sizeof(nodo));
            nuevo->num = num;
            nuevo->sig = *L;   //Inserto al inicio (caso de la pila)
            *L = nuevo;
        }
        fclose(arch);
    }
    else
        printf("Archivo no existente...");
}

