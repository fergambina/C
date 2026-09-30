#include <stdio.h>
#include <stdlib.h>
#define DIM 30

void leerVector(float v[], int *n);
float promedio(float v[], int i, int n);


int main()
{
    float v[DIM];
    int n;
    leerVector(v, &n);
    printf("El promedio de los elementos del vector es: %5.2f", promedio(v, n - 1, n));
    return 0;
}

void leerVector(float v[], int *n){
    int i;
    printf("Ingrese cantidad de componentes: ");
    scanf("%d", n);
    for(i = 0; i < *n; i++){
        printf("Ingrese v[%d] = ", i);
        scanf("%f", &v[i]);
    }
}

float promedio(float v[], int i, int n){
    if(i == 0)
        return v[i]/n;
    else
        return v[i]/n + promedio(v, i - 1, n);
}
