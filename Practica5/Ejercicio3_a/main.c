/*Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes en orden inverso, comenzando por el último votante. */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void cargarVotantes(TPila *P);
void mostrarVotantes(TPila *P, int n);

int main()
{
    TPila P;
    int n;
    cargarVotantes(&P);
    printf("Ingrese N: ");
    scanf("%d", &n);
    printf("Monstrando los ultimos N votantes...");
    mostrarVotantes(&P, n);
    return 0;
}

void cargarVotantes(TPila *P){
    TElementoP dni;
    printf("Ingrese DNI: ");
    scanf("%lu", &dni);              //do..while?
    while(dni != 0){
        poneP(P, dni);
        printf("Ingrese DNI: ");
        scanf("%lu", &dni);
    }
}

void mostrarVotantes(TPila *P, int n){
    TElementoP dni;
    int i = 0;
    while(i < n && !vaciaP(*P)){
        sacaP(P, &dni);
        printf("%lu\n", dni);
        i++;
    }
}
