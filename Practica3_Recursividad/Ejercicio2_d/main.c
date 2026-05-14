#include <stdio.h>
#include <stdlib.h>
#define DIM 30

void leerMatriz(int mat[][DIM], int *n, int *m);
int maximoFila(int mat[][DIM], int i, int j);
void generaVectorMaximosFila(int mat[][DIM], int i, int m, int vec[]);
void escribirVector(int vec[], int n);

int main()
{
    int mat[DIM][DIM], vec[DIM], n, m;
    leerMatriz(mat, &n, &m);
    generaVectorMaximosFila(mat, n - 1, m - 1, vec);
    printf("\n");
    escribirVector(vec, n);
    return 0;
}

void escribirVector(int vec[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d\n", vec[i]);

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

int maximoFila(int mat[][DIM], int i, int j){
    int maxResto;
    if(j == 0)
        return mat[i][j];
    else{
        maxResto = maximoFila(mat, i, j - 1);
        if(mat[i][j] > maxResto)
            return mat[i][j];
        else
            return maxResto;
    }
}

void generaVectorMaximosFila(int mat[][DIM], int i, int m, int vec[]){
    if(i >= 0){
        vec[i] = maximoFila(mat, i, m);
        generaVectorMaximosFila(mat, i - 1, m, vec);
    }
}
