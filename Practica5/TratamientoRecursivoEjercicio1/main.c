/* Resolver recursivamente. En una Pila se han almacenado valores enteros, se desea saber cuántos
(excepto los dos primeros) son iguales al promedio de los dos anteriores, la pila puede perderse.
Por ejemplo:
Pila(tope) : 1 3 2 0 1 5 3 5    Rta: 3 */

#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int main()
{
    TPila P;
    int cont = 0;
    cargaPila(&P);
    prom2(&P, &cont);
    printf("Cantidad de elementos iguales al promedio de los dos anteriores: %d", cont);
    return 0;
}

void prom2(TPila *P, int *cont){
    TElementoP num1, num2;
    if(!vaciaP(*P)){
        sacaP(P, &num1);
        if(!vaciaP(*P)){
            sacaP(P, &num2);
            if(!vaciaP(*P)){
                if(consultaP(*P) == (num1 + num2) / 2.0)
                    (*cont)++;
                poneP(P, num2);
                prom2(P, cont);
            }
        }
    }
}
