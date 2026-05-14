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

int main(){
     arbol a;
     int x;
     /* carga arbol ejemplo. Ej 1 */
     addnodo(&a, 5);
     addnodo(&a->izq, 8);
     addnodo(&a->izq->izq, 3);
     addnodo(&a->izq->der, 6);

     addnodo(&a->der, 4);
     addnodo(&a->der->izq, 1);
     addnodo(&a->der->izq->der, 2);

     return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
