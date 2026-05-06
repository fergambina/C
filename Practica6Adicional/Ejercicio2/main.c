/*A partir de una lista simplemente enlazada ordenada de enteros, generar dos listas
simplemente enlazadas de salida: una conteniendo los valores impares ordenados
descendentemente, y la segunda con los valores pares ordenados de manera ascendente. No
se deberá crear nuevos nodos, sino utilizar los de la lista original generando nuevos enlaces. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *sig;}nodo;
typedef struct nodo *TLista;

int main()
{
    TLista L, LI, LP;
    cargaLista(&L);
    generaListas(L, &LI, &LP);
    return 0;
}

void generaListas(TLista L, TLista *LI, TLista *LP){
    TLista act, sig, ultP, auxI;
    *LI = NULL;
    *LP = NULL;
    act = L;
    while(act != NULL){
        sig = act->sig;
        if(act->num % 2 == 0){
            if(*LP = NULL)
                *LP = act;
            else
                ultP->sig = act;
            ultP = act;
        }
        else{
            act->sig = *LI;
            *LI = act;
        }
        act = sig;
    }
    if(ultP != NULL){
        ultP->sig = NULL;
    }
    if(*LI != NULL){
        auxI = *LI;
        while(auxI->sig != NULL && auxI->sig->num % 2 != 0)
            auxI = auxI->sig;
        auxI->sig = NULL;
    }

}
