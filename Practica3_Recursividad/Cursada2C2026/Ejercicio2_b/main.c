/*Sea A un arreglo de reales y un valor X real ingresado por teclado, se pide determinar en
que posición se encuentra la primera ocurrencia de X o -1 en caso de no encontrarlo.
Implementar:
I.
II.
Considerando el arreglo desordenado, una búsqueda lineal recursiva.
Para un arreglo ordenado en forma ascendente, una búsqueda binaria recursiva. */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30


void leerVector(float v[], int *n);
int busquedaLineal(float v[], int i, int n, float x);
int busquedaBinaria(float v[], int i, int n, float x);
//int busquedaLineal(float v[], int n, float x);

int main()
{
    float v[DIM], x;
    int n;
    leerVector(v, &n);
    printf("Ingrese un valor : ");
    scanf("%f", &x);
    printf("El valor %.2f se encuentra en la posicion (-1 si no existe): %d\n", x, busquedaLineal(v, n - 1, x));
    printf("El valor %.2f se encuentra en la posicion (-1 si no existe): %d", x, busquedaBinaria(v, 0, n - 1, x));
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

int busquedaLineal(float v[], int i, int n, float x){  //Encuentra la primer ocurrencia de X (recorro desde el inicio al final)
    if(i > n)
        return -1;
    else
        if(v[i] == x)
            return i;
        else
            return busquedaLineal(v, i + 1, n, x);

}

int busquedaBinaria(float v[], int i, int n, float x){
    int medio;
    if(i > n)
        return -1;
    else{
        medio = (i + n) / 2;
        if(v[medio] == x)
            return medio;
        else
            if(v[medio] < x)
                return busquedaBinaria(v, medio + 1, n, x);   //Me muevo hasta medio + 1 si el valor de la posicion donde estoy parado es menor que x.
            else
                return busquedaBinaria(v, i, medio - 1, x);
    }


/*Busquedas sin variable i (recorro desde el final hasta el inicio)  --> Encuentra la ultima ocurrencia de X.
int busquedaLineal(float v[], int n, float x){
    if(n < 0)
        return -1;
    else{
        if(v[n] == x)
            return n;
        else
            return busquedaLineal(v , n - 1, x);
    }

}*/
