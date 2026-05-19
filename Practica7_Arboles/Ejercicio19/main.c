/* Dado un árbol binario que proviene de la transformación de un bosque, determinar qué
cantidad de árboles lo componían. */

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
int cantArboles(arbol a);

int main(){
     arbol a;

     //Primer arbol del bosque
     addnodo(&a, 5);
     addnodo(&a->izq, 10);
     addnodo(&a->izq->der, 20);

     //Segundo arbol del bosque
     addnodo(&a->der, 8);
     addnodo(&a->der->izq, 3);
     addnodo(&a->der->izq->der, 6);

     //Tercer arbol del bosque
     addnodo(&a->der->der, 4);
     addnodo(&a->der->der->izq, 1);
     addnodo(&a->der->der->izq->der, 2);

     printf("Cantidad de arboles del bosque: %d", cantArboles(a));

     return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int cantArboles(arbol a){
    int cont = 0;
    while(a != NULL){
        cont++;
        a = a->der;
    }
    return cont;
}
