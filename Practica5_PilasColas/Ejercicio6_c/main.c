/* Desarrollar subprogramas (con estructuras iterativas) que trabajando sobre una pila de
enteros: calcule los valores máximo y mínimo de la pila (sin perder la información de la pila) */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void cargarPila(TPila *P);
void maximo(TPila *P, int *max);
void minimo(TPila *P, int *min);

int main()
{
    TPila P;
    TElementoP max, min;
    cargarPila(&P);
    maximo(&P, &max);
    minimo(&P, &min);
    if(max != -999)
        printf("Maximo de la pila: %d\n", max);
    else
        printf("La pila esta vacia.\n");
    if(min != 999)
        printf("Minimo de la pila: %d\n", min);
    else
        printf("La pila esta vacia.\n");
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

void maximo(TPila *P, int *max){   //Devuelve -999 en max si la pila esta vacia.
    TElementoP num;
    TPila PAux;
    iniciaP(&PAux);
    if(!vaciaP(*P)){
        sacaP(P, &num);
        poneP(&PAux, num);
        *max = num;
        while(!vaciaP(*P)){
            sacaP(P, &num);
            poneP(&PAux, num);
            if(num > *max)
                *max = num;
        }
        while(!vaciaP(PAux)){
            sacaP(&PAux, &num);
            poneP(P, num);
        }
    }
    else
        *max = -999;
}


void minimo(TPila *P, int *min){   //Devuelve 999 en min si la pila esta vacia.
    TElementoP num;
    TPila PAux;
    iniciaP(&PAux);
    if(!vaciaP(*P)){
        sacaP(P, &num);
        poneP(&PAux, num);
        *min = num;
        while(!vaciaP(*P)){
            sacaP(P, &num);
            poneP(&PAux, num);
            if(num < *min)
                *min = num;
        }
        while(!vaciaP(PAux)){
            sacaP(&PAux, &num);
            poneP(P, num);
        }
    }
    else
        *min = +999;
}
