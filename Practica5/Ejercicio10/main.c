/* Ingresar una secuencia de caracteres terminada en punto que representa una expresión
aritmética.
a. Comprobar que los paréntesis estén balanceados, de no ser así informar si falta
izquierdo o derecho. Los paréntesis son los únicos símbolos a controlar. Ejemplo
correcto: ( ( ) ( ) ). Ej. incorrectos: ( ( ) ( ) ; ( ) ) ( ; ( ) ) (  */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

int main()
{
    TPila p;
    cargarSecuencia(&p);
    return 0;
}

void cargarSecuencia(TPila *p){
    TElementoP car;
    iniciaP(p);
    printf("Ingrese caracter: ");
    scanf("%c", &car);
    while(car != '.'){
        poneP(p, car);
        printf("Ingrese caracter: ");
        scanf("%c", &car);
    }
}

void compruebaBalance(TPila *p, int *res){   //res se incializa con 0 en el main.
    TElementoP car;
    int cont_izq = 0;
    int sin_error = 1;
    TPila paux;
    iniciaP(&paux);
    *res = 0; //Expresion balanceada.
    while(!vaciaP(*p)){
        sacaP(p, &car);
        poneP(&paux, car);
    }
    while(!vaciaP(paux)&& sin_error != 0){
            sacaP(&paux, car);
            if(car == '('){
                cont_izq++
            }
            else{
                if(car == ')')
                    cont_izq--;
                if(cont_izq < 0){
                    *res = -1;
                    sin_error = 0;
                }
            }

    }
    if(sin_error != 0 && cont_izq > 0){
        *res = 1;
    }

}
