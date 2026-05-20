/*Dado un árbol binario proveniente de la conversión de un árbol general:
a) hallar la cantidad de nodos que habia en niveles impares.
b) obtener el promedio de las claves cuyo grado era K (dato de entrada).
c) obtener la altura del árbol original
d) determinar el grado del árbol original. */

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
int cantNodosNivelesImpares(arbol a, int nivelActual);
float promV1(arbol a, int K);
int grado(arbol a);
int suma(arbol a, int K);
int cantNodos(arbol a, int K);
void acumula(arbol a, int k, int *suma, int *cantidad);
float promV2(arbol a, int k);

int main(){
    arbol a;
    int gr;
    addnodo(&a, 10); // Raíz
    addnodo(&a->izq, 1); // Primer hijo de 5
    addnodo(&a->izq->der, 2); // Primer hijo de 3
    addnodo(&a->izq->der->izq, 4); // Hermano de 2 (segundo hijo de 3)
    addnodo(&a->izq->der->izq->der, 5);
    addnodo(&a->izq->der->der, 3);
    addnodo(&a->izq->der->der->izq, 6);
    addnodo(&a->izq->der->der->izq->izq, 7);
    addnodo(&a->izq->der->der->izq->izq->izq, 10);
    addnodo(&a->izq->der->der->izq->izq->der, 8);
    printf("Cantidad de nodos en niveles impares: %d\n", cantNodosNivelesImpares(a, 1));  //El nivel se incializa en 1.

    printf("Ingrese grado: ");
    scanf("%d", &gr);
    printf("El promedio de las claves cuyo grado era %d es: %5.2f\n", gr, promV1(a, gr));
    printf("El promedio de las claves cuyo grado era %d es: %5.2f\n", gr, promV2(a, gr));
    return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int cantNodosNivelesImpares(arbol a, int nivelActual){
    if(a != NULL)
        if(nivelActual % 2 != 0)
            return 1 + cantNodosNivelesImpares(a->izq, nivelActual + 1) + cantNodosNivelesImpares(a->der, nivelActual);
        else
            return cantNodosNivelesImpares(a->izq, nivelActual + 1) + cantNodosNivelesImpares(a->der, nivelActual);
    else
        return 0;
}

//Ejercicio b) En esta version recorro el arbol dos veces... ineficiente...
int grado(arbol a){
    int cont = 0;
    a = a->izq;
    while(a != NULL){
        cont++;
        a = a->der;
    }
    return cont;
}

int cantNodos(arbol a, int K){
    if(a != NULL){
        if(grado(a) == K)
            return 1 + cantNodos(a->izq, K) + cantNodos(a->der, K);
        else
            return cantNodos(a->izq, K) + cantNodos(a->der, K);
    }
    else
        return 0;
}


int suma(arbol a, int K){
    if(a != NULL)
        if(grado(a) == K)
            return a->dato + suma(a->izq, K) + suma(a->der, K);
        else
            return suma(a->izq, K) + suma(a->der, K);
    else
        return 0;
}

float promV1(arbol a, int K){
    int cantidad = cantNodos(a, K);
    if(cantidad > 0)
        return (float)suma(a, K) / cantidad;
    else
        return 0;
}

//Ejercicio b) Version 2. Recorro una sola vez el arbol.
void acumula(arbol a, int k, int *suma, int *cantidad){
    int gr;
    if(a != NULL){
        gr = grado(a);
        if(gr == k){
            (*suma) += a->dato;
            (*cantidad)++;
        }
        acumula(a->izq, k , suma, cantidad);
        acumula(a->der, k, suma, cantidad);
    }
}

float promV2(arbol a, int k){
    int suma = 0;
    int cantidad = 0;
    acumula(a, k, &suma, &cantidad);
    if(cantidad > 0)
        return (float)suma/cantidad;
    else
        return 0;
}

//Ejercicio c)
int profundidad(arbol a){
    int profIzq, profDer;
    if(a != NULL){
        profIzq = 1 + profundidad(a->izq);  //Voy al hijo del nodo del arbol general
        profDer = profundidad(a->der);      //Voy al hermano del nodo del arbol general
        if(profIzq > profDer)
            return profIzq;
        else
            return profDer;
    }
    else
        return 0;
}
