/*Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la pila.
a. Utilizar la implementación estática. */

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
        while(fscanf(archT, "%c\n", &car) == 1)
            poneP(P, car);
        fclose(archT);
    }
    else{
        printf("El archivo no existe...");
    }
}

void mostrarPila(TPila *P){
    TElementoP car;
    while(!vaciaP(*P)){                            //Mostrar pila hacerlo recursivo...
        sacaP(P, &car);
        printf("%c\n", car);
    }
}
