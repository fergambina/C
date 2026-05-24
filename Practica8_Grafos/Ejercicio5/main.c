/*Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

void cargaMatAdy(int matAdy[][DIM], int vec[], int *N);
void mostrarMatAdy(int matAdy[][DIM], int N);
int gradoEntrada(int matAdy[][DIM], int vec[], int N, int vertice);
int buscaIndice(int vec[], int N, int vertice);
int gradoSalida(int matAdy[][DIM], int N, int vertice);
int gradoTotal(int matAdy[][DIM], int vec[], int N, int vertice);

int main()
{
    int matAdy[DIM][DIM], N, vertice;
    int vec[DIM];
    cargaMatAdy(matAdy, vec, &N);
    mostrarMatAdy(matAdy, N);
    printf("Ingrese vertice: ");
    scanf("%d", &vertice);
    printf("El grado de entrada del vertice %d es %d\n", vertice, gradoEntrada(matAdy, vec, N, vertice));
    printf("El grado de salida del vertice %d es %d\n", vertice, gradoSalida(matAdy, N, vertice));
    printf("El grado total del vertice %d es %d\n", vertice, gradoTotal(matAdy, vec, N, vertice));
    return 0;
}

void cargaMatAdy(int matAdy[][DIM], int vec[], int *N){
    int i, j;
    FILE *arch;
    arch = fopen("matrizAdyacencia.txt", "rt");
    fscanf(arch, "%d", N);
        for(i = 0; i < *N; i++){
            vec[i] = i + 1; //Vector paralelo a la matriz.
            for(j = 0; j < *N; j++)
                fscanf(arch, "%d", &matAdy[i][j]);
        }
    fclose(arch);
}

void mostrarMatAdy(int matAdy[][DIM], int N){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            printf("%d\t", matAdy[i][j]);
        printf("\n");
    }
}

//Ejercicio a) En esta version implemento el vector paralelo a la matriz. Asumo que el vertice ingresado existe.
int buscaIndice(int vec[], int N, int vertice){
    int i = 0;
    while(vec[i] != vertice)
        i++;
    return i;
}

int gradoEntrada(int matAdy[][DIM], int vec[], int N, int vertice){
    int id, i, cont = 0;
    id = buscaIndice(vec, N, vertice);
    for(i = 0; i < N; i++)
        if(matAdy[i][id] == 1)
            cont++;
    return cont;
}

//Ejercicio b) En este caso no uso el vector paralelo.
int gradoSalida(int matAdy[][DIM], int N, int vertice){
    int j, cont = 0;
    for(j = 0; j < N; j++)
        if(matAdy[vertice - 1][j] == 1)
            cont++;
    return cont;
}

int gradoTotal(int matAdy[][DIM], int vec[], int N, int vertice){
    if(matAdy[vertice - 1][vertice - 1] == 1)
        return gradoEntrada(matAdy, vec, N, vertice) + gradoSalida(matAdy, N, vertice) - 1; //Tiene bucle.
    else
        return gradoEntrada(matAdy, vec, N, vertice) + gradoSalida(matAdy, N, vertice);
}
