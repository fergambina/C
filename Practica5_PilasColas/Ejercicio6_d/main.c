/* Desarrollar subprogramas (con estructuras iterativas) que trabajando sobre una pila de
enteros: quite todos los valores mayores al último.*/

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void cargarPila(TPila *P);
void quitaValoresMayoresUltimo(TPila *P);
void mostrarPila(TPila *P);

int main()
{
    TPila P;
    cargarPila(&P);
    printf("Mostrando pila...\n");
    mostrarPila(&P);
    printf("\n");
    quitaValoresMayoresUltimo(&P);
    printf("Mostrando pila con los elementos menores al ultimo...\n");
    mostrarPila(&P);
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

void quitaValoresMayoresUltimo(TPila *P){
    TPila PAux;
    TElementoP ult, num;
    iniciaP(&PAux);
    if(!vaciaP(*P)){
        sacaP(P, &ult);
        poneP(&PAux, ult);
        while(!vaciaP(*P)){
            sacaP(P, &num);
            if(num <= ult)
                poneP(&PAux, num);
        }
        while(!vaciaP(PAux)){
            sacaP(&PAux, &num);
            poneP(P, num);
        }
    }
}

void mostrarPila(TPila *P){
    TPila PAux;
    TElementoP num;
    iniciaP(&PAux);
    while(!vaciaP(*P)){
        sacaP(P, &num);
        poneP(&PAux, num);
    }
    while(!vaciaP(PAux)){
        sacaP(&PAux, &num);
        printf("%d\n", num);
        poneP(P, num);
    }
}

