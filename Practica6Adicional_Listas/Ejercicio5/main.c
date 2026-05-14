/*Resolver mediante subprogramas las siguientes operaciones sobre una lista doblemente
enlazada:
a) insertar un elemento en la posición media. Si la cantidad de elementos de la lista es impar
insertar en la posición media más uno. Considerar la inserción en una lista vacía (único
nodo)
b) eliminar un elemento conociendo la posición (puntero) del anterior, nulo para eliminar el
primer elemento.
c) eliminar todas las ocurrencias del elemento X (recibido como parámetro) */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoD{
    int num;
    struct nodoD *ant, *sig;}nodoD;
typedef struct nodoD *PnodoD;

typedef struct{
    PnodoD pri, ult;}TListaD;

void cargaLista(TListaD *LD);
void insertaEnElMedio(TListaD *LD, int num);
void muestraLista(TListaD LD);

int main()
{
    TListaD LD;
    int num;
    cargaLista(&LD);
    muestraLista(LD);
    printf("\n");
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    insertaEnElMedio(&LD, num);
    muestraLista(LD);
    return 0;
}

void muestraLista(TListaD LD){
    PnodoD aux;
    aux = LD.pri;
    while(aux != NULL){
        printf("%d\t", aux->num);
        aux = aux->sig;
    }
}

void cargaLista(TListaD *LD){
    int num;
    PnodoD nuevo;
    FILE *arch;
    (*LD).pri = NULL;
    (*LD).ult = NULL;
    arch = fopen("numeros.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%d", &num) == 1){
            nuevo = (PnodoD)malloc(sizeof(nodoD));
            nuevo->num = num;
            if((*LD).pri == NULL){
                nuevo->ant = NULL;
                nuevo->sig = NULL;
                (*LD).pri = nuevo;
                (*LD).ult = nuevo;
            }
            else{
                nuevo->sig = NULL;
                nuevo->ant = (*LD).ult;
                (*LD).ult->sig = nuevo;
                (*LD).ult = nuevo;
            }
        }
    }
}

void insertaEnElMedio(TListaD *LD, int num){
    PnodoD nuevo, auxI, auxU;
    nuevo = (PnodoD)malloc(sizeof(nodoD));
    nuevo->num = num;
    if((*LD).pri == NULL){
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        (*LD).pri = nuevo;
        (*LD).ult = nuevo;
    }
    else{
        auxI = (*LD).pri;
        auxU = (*LD).ult;
        while(auxI->sig != auxU && auxI != auxU){
            auxI = auxI->sig;
            auxU = auxU->ant;
        }
        nuevo->sig = auxI->sig;
        nuevo->ant = auxI;
        if(auxI->sig != NULL)
            auxI->sig->ant = nuevo;
        else
            (*LD).ult = nuevo;
        auxI->sig = nuevo;
    }
}

void eliminaConociendoPunteroAnterior(TListaD *LD, PnodoD anterior){
    PnodoD aEliminar;
    if((*LD).pri != NULL){
        if(anterior == NULL){
            aEliminar = (*LD).pri;
            if((*LD).pri != (*LD).ult){
                (*LD).pri = aEliminar->sig;
                (*LD).pri->ant = NULL;
            }
            else{
                (*LD).pri = NULL;
                (*LD).ult = NULL;
            }
            free(aEliminar);
        }
        else{
            if(anterior->sig != NULL){
                aEliminar = anterior->sig;
                if(aEliminar == (*LD).ult){
                    (*LD).ult = anterior;
                    anterior->sig = NULL;
                }
                else{
                    anterior->sig = aEliminar->sig;
                    aEliminar->sig->ant = anterior;
                }
                free(aEliminar);
            }
        }
    }
}

void eliminaAparicionesDeX(TListaD *LD, int x){
    PnodoD act, elim;
    act = (*LD).pri;
    while(act != NULL){
        if(act->num == x){
            elim = act;
            act = act->sig;
            if((*LD).pri == (*LD).ult){
                (*LD).pri = NULL;
                (*LD).ult = NULL;
            }
            else{
                if(elim == (*LD).pri){
                    (*LD).pri = elim->sig;
                    (*LD).pri->ant = NULL;
                }
                else{
                    if(elim == (*LD).ult){
                        (*LD).ult = elim->ant;
                        (*LD).ult->sig = NULL;
                    }
                    else{
                        elim->ant->sig = elim->sig;
                        elim->sig->ant = elim->ant;
                    }
                }
            }
            free(elim);
        }
        else
            act = act->sig;
    }
}



