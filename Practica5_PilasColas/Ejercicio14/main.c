/*Utilizar las estructuras que considere adecuadas para determinar si una palabra almacenada en
una cola es palíndroma. Se conoce de antemano la cantidad de letras de la palabra (N). */

#include <stdio.h>
#include <stdlib.h>
#define DIM 1000
#include "Cola.h"
#include "Pilas.h"

void cargaPalabra(TCola *c, int *n, char palabra[]);
void esPalindroma(TCola *c, int n, int *esPalind);

int main()
{
    TCola c;
    char palabra[DIM];
    int n = 0, esPalind = 1;
    printf("Ingrese palabra: ");
    scanf("%s", palabra);
    cargaPalabra(&c, &n, palabra);
    esPalindroma(&c, n, &esPalind);
    if(esPalind)
        printf("La palabra ingresada es palindroma.");
    else
        printf("La palabra ingresada no es palindroma.");
    return 0;
}

void cargaPalabra(TCola *c, int *n, char palabra[]){
    int i;
    iniciaC(c);  //Acordarme de inicializar las estructuras.......
    for(i = 0; palabra[i] != '\0'; i++){
        poneC(c, palabra[i]);
        (*n)++;
    }
}

void esPalindroma(TCola *c, int n, int *esPalind){  //esPalind se inicializa con 1 en el main.
    TPila paux;
    TElementoP temp1;
    TElementoC car, temp2;
    int i, medio;
    medio = n / 2;
    iniciaP(&paux);
    for(i = 0; i < medio; i++){
        sacaC(c, &car);
        poneP(&paux, car);
    }
    if(n % 2 != 0)  //La palabra tiene cantidad de letras impar, por lo cual debo sacarle el caracter del medio
        sacaC(c, &car);
    while(!vaciaP(paux) && esPalind != 0){
        sacaP(&paux, &temp1);
        sacaC(c, &temp2);
        if(temp1 != temp2)
            *esPalind = 0;
    }
}
