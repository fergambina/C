/*4) Eliminar todas las apariciones de X de una lista simplemente enlazada de enteros*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *sig;
}nodo;
typedef struct nodo *TLista;

int main()
{
    printf("Hello world!\n");
    return 0;
}



void eliminaAparicionesX(TLista *L, int x){
    TLista elim, ant, act;
    act = *L;
    while(act != NULL){
        if(act->num == x){
            elim = act;
            act = act->sig;
            if(elim == *L)
                *L = act;
            else
                ant->sig = act;
            free(elim);
        }
        else{
            ant = act;
            act = act->sig;
        }
    }
}


void eliminaAparicionesX(TLista *L, int x){
    TLista elim, ant, act;
    act = *L;
    while(act != NULL){
        if(act->num == x){
            elim = act;
            if(*L == act)
                *L = (*L)->sig;
            else
                ant->sig = act->sig;
            act = act->sig;
            free(elim);
        }
        else{
            ant = act;
            act = act->sig;
        }
    }
}
