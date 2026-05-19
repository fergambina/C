/*Desarrollar funciones para:
a) calcular la profundidad de un árbol binario.
b) retornar la longitud de la cadena más larga de un árbol binario de cadenas.
c) devolver la cantidad de hijos derechos que contiene un árbol binario*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

typedef char TElememtoA[30];
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
void profundidad(arbol a, int alturaActual, int *alturaMaxima);
int profundidadV2(arbol a);
void longCadenaMasLarga(arbol a, int *longMasLarga);
void hijosDerecho(arbol a, int *cantHijosDer);

int main(){
     arbol a;
     int alturaMaxima = -1, longMasLarga = -1, cantHijosDer = 0;

     addnodo(&a, "a");

     addnodo(&a->izq, "bc");
     addnodo(&a->izq->der, "efgh");
     addnodo(&a->izq->der->izq, "cd");
     addnodo(&a->izq->der->der, "e");

     addnodo(&a->der, "b");

     profundidad(a, 0, &alturaMaxima);
     printf("La profundidad (version void) del arbol es: %d\n", alturaMaxima);
     printf("La profundidad (version int) del arbol es: %d\n", profundidadV2(a));
     longCadenaMasLarga(a, &longMasLarga);
     printf("Longitud de la cadena mas larga: %d\n", longMasLarga);
     hijosDerecho(a, &cantHijosDer);
     printf("Cantidad de hijos derecho: %d", cantHijosDer);

 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    strcpy((*a)->dato, e);
    (*a)->izq = NULL;
    (*a)->der = NULL;
}


void profundidad(arbol a, int alturaActual, int *alturaMaxima){
    if(a != NULL){
        if(a->izq == NULL && a->der == NULL){
            if(alturaActual > *alturaMaxima)
                *alturaMaxima = alturaActual;
        }
        profundidad(a->izq, alturaActual + 1, alturaMaxima);
        profundidad(a->der, alturaActual + 1, alturaMaxima);
    }
}

int profundidadV2(arbol a){
    int profIzq, profDer;
    if(a == NULL)
        return -1;
    else{
        profIzq = profundidadV2(a->izq);
        profDer = profundidadV2(a->der);
        if(profIzq > profDer)
            return 1 + profIzq;
        else
            return 1 + profDer;
    }
}



void longCadenaMasLarga(arbol a, int *longMasLarga){
    int longActual;
    if(a != NULL){
        longActual = strlen(a->dato);
        if(longActual > *longMasLarga)
            *longMasLarga = longActual;
        longCadenaMasLarga(a->izq, longMasLarga);
        longCadenaMasLarga(a->der, longMasLarga);
    }
}

int longCadenaMasLargaV2(arbol a){
    int longActual, longMaxIzq, longMaxDer;
    if(a == NULL)
        return 0;
    else{
        longActual = strlen(a->dato);
        longMaxIzq = longCadenaMasLargaV2(a->izq);
        longMaxDer = longCadenaMasLargaV2(a->der);
        if(longActual >= longMaxIzq && longActual >= longMaxDer)
            return longActual;
        else
            if(longMaxIzq >= longActual && longMaxIzq >= longMaxDer)
                return longMaxIzq;
            else
                return longMaxDer;
    }

}


void hijosDerecho(arbol a, int *cantHijosDer){
    if(a != NULL){
        if(a->der != NULL)
            (*cantHijosDer)++;
        hijosDerecho(a->izq, cantHijosDer);
        hijosDerecho(a->der, cantHijosDer);
    }
}

int cantHijosDerchos(arbol a){
    if(a == NULL)
        return 0;
    else{
        if(a->der != NULL)
            return 1 + cantHijosDerchos(a->izq) + cantHijosDerchos(a->der);
        else
            return cantHijosDerchos(a->izq) + cantHijosDerchos(a->der);
    }
}
