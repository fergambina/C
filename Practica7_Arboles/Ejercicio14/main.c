/*Desarrollar una función que compruebe que si un árbol binario es un ABB. */

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
int esABB(arbol a, int min, int max);

int main()
{
     arbol a;
     int min = -999, max = 999;
     addnodo(&a, 5);  // Raíz

     // Subárbol izquierdo (todos MENORES que 5)
     addnodo(&a->izq, 3);
     addnodo(&a->izq->izq, 1);
     addnodo(&a->izq->der, 4);
     addnodo(&a->izq->izq->der, 2);  // 2 > 1 pero < 5

     // Subárbol derecho (todos MAYORES que 5)
     addnodo(&a->der, 8);
     addnodo(&a->der->izq, 6);  // 6 > 5 pero < 8

     if(esABB(a, min, max))
        printf("El arbol es ABB");
     else
        printf("El arbol no es ABB");


     return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int esABB(arbol a, int min, int max){
    if(a != NULL){
        if(a->dato <= min || a->dato >= max)
            return 0;
        else
            return esABB(a->izq, min, a->dato) && esABB(a->der, a->dato, max);
    }
    else
        return 1;
}
