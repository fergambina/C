/*Corregir la siguiente función, la cual retorna si un valor recibido como parámetro se encuentra
en un ABB cuyas claves son enteros.
int busca(arbol a, int* x) {
  if (a != NULL)
     return 0;
  else
     if(x = a.dato)
         return 1;
     else
       if(x < a.dato)
          return busca(a.der, *x);
       else
          return busca(a->izq, *x);
} */

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
int busca(arbol a, int x);

int main(){
     arbol a;
     int x;

     addnodo(&a, 5);  // Raíz

     // Subárbol izquierdo (todos MENORES que 5)
     addnodo(&a->izq, 3);
     addnodo(&a->izq->izq, 1);
     addnodo(&a->izq->der, 4);
     addnodo(&a->izq->izq->der, 2);  // 2 > 1 pero < 5

     // Subárbol derecho (todos MAYORES que 5)
     addnodo(&a->der, 8);
     addnodo(&a->der->izq, 6);  // 6 > 5 pero < 8

     printf("Ingrese un numero: ");
     scanf("%d", &x);
     if(busca(a, x))
        printf("El numero %d esta en el arbol binario de busqueda", x);
     else
        printf("El numero %d no esta en el arbol binario de busqueda.", x);

     return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int busca(arbol a, int x){
    if(a != NULL){
        if(x == a->dato)
            return 1;
        else
            if(x < a->dato)
                return busca(a->izq, x);
            else
                return busca(a->der, x);
    }
    else
        return 0;
}
