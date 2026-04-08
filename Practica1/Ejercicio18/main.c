/*Desarrollar un subprograma que duplique los elementos de un vector ubicados en las
posiciones pares. Implementar 3 veces utilizando for, while y do while*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30

void leerVector(int [], int *);
void mostrarVector(int [], int);
void duplicaConFor(int [], int);
void duplicaConWhile(int [], int);
void duplicaConDoWhile(int [], int);

int main()
{
    int v[MAX], n;
    leerVector(v, &n);
    printf("Vector original: \n");
    mostrarVector(v, n);
    duplicaConFor(v,n);
    mostrarVector(v, n);
    duplicaConWhile(v, n);
    mostrarVector(v, n);
    duplicaConDoWhile(v, n);
    mostrarVector(v, n);
    return 0;
}

void leerVector(int v[], int *n){
    int i;
    printf("Ingrese cantidad de componentes: ");
    scanf("%d", n);
    for(i = 0; i < *n; i++){
        printf("Ingrese componente %d: ", i);
        scanf("%d", &v[i]);
    }
}

void mostrarVector(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", v[i]);
    printf("\n");
}

void duplicaConFor(int v[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(i % 2 == 0)
            v[i] *= 2;
    }
}

void duplicaConWhile(int v[], int n){
    int i = 0;
    while(i < n){
        if(i % 2 == 0)
            v[i] *= 2;
        i++;
    }
}

void duplicaConDoWhile(int v[], int n){
    int i = 0;
    do{
      if(i % 2 == 0)
            v[i] *= 2;
        i++;
    }while(i < n);
}



