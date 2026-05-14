/*Resolver recursivamente En una Pila se han almacenado valores enteros, se desea saber si están
ordenados de modo ascendente. No perder la pila.
Por ejemplo:
Pila(tope) : 1 2 7 10    Rta: OK */

#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int main()
{
    TPila P;
    int res = 1;
    cargaPila(&P);
    asc(&P, &res);
    if(res)
        printf("La pila esta ordenada ascendentemente.");
    else
        printf("La pila no esta ordenada ascendentemente.");
    return 0;
}

void asc(TPila *P, int *res){
    TElementoP num;
    if(vaciaP(*P)){
        sacaP(P, &num);
        if(!vaciaP(*P)){
            if(num > consultaP(*P))
                *res = 0;
            else
                asc(P, res);
        }
        poneP(P, num);
    }

}
