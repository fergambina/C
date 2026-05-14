/*Dada una matriz A de NxM float, retornar la cantidad de veces que un valor X aparece en A
(realizar una versión void y otra int) */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

void leerMatriz(float mat[][DIM], int *n, int *m);
int apaX(float mat[][DIM], int i, int j, int m, float x);
void apaX2(float mat[][DIM], int i, int j, int m, float x, int *cant_apariciones);

int main()
{

    float mat[DIM][DIM], x;
    int n, m, cant_apariciones = 0;
    leerMatriz(mat, &n, &m);
    printf("Ingrese X: ");
    scanf("%f", &x);
    printf("Cantidad de apariciones de %5.2f: %d\n", x, apaX(mat, n - 1, m - 1, m - 1, x));
    apaX2(mat, n - 1, m - 1, m - 1, x, &cant_apariciones);
    printf("Cantidad de apariciones de %5.2f: %d", x, cant_apariciones);
    return 0;
}

void leerMatriz(float mat[][DIM], int *n, int *m){
    int i, j;
    printf("Ingrese cantidad de filas: ");        //Optimizar con un do...while para verificar que el usuario haya ingresado bien la cantidad
    scanf("%d", n);                               //de filas y columnas.
    printf("Ingrese cantidad de columnas: ");     //n y m podria ser unsigned int.
    scanf("%d", m);
    for(i = 0; i < *n; i++)
        for(j = 0; j < *m; j++){
            printf("Ingrese componente mat[%d][%d]: ", i, j);
            scanf("%f", &mat[i][j]);
        }
}

int apaX(float mat[][DIM], int i, int j, int m, float x){
    if(i >= 0)
        if(j >= 0)
            if(mat[i][j] == x)
                return 1 + apaX(mat, i, j - 1, m, x);
            else
                return apaX(mat, i, j - 1, m, x);
        else
            return apaX(mat, i - 1, m, m, x);
    else
        return 0;

}

void apaX2(float mat[][DIM], int i, int j, int m, float x, int *cant_apariciones){
    if(i >= 0){
        if(j >= 0){
            if(mat[i][j] == x)
                (*cant_apariciones)++;
            apaX2(mat, i, j - 1, m, x, cant_apariciones);
        }
        else
            apaX2(mat, i - 1, m, m, x, cant_apariciones);
    }
}
