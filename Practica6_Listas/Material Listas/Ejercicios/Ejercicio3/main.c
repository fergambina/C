/*2) Dada una lista simplemente enlazada de cadenas, verificar si X está */

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

int esta(TLista L, char x[]){
    while(L != NULL && strcmp(x, L->cad) != 0)
        L = L->sig;
    return L != NULL;
}


int main()
{
    TLista L = NULL;  //TLista es un puntero a nodo.
    char cad[MAX];
    cargarLista(&L);  //Recibe la direccion de un puntero a nodo.
    printf("Ingres una cadena: ");
    scanf("%s", cad);
    if(esta(L, cad))
        printf("La cadena ingresada esta.");
    else
        printf("La cadena ingresada no esta.");
    return 0;
}
