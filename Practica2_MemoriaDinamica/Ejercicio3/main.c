/*Implementar un programa que cree dinámicamente 3 variables enteras (pint1, pint2 y pint3),
muestre su suma y su producto. No utilizar estructuras iterativas. Asegurarse de administrar
correctamente la memoria e implementar una función para evitar duplicaciones de código en la
creación y lectura de cada variable. Desarrollar en primera instancia una función que retorne
un puntero a entero. Para cumplir con el paradigma de programación estructurada, convertir
en una función void que retorne el resultado como parámetro de salida. */

#include <stdio.h>
#include <stdlib.h>

int *leerNum1();
void leerNum2(int **ptr);

int main()
{
    int *pint1, *pint2, *pint3;
    pint1 = leerNum1();
    pint2 = leerNum1();
    pint3 = leerNum1();
    printf("%d + %d + %d = %d\n", *pint1, *pint2, *pint3, *pint1 + *pint2 + *pint3);
    printf("%d * %d * %d = %d\n", *pint1, *pint2, *pint3, *pint1 * *pint2 * *pint3);
    free(pint1);
    free(pint2);
    free(pint3);
    leerNum2(&pint1);  //Por que le paso la direccion del puntero? Para que lo modifique...
    leerNum2(&pint2);
    leerNum2(&pint3);
    printf("%d + %d + %d = %d\n", *pint1, *pint2, *pint3, *pint1 + *pint2 + *pint3);
    printf("%d * %d * %d = %d\n", *pint1, *pint2, *pint3, *pint1 * *pint2 * *pint3);
    free(pint1);
    free(pint2);
    free(pint3);
    return 0;
}

int *leerNum1(){
    int *aux = (int *) malloc(sizeof(int));
    printf("Ingrese un numero: ");
    scanf("%d", aux);
    return aux;
}

void leerNum2(int **ptr){              //El segundo asterisco es como el VAR de Pascal...
    *ptr = (int *)malloc(sizeof(int));
    printf("Ingrese un numero: ");
    scanf("%d", *ptr);    //Por que *ptr??
}
