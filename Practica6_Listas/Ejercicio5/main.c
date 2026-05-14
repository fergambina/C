/*Una lista contiene en cada nodo una cola de números enteros. Desarrollar un programa que
genere una pila con los elementos máximos de cada cola de la lista. (Utilizar TDA pila dinámica
y TDA cola circular). */

#include <stdio.h>
#include <stdlib.h>
#include "PilaDinamica.h"
#include "ColaEstaticaCircular.h"

typedef struct nodo{
    TCola C;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

void cargaLista(TLista *L);

int main()
{
    TLista L = NULL;
    TPila P;
    cargaLista(&L);
    generaPila(L, &P);
    mostrarPila(&P);
    return 0;
}

void generaPila(TLista L, TPila *P){
    TLista aux;
    int num, max, cent = 999;
    iniciaP(P);
    aux = L;
    while(aux != NULL){
        max = -999;
        poneC(&(aux->C), cent);
        sacaC(&(aux->C), &num);
        while(num != cent){
            if(num > max)
                max = num;
            poneC(&(aux->C), num);
            sacaC(&(aux->C), &num);
        }
        poneP(P, max);
        aux = aux->sig;
    }
}

void cargaLista(TLista *L){
    TLista nuevo;
    TElementoC num;
    FILE *arch;
    arch = fopen("colas.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%d", &num) == 1){
            nuevo = (TLista)malloc(sizeof(nodo));
            iniciaC(&(nuevo->C));
            if(num != -999){
                poneC(&(nuevo->C), num);
                while(fscanf(arch, "%d", &num) == 1 && num != -999)
                    poneC(&(nuevo->C), num);
            }
            nuevo->sig = *L;
            *L = nuevo;
        }
        fclose(arch);
    }
}
