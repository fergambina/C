/*Desarrollar un programa que cree dinámicamente un arreglo de números reales que contenga
N elementos (N es ingresado por teclado). Ingresar sus elementos y mostrar aquellos que sean
positivos utilizando aritmética de punteros. Al finalizar, liberar la memoria solicitada en tiempo
de ejecución. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *arreglo;
    int n, i;
    printf("Ingrese cantidad de elementos: ");
    scanf("%d", &n);
    arreglo = (float *) malloc(n * sizeof(int));
    printf("Ingresando los numeros reales...");
    for(i = 0; i < n; i++){
        printf("Elemento [%d]: ", i);
        scanf("%f", arreglo + i);
    }
    printf("Mostrando los numeros positivos...");
    for(i = 0; i < n; i++)
        if(*(arreglo + i) > 0)
            printf("%.2f\n", *(arreglo + i));
    free(arreglo);
    return 0;
}
