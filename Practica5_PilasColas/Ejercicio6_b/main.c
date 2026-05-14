/*Desarrollar subprogramas (con estructuras iterativas) que trabajando sobre una pila de
enteros:
b. obtenga el valor promedio (sin perder la información de la pila)
*/

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void cargarPila(TPila *P);
void promedio(TPila *P, float *prom);

int main()
{
    TPila P;
    float prom;
    cargarPila(&P);
    promedio(&P, &prom);
    printf("Promedio de los elementos de la pila: %5.2f", prom);
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

void promedio(TPila *P, float *prom){
    TPila PAux;
    TElementoP num, sum = 0;
    int cont = 0;
    iniciaP(&PAux);
    while(!vaciaP(*P)){
        sacaP(P, &num);
        poneP(&PAux, num);
        sum += num;
        cont++;
    }
    if(cont > 0){
        *prom = sum / cont;
        while(!vaciaP(PAux)){
            sacaP(&PAux, &num);
            poneP(P, num);
        }
    }
    else
        *prom = 0.0;

}
