/*Desarrollar un programa que reciba una expresión aritmética que contemple las cuatro
operaciones básicos (+, -, * y /) en notación postfija (polaca invertida) y devuelva su valor, a
menos que ocurra un error porque la expresión no sea válida. Las expresiones postfijas no
necesitan paréntesis para especificar el orden de las operaciones. Ej: 5 *(1+3) en notación
posfija es 5 1 3 + *. Los operandos se limitan a números de un solo dígito y son leídos como
caracteres, de la misma manera que los operadores. */

#include <stdio.h>
#include <stdlib.h>
#include "PilaEstatica.h"
#include "ColaEstatica.h"

void cargaExpresion(TCola *C);
void procesaExpresion(TCola *C, int *res);

int main()
{
    TCola C;
    int res;
    cargaExpresion(&C);
    procesaExpresion(&C, &res);
    if(res != - 999)
        printf("El resultado de la expresion es: %d", res);
    else
        printf("Expresion cargada invalida");
    return 0;
}

void cargaExpresion(TCola *C){
    FILE *arch;
    char car;
    iniciaC(C);
    arch = fopen("expresion.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, " %c", &car) == 1){
            poneC(C, car);
        }
        fclose(arch);
    }
    else
        printf("Archivo no existente...");
}

void procesaExpresion(TCola *C, int *resultado){
    TPila P;
    char car, res_char;
    int op1, op2, res, error = 0;
    iniciaP(&P);
    while(!vaciaC(*C) && !error){
        sacaC(C, &car);
        if(car >= '0' && car <= '9')
            poneP(&P, car - '0');
        else{
            if(!vaciaP(P)){
                sacaP(&P, &op1);
                if(!vaciaP(P)){
                    sacaP(&P, &op2);
                    switch(car){
                    case '+':
                            res = op2 + op1;
                            break;
                    case '-':
                            res = op2 - op1;
                            break;
                    case '*':
                            res = op2 * op1;
                            break;
                    case '/':
                            if(op1 != 0)
                                res = op2 / op1;
                            else
                                error = 1;
                            break;
                    default: error = 1;
                    }
                    if(!error)
                        poneP(&P, res);
                }
                else
                    error = 1;
            }
            else
                error = 1;
        }
    }
    if(error)
        *resultado = -999;
    else{
        if(!vaciaP(P)){
            sacaP(&P, &res);
            if(vaciaP(P))
                *resultado = res;
            else
                *resultado = -999;
        }
        else
            *resultado = -999;
    }
}
