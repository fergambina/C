/*1) Dada una lista simplemente enlazada de cadenas, retornar la cantidad que tienen longitud par */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct nodo{
    char cad[MAX];
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

void cargarLista(TLista *L){
    TLista nuevo;
    char cad[MAX];
    FILE *arch;
    *L = NULL;
    arch = fopen("cadenas.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%s", cad) == 1){
            nuevo = (TLista)malloc(sizeof(nodo));
            strcpy(nuevo->cad, cad);
            nuevo->sig = *L;
            *L = nuevo;
        }
        fclose(arch);
    }
}

int cantLongPar(TLista L){
    int cont = 0;
    while(L != NULL){
        if(strlen(L->cad) % 2 == 0)
            cont++;
        L = L->sig;
    }
    return cont;
}



int main()
{
    TLista L = NULL;  //TLista es un puntero a nodo.
    cargarLista(&L);  //Recibe la direccion de un puntero a nodo.
    printf("Cantidad de cadenas de longitud par: %d", cantLongPar(L));
    return 0;
}
