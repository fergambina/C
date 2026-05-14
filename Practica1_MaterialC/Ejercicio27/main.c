/*Desarrollar una función que a partir de una matriz de NxM elementos enteros, devuelva en un
arreglo de structs, fila, columna y valor de las componentes de la matriz divisibles por N+M */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

typedef struct {
    int fila, columna, valor;
} TComponente;

void leerMatriz(int mat[DIM][DIM], int *n, int *m);
void generarArreglo(int mat[DIM][DIM], int n, int m, TComponente componentes[2*DIM], int *k);

int main()
{
    int mat[DIM][DIM], n, m, k = 0;
    TComponente componentes[2*DIM];
    leerMatriz(mat, &n, &m);
    generarArreglo(mat, n, m, componentes, &k);
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

void generarArreglo(int mat[DIM][DIM], int n, int m, TComponente componentes[2*DIM], int *k){
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(mat[i][j] % (n + m) == 0){
                componentes[*k].fila = i;
                componentes[*k].columna = j;
                componentes[*k].valor = mat[i][j];
                (*k)++;
            }
}
