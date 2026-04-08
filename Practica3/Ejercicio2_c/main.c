/*Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada. */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

void leerMatriz(int mat[][DIM], int *n);
int minimo(int mat[][DIM], int i, int j, int n);

int main()
{
    int mat[DIM][DIM], n;
    leerMatriz(mat, &n);
    printf("El minimo de la matriz es: %d", minimo(mat, n - 1, n - 1, n - 1));
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

int minimo(int mat[][DIM], int i, int j, int n){       //Recorro por filas desde el ultimo elemento
    if(i == 0 && j == 0)
        return mat[i][j];
    else{
        if(j > 0)
            if(mat[i][j] < minimo(mat, i, j - 1, n))
                return mat[i][j];
            else
                return minimo(mat, i, j - 1, n);
        else
            if(mat[i][j] < minimo(mat, i - 1, n, n))
                return mat[i][j];
            else
                return minimo(mat, i - 1, n, n);
    }
}
