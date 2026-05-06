/*Resolver mediante subprogramas las siguientes operaciones sobre una lista circular:
a) insertar un elemento conociendo la posición (puntero) del anterior. Tomar el último como
anterior del primero, y nulo para insertar en una lista vacía.
b) insertar un elemento conociendo la posición (puntero) del siguiente. Tomar el primero
como siguiente del último, nulo para insertar en una lista vacía.
c) eliminar todas las ocurrencias del elemento X (recibido como parámetro) */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *sig;}nodo;
typedef struct nodo *TListaC;


int main()
{
    printf("Hello world!\n");
    return 0;
}

void insertaElementoV1(TListaC *LC, TListaC anterior, int num){
    TListaC nuevo;
    nuevo = (TListaC)malloc(sizeof(nodo));
    nuevo->num = num;
    if(anterior == NULL){
        *LC = nuevo;
        nuevo->sig = nuevo;
    }
    else{
        if(anterior == *LC){
            nuevo->sig = anterior->sig;
            anterior->sig = nuevo;
        }
        else{
            nuevo->sig = anterior->sig;
            anterior->sig = nuevo;
        }
    }
}

void insertaElementoV2(TListaC *LC, TListaC siguiente, int num){
    TListaC nuevo, anterior;
    nuevo = (TListaC)malloc(sizeof(nodo));
    nuevo->num = num;
    if(siguiente == NULL){
        *LC = nuevo;
        nuevo->sig = nuevo;
    }
    else{
        if(siguiente == (*LC)->sig){
            nuevo->sig = siguiente;
            (*LC)->sig = nuevo;
            *LC = nuevo;
        }
        else{
            anterior = (*LC)->sig;
            while(anterior->sig != siguiente)
                anterior = anterior->sig;
            anterior->sig = nuevo;
            nuevo->sig = siguiente;
        }
    }
}

void eliminaOcurrenciasDeX(TListaC *LC, int x){
    TListaC ant, act, elim;
    if(*LC != NULL){
        ant = *LC;
        act = (*LC)->sig;
        do{
            if(act->num == x){
                elim = act;
                if(act == ant){
                    *LC = NULL;
                }
                else{
                    ant->sig = act->sig;
                    if(act == *LC)
                        *LC = ant;
                    act = act->sig;
                }
                free(elim);
            }
            else{
                ant = act;
                act = act->sig;
            }
        }while(*LC != NULL && act != (*LC)->sig);
    }
}
