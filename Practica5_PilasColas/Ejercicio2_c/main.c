#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void cargarPila(TPila *P);
void mostrarPila(TPila *P);

int main()
{
    TPila P;
    cargarPila(&P);
    mostrarPila(&P);
    return 0;
}

void cargarPila(TPila *P){
    FILE *archT;
    TElementoP car;
    iniciaP(P);
    archT = fopen("caracteres.txt", "rt");
    if(archT != NULL){
        while(fscanf(archT,"%c\n", &car) == 1)
            poneP(P, car);
        fclose(archT);
    }
    else{
        printf("El archivo no existe...");
    }
}

void mostrarPila(TPila *P){
    TPila PAux;
    TElementoP car;
    iniciaP(&PAux);
    while(!vaciaP(*P)){
        sacaP(P, &car);
        poneP(&PAux, car);
    }
    while(!vaciaP(PAux)){
        sacaP(&PAux, &car);
        printf("%c\n", car);
        poneP(P, car);
    }
}
