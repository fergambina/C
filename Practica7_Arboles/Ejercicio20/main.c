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
float prom(arbol a, int K);
int grado(arbol a);
int suma(arbol a, int K);
int cantNodos(arbol a, int K);

int main(){
    arbol a;
    int gr;
    addnodo(&a, 5); // Raíz

    addnodo(&a->izq, 3); // Primer hijo de 5
    addnodo(&a->izq->izq, 2); // Primer hijo de 3
    addnodo(&a->izq->izq->der, 4); // Hermano de 2 (segundo hijo de 3)

    addnodo(&a->izq->der, 7); // Hermano de 3 (segundo hijo de 5)
    addnodo(&a->izq->der->izq, 6); // Primer hijo de 7

    addnodo(&a->izq->der->der, 1); // Hermano de 7 (tercer hijo de 5)
    addnodo(&a->izq->der->der->izq, 8); // Primer hijo de 1
    addnodo(&a->izq->der->der->izq->der, 9); // Hermano de 8 (segundo hijo de 1)
    printf("Cantidad de nodos en niveles impares: %d\n", cantNodosNivelesImpares(a, 1));  //El nivel se incializa en 1.

    printf("Ingrese grado: ");
    scanf("%d", &gr);
    printf("El promedio de las claves cuyo grado era %d es: %5.2f\n", gr, prom(a, gr));
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

int grado(arbol a){
    int cont = 0;
    a = a->izq;
    while(a != NULL){
        cont++;
        a = a->der;
    }
    return cont;
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

float prom(arbol a, int K){
    int cantidad = cantNodos(a, K);
    if(cantidad > 0)
        return (float)suma(a, K) / cantidad;
    else
        return 0;
}

int profundidad(arbol a){
    int profIzq, profDer;
    if(a != NULL){
        profIzq = 1 + profundidad(a->izq);
        profDer = profundidad(a->der);
        if(profIzq > profDer)
            return profIzq;
        else
            return profDer;

    }
    else
        return -1;
}
