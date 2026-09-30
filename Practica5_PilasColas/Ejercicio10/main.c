/* Ingresar una secuencia de caracteres terminada en punto que representa una expresión
aritmética.
a. Comprobar que los paréntesis estén balanceados, de no ser así informar si falta
izquierdo o derecho. Los paréntesis son los únicos símbolos a controlar. Ejemplo
correcto: ( ( ) ( ) ). Ej. incorrectos: ( ( ) ( ) ; ( ) ) ( ; ( ) ) (  */

#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"


void compruebaParentesis(){
    TPila P;
    TElementoP car, extraido;
    int balanceado = 1;
    iniciaP(&P);
    printf("Ingrese una expresion terminada en '.': ");
    scanf("%c", &car);
    while(car != '.' && balanceado){
        if(car == '(')
            poneP(&P, car);
        else{
            if(car == ')'){
                if(!vaciaP(P))
                    sacaP(&P, &extraido);
                else{
                    balanceado = 0;
                    printf("Error: Falta el parentesis izquierdo '('\n");
                }
            }
        }
        scanf(" %c", &car);
    }
    if (balanceado == 1) {
        if (!vaciaP(P)) {
            // Si la pila no quedó vacía, abrimos paréntesis que nunca cerramos
            printf("Error: Falta el parentesis derecho ')'\n");
        } else {
            printf("La expresion es correcta y los parentesis estan balanceados.\n");
        }
    }

}

void compruebaExpresion(){
    TPila P;
    TElementoP car, extraido;
    int balanceado = 1;
    iniciaP(&P);
    printf("Ingrese una secuencia de caracteres terminada en .: ");
    scanf("%c", &car);
    while(car != '.' && balanceado){
        if(car == '(' || car == '{' || car == '[')
            poneP(&P, car);
        else{
            if(car == ')' || car == '}' || car == ']')
                if(vaciaP(P)){
                    balanceado = 0;
                    printf("Sobra simobolo de cierre\n");
                }
                else{
                    sacaP(&P, &extraido);
                    if((car == ')' && extraido != '(')|| (car == '}' && extraido != '{')|| (car == ']' && extraido != '[')){
                        balanceado = 0;
                        printf("Simbolos cruzados\n");
                    }
                }
        }
        scanf(" %c", &car);
    }
}


int main()
{
    compruebaParentesis();
    return 0;
}

