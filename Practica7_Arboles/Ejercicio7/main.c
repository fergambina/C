/*Desarrollar una función que retorne la suma del contenido de aquellos nodos de un árbol
binario que tengan grado 1 y se encuentren en un nivel X que es dato.  */

#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo{
        TElementoA dato;
        struct nodo *izq;
        struct nodo *der;
}nodo;
typedef nodo *arbol;

void addnodo(arbol* a, TElementoA e);
void sumaNodosGrado1(arbol a, int nivel, int nivelActual, int *suma);

int main(){
     arbol a;
     int nivel, suma = 0;
     addnodo(&a, 1);

     addnodo(&a->izq, 2);
     addnodo(&a->izq->der, 5);
     addnodo(&a->izq->der->der, 8);
     addnodo(&a->izq->izq, 3);
     addnodo(&a->izq->izq->izq, 4);


     addnodo(&a->der, 6);
     addnodo(&a->der->der, 7);
     addnodo(&a->der->der->izq, 9);

     printf("Ingrese un nivel: ");
     scanf("%d", &nivel);
     sumaNodosGrado1(a, nivel, 1, &suma);
     printf("suma del contenido de aquellos nodos de un árbol binario que tengan grado 1 y se encuentren en el nivel %d: %d", nivel, suma);

     return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void sumaNodosGrado1(arbol a, int nivel, int nivelActual, int *suma){
    if(a != NULL){
        if(nivel == nivelActual)
            if((a->izq == NULL && a->der != NULL) || (a->izq != NULL && a->der == NULL))
                (*suma) += a->dato;
        sumaNodosGrado1(a->izq, nivel, nivelActual + 1, suma);
        sumaNodosGrado1(a->der, nivel, nivelActual + 1, suma);
    }
}

