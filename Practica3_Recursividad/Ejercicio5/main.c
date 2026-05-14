/*Determinar mediante una función “lógica” si una matriz cuadrada de dimensión NxN es
simétrica (aij = aji) con respecto a su diagonal. */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

void leerMatriz(int mat[][DIM], int *n);
int simetrica(int mat[][DIM], int i, int j);

int main()
{
    int mat[DIM][DIM], n;
    leerMatriz(mat, &n);
    if(simetrica(mat, n - 1, n - 2))
        printf("La matriz es simetrica.");
    else
        printf("La matriz no es simetrica.");
    return 0;
}


void leerMatriz(int mat[][DIM], int *n){
    int i, j;
    printf("Ingrese dimension de la matriz: ");
    scanf("%d", n);
    for(i = 0; i < *n; i++)
        for(j = 0; j < *n; j++){
            printf("Ingrese componente mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
}

int simetrica(int mat[][DIM], int i, int j){
    if(i < 0)
        return 1;
    else{
        if(j >= 0)
            if(mat[i][j] == mat[j][i])
                return simetrica(mat, i, j - 1);
            else
                return 0;
        else
            return simetrica(mat, i - 1, i - 2);
    }
}
