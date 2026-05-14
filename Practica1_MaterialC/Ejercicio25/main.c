/*Leer el nombre y la edad de N personas, calcular e imprimir:
a) el listado de nombres de las personas de más de X años (X es dato).
b) el porcentaje de las personas mayores de edad (sobre el total). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100

int main()
{
    char nombres[DIM][DIM], temp[DIM];
    unsigned int edades[DIM], edad, n, i, x, k = 0, cantMayor = 0;
    printf("Ingrese X: ");
    scanf("%d", &x);
    do{
        printf("Ingrese cantidad de personas: ");
        scanf("%u", &n);
    }while(n < 0);
    for(i = 0 ; i < n; i++){
        printf("Ingrese nombre: ");
        scanf("%[^\n]", &temp[i]);
        printf("Ingrese edad: ");
        scanf("%u", &edades[i]);
        if(edad > x){
            strcpy(nombres[k],temp);
            k++;
        }
        if(edad >= 18)
            cantMayor += 1;
    }
    printf("Personas con mas de %d anios: ", x);
    for(i = 0; i < k; k++)
        printf("%s\n", nombres[k]);

    printf("Porcentaje de personas mayores de edad: %5.2f", (float)cantMayor*100 / n);

    return 0;
}
