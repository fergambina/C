/*Escribir un programa que lea desde un archivo un texto que contiene una cantidad desconocida
de palabras (una en cada línea) y genere una lista ordenada de todas las palabras existentes en
el texto con su frecuencia de aparición.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20

typedef struct nodo{
    char pal[DIM];
    unsigned int frec;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

void insertaOrdenado(TLista *L, char pal[]);

int main()
{
    TLista L = NULL;
    return 0;
}

void cargaLista(TLista *L){
    char pal[DIM];
    FILE *arch;
    arch = fopen("palabras.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%s", pal) == 1){
            printf("%s", pal);
            insertaOrdenado(L, pal);
        }
    }
    else
        printf("Error al abrir el archivo.");
}

void insertaOrdenado(TLista *L, char pal[]){
    TLista aux, act, ant;
    if(*L == NULL || strcmp(pal, (*L)->pal) < 0){
        aux = (TLista)malloc(sizeof(nodo));
        strcpy(aux->pal, pal);
        aux->frec = 1;
        aux->sig = *L;
        *L = aux;
    }
    else{
        act = *L;
        ant = NULL;
        while(act != NULL && strcmp(pal, act->pal) > 0){
            ant = act;
            act = act->sig;
        }
        if(act != NULL && strcmp(pal, act->pal) == 0)
            act->frec += 1;
        else{
            aux = (TLista)malloc(sizeof(nodo));
            strcpy(aux->pal, pal);
            aux->frec = 1;
            aux->sig = act;
            ant->sig = aux;

        }
    }

}
