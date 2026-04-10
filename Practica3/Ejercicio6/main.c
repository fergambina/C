/* Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par. */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30


void leerMatriz(int mat[][DIM], int *n, int *m);

int main()
{
    int mat[DIM][DIM], n, m;
    leerMatriz(mat, &n, &m);
    return 0;
}

void leerMatriz(int mat[][DIM], int *n, int *m){
    int i, j;
    printf("Ingrese cantidad de filas: ");        //Optimizar con un do...while para verificar que el usuario haya ingresado bien la cantidad
    scanf("%d", n);                               //de filas y columnas.
    printf("Ingrese cantidad de columnas: ");     //n y m podria ser unsigned int.
    scanf("%d", m);
    for(i = 0; i < *n; i++)
        for(j = 0; j < *m; j++){
            printf("Ingrese componente mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
}

void mayorFilaAnterior(int mat[][DIM], int i, int j, int n, int m, int sumaAct, int sumaAnt){
    if(i > n)
        return 1;
    else{
        if(j <= m)
            return mayorFilaAnterior(mat, i, j + 1, n, m, mat[i][j] + sumaAct, sumaAnt);



    }
}
