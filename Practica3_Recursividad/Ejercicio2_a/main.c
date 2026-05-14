#include <stdio.h>
#include <stdlib.h>
#define DIM 30

int suma(int v[], int n);
void leerVector(int v[], int *n);
void escribirVector(int v[], int n);
void escribirVectorInverso(int v[], int n);

int main()
{
    int v[DIM], n;
    leerVector(v, &n);
    printf("Suma = %d\n", suma(v, n - 1));
    printf("Vector cargado...\n");
    escribirVector(v, n - 1);
    printf("\n");
    printf("Vector cargando en orden inverso...\n");
    escribirVectorInverso(v, n - 1);
    return 0;
}

void leerVector(int v[], int *n){
    int i;
    printf("Ingrese cantidad de componentes: ");
    scanf("%d", n);
    for(i = 0; i < *n; i++){
        printf("Ingrese v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

int suma(int v[], int n){
    if(n == 0)
        return v[n];
    else
        return v[n] + suma(v, n - 1);
}

void escribirVector(int v[], int n){
    if(n >= 0){
        escribirVector(v, n - 1);
        printf("%d\t", v[n]);
    }
}

void escribirVectorInverso(int v[], int n){
    if(n >= 0){
        printf("%d\t", v[n]);
        escribirVectorInverso(v, n - 1);
    }
}
