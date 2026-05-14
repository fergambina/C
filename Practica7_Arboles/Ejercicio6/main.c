/*Dado un árbol binario de cadenas de caracteres retornar el nivel en el que se encuentra la
cadena más larga que comienza con A */


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
void nivelCadMasLargaA(arbol a, int *longMasLarga, int nivelActual, int *nivelMasLarga);

int main(){
     arbol a;
     int longMasLarga = 0, nivelMasLarga = 0;
     /* carga arbol ejemplo. Ej 1 */
     addnodo(&a, "bc");
     addnodo(&a->izq, "Ab");
     addnodo(&a->izq->izq, "e");
     addnodo(&a->izq->der, "ABC");

     addnodo(&a->der, "bd");

     nivelCadMasLargaA(a, &longMasLarga, 0, &nivelMasLarga);
     printf("Nivel en el que se encuentra la cadena más larga que comienza con A: %d", nivelMasLarga);

 return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    strcpy((*a)->dato, e);
    (*a)->izq = NULL;
    (*a)->der = NULL;
}



void nivelCadMasLargaA(arbol a, int *longMasLarga, int nivelActual, int *nivelMasLarga){
    int longActual;
    if(a != NULL){
        if(a->dato[0] == 'A'){
            longActual = strlen(a->dato);
            if(longActual > *longMasLarga){
                *longMasLarga = longActual;
                *nivelMasLarga = nivelActual;
            }
        }
        nivelCadMasLargaA(a->izq, longMasLarga, nivelActual + 1, nivelMasLarga);
        nivelCadMasLargaA(a->der, longMasLarga, nivelActual + 1, nivelMasLarga);
    }
}
