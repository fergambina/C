/* Dada una lista doblemente enlazada de caracteres que representa una palabra, verificar si es
palíndroma.  */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoD{
    char c;
    struct nodoD *ant, *sig;}nodoD;
typedef struct nodoD *PnodoD;

typedef struct{
    PnodoD pri, ult;
}TListaD;

void cargarPalabra(TListaD *LD);
void escribirLista(TListaD LD);
void esPalindroma(TListaD LD, int *esPalin);

int main()
{
    TListaD LD;
    int esPalin;
    cargarPalabra(&LD);
    escribirLista(LD);
    printf("\n");
    esPalindroma(LD, &esPalin);
    if(esPalin)
        printf("La palabra es palindroma");
    else
        printf("La palabra no es palindroma");
    return 0;
}

void cargarPalabra(TListaD *LD){
    FILE *arch;
    PnodoD nuevo;
    char c;
    (*LD).pri = NULL;
    (*LD).ult = NULL;
    arch = fopen("palabra.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, " %c", &c) == 1){
            nuevo = (PnodoD)malloc(sizeof(nodoD));
            nuevo->c = c;
            if((*LD).pri == NULL){
                nuevo->ant = NULL;
                nuevo->sig = NULL;
                (*LD).ult = nuevo;
                (*LD).pri = nuevo;
            }
            else{
                nuevo->sig = NULL;
                nuevo->ant = (*LD).ult;
                nuevo->ant->sig = nuevo;
                (*LD).ult = nuevo;
            }
        }
        fclose(arch);
    }
}

void escribirLista(TListaD LD){
    PnodoD aux;
    aux = LD.pri;
    while(aux != NULL){
        printf("%c\t", aux->c);
        aux = aux->sig;
    }
}


void esPalindroma(TListaD LD, int *esPalin){
    PnodoD auxP, auxU;
    *esPalin = 1;
    if(LD.pri != NULL){
        auxP = LD.pri;
        auxU = LD.ult;
        while(auxP != auxU && *esPalin){
            if(auxP->c != auxU->c)
                *esPalin = 0;
            else{
                auxP = auxP->sig;
                auxU = auxU->ant;
            }
        }
    }
}
