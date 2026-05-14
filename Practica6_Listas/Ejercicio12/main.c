/*Una lista doble contiene en cada nodo un rango de números enteros [A,B] y una sublista de
enteros. Generar una lista simple paralela a la lista doble donde cada nodo contenga el
promedio de los valores de la sublista y la cantidad de elementos de la misma que no
pertenecen al rango [A,B].*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoSub{
    int num;
    struct nodoSub *sig;}nodoSub;
typedef nodoSub *Sublista;

typedef struct nodoD{
    int priR, ultR;
    struct nodoD *ant, *sig;
    Sublista sub;}nodoD;
typedef nodoD *PnodoD;

typedef struct{
    PnodoD pri, ult;}TListaD;

typedef struct nodo{
    float prom;
    int cantElemNoRango;
    struct nodo *sig;}nodo;
typedef nodo *TLista;


int main()
{
    printf("Hello world!\n");
    return 0;
}


void generaLista(TListaD LD, TLista *L){
    PnodoD aux;
    Sublista actS;
    TLista nuevo, ultimo;
    int sumSublista, cantElemNoRango, cantElem;
    *L = NULL;
    ultimo = NULL;
    aux = LD.pri;
    while(aux != NULL){
        nuevo = (TLista)malloc(sizeof(nodo));
        sumSublista = 0;
        cantElem = 0;
        cantElemNoRango = 0;
        actS = aux->sub;
        while(actS != NULL){
            cantElem++;
            sumSublista += actS->num;
            if(actS->num < aux->priR || actS->num > aux->ultR)
                cantElemNoRango++;
            actS = actS->sig;
        }
        if(cantElem > 0)
            nuevo->prom = (float)sumSublista / cantElem;
        else
            nuevo->prom = 0;
        nuevo->cantElemNoRango = cantElemNoRango;
        nuevo->sig = NULL;   //Inserto al final
        if(*L == NULL)
            *L = nuevo;
        else
            ultimo->sig = nuevo;
        ultimo = nuevo;
        aux = aux->sig;
    }
}
