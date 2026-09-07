#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int main()
{
    printf("Hello world!\n");
    return 0;
}

//Desarrollar una funcion que genere un vector de N elementos con la suma de los elementos de cada fila de una matriz de N*N enteros.
void generaV(int mat[][MAX], int vec[MAX], int i, int j, int n){
    if(i >= 0){ //Si estoy en una fila valida
        vec[i] += mat[i][j];
        if(j > 0)
            generaV(mat, vec, i, j - 1, n);
        else
            generaV(mat, vec, i - 1, n, n);
    }
}


//Invocacion: generaV(mat, vec, n - 1, n - 1, n);
