#include <stdlib.h>
#include "Pila_Dinamica.h"

void iniciaP(TPila *P){
    *P = NULL;
}

int vaciaP(TPila P){
    return P == NULL;
}

TElementoP consultaP(TPila P){
    if(P != NULL)
        return P->dato;
}

void poneP(TPila *P,TElementoP x){
    TPila N;
    N = (TPila)malloc(sizeof(nodop));
    N->dato = x;
    N->sig = *P;
    *P = N;
}

void sacaP(TPila *P, TElementoP *x){
    TPila N;
    if(*P != NULL){
        N = *P;
        *x = (*P)->dato;
        *P = (*P)->sig;
        free(N);
    }
}

