/*2) Dada una matriz de nxn de caracteres, desarrollar una función recursiva void que obtenga y muestre
la cantidad de vocales por columna. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void informaColumnVoc(char M[][MAX], int i, int j, int n, int cont){
    if(j <= n){
        if(i <= n){
            if(esVocal(M[i][j]))
                cont++;
            informaColumnVoc(M, i + 1, j, n, cont);
        }
        else{
            printf("%d\t%d\n", j + 1, cont);
            informaColumnVoc(M, 0, j + 1, n, 0);
        }
    }
}

//Invocacion: informaColumnVoc(M, 0, 0, n - 1, 0);
