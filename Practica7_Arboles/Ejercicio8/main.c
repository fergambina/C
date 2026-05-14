/*El draw de un torneo de tenis se representa mediante un árbol binario invertido. Desarrollar
subprogramas que muestren:
a) el nombre del ganador.
b) los nombres de los 2 finalistas.
c) los nombres de los 4 semifinalistas.
d) los nombres de todos los competidores y la cantidad.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

typedef char TElementoA[DIM];
typedef struct nodo{
        TElementoA dato;
        struct nodo *izq;
        struct nodo *der;
}nodo;
typedef nodo *arbol;

void addnodo(arbol* a, TElementoA e);
void ganador(arbol a);
void finalistas(arbol a);
void semifinalistas(arbol a);
void competidores(arbol a, int *cont);

int main(){
     arbol a;
     int cont = 0;
     /* carga arbol ejemplo. Ej 1 */
     addnodo(&a, "A");
     addnodo(&a->izq, "A");
     addnodo(&a->izq->izq, "A");
     addnodo(&a->izq->der, "B");

     addnodo(&a->der, "C");
     addnodo(&a->der->izq, "C");
     addnodo(&a->der->der, "D");

     ganador(a);
     finalistas(a);
     semifinalistas(a);

     competidores(a, &cont);
     printf("Cantidad de competidores: %d", cont);

     return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    strcpy((*a)->dato, e);
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void ganador(arbol a){
    if(a != NULL)
        printf("Ganador: %s\n", a->dato);
}

void finalistas(arbol a){
    if(a != NULL && a->izq != NULL && a->der != NULL){
        printf("Finalista 1: %s\n", a->izq->dato);
        printf("Finalista 2: %s\n", a->der->dato);
    }
}

void semifinalistas(arbol a){
    if(a != NULL && a->izq->izq != NULL && a->izq->der != NULL && a->der->izq != NULL && a->der->der != NULL){
        printf("Semifinalista 1: %s\n", a->izq->izq->dato);
        printf("Semifinalista 2: %s\n", a->izq->der->dato);
        printf("Semifinalista 3: %s\n", a->der->izq->dato);
        printf("Semifinalista 4: %s\n", a->der->der->dato);
    }
}

void competidores(arbol a, int *cont){
    if(a != NULL){
        if(a->izq == NULL && a->der == NULL){
            printf("Competidor: %s\n", a->dato);
            (*cont)++;
        }
        competidores(a->izq, cont);
        competidores(a->der, cont);
    }
}
