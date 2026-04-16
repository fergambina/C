/*Desarrollar un programa que sume dos números enteros positivos, permitiendo una cantidad
de dígitos mayor a la que soportan los tipos numéricos. Los números pueden tener diferente
magnitud y deben ser ingresados comenzando desde su dígito más significativo (en orden).
Utilizar pilas de caracteres. */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

#define DIM 1000

void cargarNumPila(TPila *p, char num[]);
void suma(TPila *p1, TPila *p2, TPila *pres);
void mostrarPila(TPila *p);

int main()
{
    char num1[DIM], num2[DIM];
    TPila p1, p2, pres;
    printf("Ingrese un numero: ");
    scanf("%s", num1);
    printf("Ingrese un numero: ");
    scanf("%s", num2);
    cargarNumPila(&p1, num1);
    cargarNumPila(&p2, num2);
    printf("La suma de ambos numeros es: ");
    suma(&p1, &p2, &pres);
    mostrarPila(&pres);
    return 0;
}

void cargarNumPila(TPila *p, char num[]){
    int i;
    iniciaP(p);
    for(i = 0; num[i] != '\0'; i++)
        poneP(p, num[i]);
}

void suma(TPila *p1, TPila *p2, TPila *pres){
    int dig1, dig2, tot;
    int acarreo = 0;
    char digito;
    TElementoP temp;
    iniciaP(pres);
    while(!vaciaP(*p1) || !vaciaP(*p2) || acarreo != 0){
            dig1 = dig2 = 0;
            if(!vaciaP(*p1)){
                sacaP(p1, &temp);
                dig1 = temp - '0';
            }
            if (!vaciaP(*p2)) {
                sacaP(p2, &temp);
                dig2 = temp - '0';
            }
            tot = dig1 + dig2 + acarreo;
            acarreo = tot / 10;
            digito = (tot % 10) + '0';
            poneP(pres, digito);
    }
}

void mostrarPila(TPila *p){
    TElementoP digito;
    while(!vaciaP(*p)){
        sacaP(p, &digito);
        printf("%c", digito);
    }
}
