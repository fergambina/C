/*Corregir los errores en la siguiente función void, la cual genera un arreglo de caracteres con los
nodos de grado 2 de un árbol binario.
void arrgrado2(arbol a, char v[N], int dimv) {
  if (a != NULL) {
    if(a->izq != NULL && a->der == NULL) {
       (*dimv)++;
       v[dimv] = a->dato;
    } else
       arrgrado2(a->izq, v[], dimv);
       arrgrado2(a->der, v[], dimv);

  }
*/


#include <stdio.h>
#include <stdlib.h>
#define DIM 30

typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
void arrgrado2(arbol a, TElememtoA v[], int *dimV);

int main(){
 arbol a;
 int x;
 TElememtoA v[DIM];
 int dimV = 0, i;
 /* carga arbol ejemplo. Ej 1 */
 addnodo(&a, 5);
 addnodo(&a->izq, 8);
 addnodo(&a->izq->izq, 3);
 addnodo(&a->izq->der, 6);

 addnodo(&a->der, 4);
 addnodo(&a->der->izq, 1);
 addnodo(&a->der->izq->der, 2);

 arrgrado2(a, v, &dimV);
 for(i = 0 ; i < dimV; i++)
    printf("%d\t", v[i]);

 return 0;

}


void arrgrado2(arbol a, TElememtoA v[], int *dimV){
    if(a!= NULL){
        if(a->izq != NULL && a->der != NULL){
            v[*dimV] = a->dato;
            (*dimV)++;
        }
        arrgrado2(a->izq, v, dimV);
        arrgrado2(a->der, v, dimV);
    }

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
