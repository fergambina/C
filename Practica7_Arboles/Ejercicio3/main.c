/*Desarrollar funciones para:
a) devolver la suma de los elementos múltiplos de 3 de un árbol binario.
b) retornar la cantidad de hojas de un árbol binario.
c) informar si un valor recibido como parámetro se encuentra en un árbol binario.*/

#include <stdio.h>
#include <stdlib.h>

typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);

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

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}


void sumaMultiplos3(arbol a, int *suma){
    if(a != NULL){
        if(a->dato % 3 == 0)
            *suma += a->dato;
        sumaMultiplos3(a->izq, suma);
        sumaMultiplos3(a->der, suma);
    }
}

int sumaMultiplos3V2(arbol a){
    if(a == NULL)
        return 0;
    else{
        if(a->dato % 3 == 0)
            return a->dato + sumaMultiplos3V2(a->izq) + sumaMultiplos3V2(a->der);
        else
            return sumaMultiplos3V2(a->izq) + sumaMultiplos3V2(a->der);
    }
}


int cantHojas(arbol a){
    if(a != NULL){
        if(a->izq == NULL && a->der == NULL)
            return 1;
        else
            return cantHojas(a->izq) + cantHojas(a->der);
    }
    else
        return 0;
}

int esta(arbol a, int x){
    if(a != NULL)
        if(a->dato == x)
            return 1;
        else
            return esta(a->izq, x) || esta(a->der, x);
    else
        return 0;
}
