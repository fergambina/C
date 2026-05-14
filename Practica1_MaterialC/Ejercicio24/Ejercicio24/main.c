/* Desarrollar un programa que lea una matriz de enteros de NxM y:
a) busque la posición de un valor x (puede no existir)
b) muestre el promedio de cada columna de la matriz.
c) muestre para cada fila que tenga al menos un cero la cantidad de elementos que superan el
promedio de la matriz */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

void leerMatriz(int mat[][DIM], int *n, int *m);
void buscaPos(int mat[][DIM], int n, int m, int x);
void promedioPorColumna(int mat[][DIM], int n, int m);
float promedioMatriz(int mat[][DIM], int n, int m);
void cantidadDeElementosSuperanAlPromedio(int mat[][DIM], int n, int m);

int main()
{
    int mat[DIM][DIM], n, m, x;
    leerMatriz(mat, &n, &m);
    printf("\n");
    printf("Ingrese un valor: ");
    scanf("%d", &x);
    buscaPos(mat, n, m, x);
    printf("\n");
    promedioPorColumna(mat, n, m);
    printf("\n");
    cantidadDeElementosSuperanAlPromedio(mat, n, m);
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

void buscaPos(int mat[][DIM], int n, int m, int x){
    int i = 0, j, encontrado = 0, fila = -1, columna = -1;
    while (i < n && !encontrado){
        j = 0;
        while(j < m && !encontrado){
            if(mat[i][j] == x){
                encontrado = 1;
                fila = i;
                columna = j;
            }
            else
                j++;
        }
        if(!encontrado)
            i++;
    }
    if(encontrado)
        printf("El valor %d se encuentra en la fila %d y columna %d.\n", x, fila, columna);
    else
        printf("El valor %d no fue encontrado.\n", x);
}

void promedioPorColumna(int mat[][DIM], int n, int m){
    int i, j, suma;
    for(j = 0; j < m; j++){
        suma = 0;
        for(i = 0; i < n; i++){
            suma += mat[i][j];
        }
        printf("El promedio de la columna %d es %5.2f\n", j, (float) suma / n);
    }
}


float promedioMatriz(int mat[][DIM], int n, int m){
    int i, j, suma = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            suma += mat[i][j];

    return (float) suma/(n*m);
}

void cantidadDeElementosSuperanAlPromedio(int mat[][DIM], int n, int m){
    int i, j, filaTieneCero, cantElem;
    float prom;
    prom = promedioMatriz(mat, n, m);
    for(i = 0; i < n; i++){
        cantElem = 0;
        filaTieneCero = 0;
        j = 0;
        while(j < m && !filaTieneCero)
            if(mat[i][j] == 0)
                filaTieneCero = 1;
            else
                j++;
        if(filaTieneCero){
            for(j = 0; j < m; j++)
                if(mat[i][j] > prom)
                    cantElem++;
            printf("La cantidad de elementos de la fila %d que superan al promedio %5.2f es %d\n", i, prom, cantElem);
        }
    }
}
