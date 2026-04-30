#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodoD{
    char car;
    struct nodoD *ant, *sig;
}nodoD;
typedef nodoD *PnodoD;

typedef struct{
    PnodoD pri, ult;
}TListaD;

void cargaLista(TListaD *LD);
void escribirLista(TListaD LD);
int esVocal(char c);
void cantVocales(TListaD LD, int *cantVocales);
void estaOrdenada(TListaD LD, int *res);

int main()
{
    TListaD LD;
    int cantVoc, res;
    cargaLista(&LD);
    escribirLista(LD);
    printf("\n");
    cantVocales(LD, &cantVoc);
    printf("La cantidad de vocales es: %d", cantVoc);
    printf("\n");
    estaOrdenada(LD, &res);
    if(res)
        printf("La lista esta ordenada.");
    else
        printf("La lista no esta ordenada");
    return 0;
}

void cargaLista(TListaD *LD){
    FILE *arch;
    PnodoD nuevo;
    char car;
    (*LD).pri = NULL;
    (*LD).ult = NULL;
    arch = fopen("caracteres.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, " %c", &car) == 1){
            nuevo = (PnodoD)malloc(sizeof(nodoD));
            nuevo->car = car;
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
        printf("%c\t", aux->car);
        aux = aux->sig;
    }
}

int esVocal(char c){
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void cantVocales(TListaD LD, int *cantVoc){
    PnodoD aux;
    aux = LD.pri;
    *cantVoc = 0;
    while(aux != NULL){
        if(esVocal(aux->car))
            (*cantVoc)++;
        aux = aux->sig;
    }

}

void estaOrdenada(TListaD LD, int *res){
    PnodoD aux;
    aux = LD.pri;
    *res = 1;
    while(aux != NULL && *res){
        if(aux->car > aux->sig->car)
            *res = 0;
        aux = aux->sig;
    }
}
