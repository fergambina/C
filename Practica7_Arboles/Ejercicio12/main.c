/*Determinar cuántos elementos de un ABB son mayores que A y menores que B. A y B son
parámetros de entrada.*/

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
void cantElemMayoresAyMenoresB(arbol a, int A, int B, int *cant);
int main()
{
     arbol a;
     int A, B, cant = 0;
     addnodo(&a, 5);  // Raíz

     // Subárbol izquierdo (todos MENORES que 5)
     addnodo(&a->izq, 3);
     addnodo(&a->izq->izq, 1);
     addnodo(&a->izq->der, 4);
     addnodo(&a->izq->izq->der, 2);  // 2 > 1 pero < 5

     // Subárbol derecho (todos MAYORES que 5)
     addnodo(&a->der, 8);
     addnodo(&a->der->izq, 6);  // 6 > 5 pero < 8

     printf("Ingrese A: ");
     scanf("%d", &A);
     printf("Ingrese B: ");
     scanf("%d", &B);
     cantElemMayoresAyMenoresB(a, A, B, &cant);
     printf("Cantidad de elementos que son mayores que %d y menores que %d: %d", A, B, cant);


     return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cantElemMayoresAyMenoresB(arbol a, int A, int B, int *cant){  //incializo cant en 0 en main
    if(a != NULL){
        if(a->dato > A && a->dato < B){
            (*cant)++;
            cantElemMayoresAyMenoresB(a->izq, A, B, cant);
            cantElemMayoresAyMenoresB(a->der, A, B, cant);
        }
        else{
            if(a->dato <= A)
                cantElemMayoresAyMenoresB(a->der, A, B, cant);
            else
                if(a->dato >= B)
                    cantElemMayoresAyMenoresB(a->izq, A, B , cant);
        }
    }
}
