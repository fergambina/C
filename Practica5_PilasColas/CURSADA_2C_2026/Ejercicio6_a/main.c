/*Desarrollar subprogramas (con estructuras iterativas) que trabajando sobre una pila de
enteros:
a. cuente la cantidad de ceros que contiene. */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void cargarPila(TPila *P);
void cantCeros(TPila *P, int *cont);

int main()
{
    TPila P;
    int cont;
    cargarPila(&P);
    cantCeros(&P, &cont);
    printf("La cantidad de ceros en la cola es: %d", cont);
    return 0;
}

void cargarPila(TPila *P){
    FILE *archT;
    TElementoP num;
    iniciaP(P);
    archT = fopen("numeros.txt", "rt");
    if(archT != NULL){
        while(fscanf(archT, "%d\n", &num) == 1)
            poneP(P, num);
        fclose(archT);
    }
    else{
        printf("El archivo no existe...");
    }
}

void cantCeros(TPila *P, int *cont){
    TElementoP num;
    *cont = 0;
    while(!vaciaP(*P)){
        sacaP(P, &num);
        if(num == 0)
            (*cont)++;
    }
}
