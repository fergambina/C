/*Transformar, mediante un subprograma recursivo, una pila de manera que tenga los mismos
datos pero cambiados de signo. */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void cargarPila(TPila *P);
void mostrarPila(TPila *P);
void transformaPila(TPila *P);

int main()
{
    TPila P;
    cargarPila(&P);
    printf("Pila original: \n");
    mostrarPila(&P);
    printf("Pila transformada: \n");
    transformaPila(&P);
    mostrarPila(&P);
    return 0;
}

void cargarPila(TPila *P){
    FILE *archT;
    TElementoP num;
    iniciaP(P);
    archT = fopen("numeros.txt", "rt");
    if(archT != NULL){
        while(fscanf(archT, " %d\n", &num) == 1)
            poneP(P, num);
        fclose(archT);
    }
    else{
        printf("El archivo no existe...");
    }
}

void mostrarPila(TPila *P){      //Se muestra un espacio cuando muestro la pila..
    TElementoP num;
    if(!vaciaP(*P)){
        sacaP(P, &num);
        mostrarPila(P);
        printf("[%d]\n", num);
        poneP(P, num);
    }
}

void transformaPila(TPila *P){
    TElementoP num;
    if(!vaciaP(*P)){
        sacaP(P, &num);
        num *= -1;
        transformaPila(P);
        poneP(P, num);
    }
}
