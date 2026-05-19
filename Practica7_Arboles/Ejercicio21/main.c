/*Dado un árbol binario que proviene de la transformación de un bosque,
a) hallar la cantidad de árboles del bosque que tenían altura al menos K (dato de entrada)
b) generar un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.
c) verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada). */

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

int calculaAltura(arbol a){
    int alturaPorHijos, alturaPorHerm;
    if(a == NULL)
        return -1;
    else{
        alturaPorHijos = 1 + calculaAltura(a->izq);
        alturaPorHerm = calculaAltura(a->der);
        if(alturaPorHijos > alturaPorHerm)
            return alturaPorHijos;
        else
            return alturaPorHerm;
    }
}


int cantArboles(arbol a, int k){
    int altura, cont = 0;
    while(a != NULL){
        altura =  1 + calculaAltura(a->izq);
        if(altura >= k)
            cont++;
        a = a->der;
    }
    return cont;
}

//Insciso b)



int inicializaArreglo(int vec[]){
    int i;
    for(i = 0; i < DIM; i++)
        vec[i] = -999;
}

int buscaMaximo(arbol a){
    int maxIzq, maxDer, maximo;
    if(a == NULL){
        maximo = -999;
    }
    else{
        maxIzq = buscaMaximo(a->izq);
        maxDer = buscaMaximo(a->der);
    }

}


void generaArreglo(arbol a, int vec[], int *n){
    while(a != NULL){
        vec[*n] = buscaMaximo(a);
        (*n)++;
        a = a->der;
    }
}

