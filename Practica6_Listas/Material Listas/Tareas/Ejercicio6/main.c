/*Dada una lista de cadenas eliminar los nodos que contengan cadenas que comiencen con vocal,
informar cuantos se han eliminado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

typedef struct nodo{
    char cad[MAX];
    struct nodo *sig;}nodo;
typedef nodo *TLista;

void cargaLista(TLista *L){
    TLista nuevo;
    FILE *arch;
    char cad[MAX];
    *L = NULL;
    arch = fopen("palabras.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%s", cad) == 1){
            nuevo = (TLista)malloc(sizeof(nodo)); //Reserva memoria dinamica en el heap y guarda su direccion en nuevo.
            strcpy(nuevo->cad, cad);
            nuevo->sig = *L;
            *L = nuevo;
        }
        fclose(arch);
    }
}

void mostrarLista(TLista L){
    while(L != NULL){
        printf("%s\n", L->cad);
        L = L->sig;
    }

}

int esVocal(char car){
    car = toupper(car);
    return car == 'A'|| car == 'E' || car == 'I' || car == 'O' || car == 'U';
}

void eliminaPalabras(TLista *L){
    TLista ant, act, elim;
    act = *L;
    while(act != NULL){
        if(esVocal(act->cad[0])){
            elim = act;
            act = act->sig;
            if(*L == elim)
                *L = (*L)->sig;
            else
                ant->sig = act;
            free(elim);
        }
        else{
            ant = act;
            act = act->sig;
        }
    }
}

int main()
{
    TLista L;
    cargaLista(&L);
    mostrarLista(L);
    eliminaPalabras(&L);
    printf("\n");
    mostrarLista(L);
    return 0;
}
