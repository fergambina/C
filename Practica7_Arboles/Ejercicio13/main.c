/*Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente. */

#include <stdio.h>
#include <stdlib.h>
#define DIM 40

typedef char TElementoA;
typedef struct nodo{
        TElementoA dato;
        struct nodo *izq;
        struct nodo *der;
}nodo;
typedef nodo *arbol;

void addnodo(arbol* a, TElementoA e);
void generaArreglo(arbol a, char v[], int *dimV);


int main()
{
     arbol a;
     char v[DIM];
     int i, dimV = 0;
     addnodo(&a, 'F');  // Raíz

     addnodo(&a->izq, 'C');
     addnodo(&a->izq->izq, 'A');
     addnodo(&a->izq->der, 'D');

     addnodo(&a->der, 'G');

     generaArreglo(a, v, &dimV);
     for(i = 0; i < dimV; i++)
        printf("%c\t", v[i]);

     return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void generaArreglo(arbol a, char v[], int *dimV){
    if(a != NULL){
        generaArreglo(a->der, v, dimV);
        v[*dimV] = a->dato;
        (*dimV)++;
        generaArreglo(a->izq, v, dimV);
    }
}
