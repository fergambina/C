/* Retornar el valor mínimo de un ABB.*/

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
int minimoABB(arbol a);

int main()
{
     arbol a;

     addnodo(&a, 5);  // Raíz

     // Subárbol izquierdo (todos MENORES que 5)
     addnodo(&a->izq, 3);
     addnodo(&a->izq->izq, 1);
     addnodo(&a->izq->der, 4);
     addnodo(&a->izq->izq->der, 2);  // 2 > 1 pero < 5

     // Subárbol derecho (todos MAYORES que 5)
     addnodo(&a->der, 8);
     addnodo(&a->der->izq, 6);  // 6 > 5 pero < 8

     printf("El minimo del ABB es: %d", minimoABB(a));
}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}


int minimoABB(arbol a){  //Para arboles no vacios
    arbol aux;
    aux = a;
    while(aux->izq != NULL)
        aux = aux->izq;
    return aux->dato;
}
