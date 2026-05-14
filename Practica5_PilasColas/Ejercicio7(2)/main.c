/*Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la pila de manera recursiva.*/

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
    archT = fopen("caracteres.txt", "rt");
    if(archT != NULL){
        iniciaP(P);
        while(fscanf(archT, " %c", &car) == 1)
            poneP(P, car);
        fclose(archT);
    }
    else{
        printf("El archivo no existe...");
    }
}

void mostrarPila(TPila *P){      //Se muestra un espacio cuando muestro la pila..
    TElementoP car;
    if(!vaciaP(*P)){
        sacaP(P, &car);
        mostrarPila(P);
        printf("[%c]\n", car);
        poneP(P, car);
    }
}
