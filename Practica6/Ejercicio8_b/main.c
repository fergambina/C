/*Dada una lista circular de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo{
    char dato;
    struct nodo *sig;
}nodo;
typedef nodo *TListaC;

void cargarLista(TListaC *LC);
void mostrarContenido(TListaC LC);
int esVocal(char c);
void cantVocales(TListaC LC, int *cant);
void estaOrdenada(TListaC LC, int *ord);
void eliminarNodo(TListaC *LC, int p);

int main()
{
    TListaC LC;
    LC = NULL;
    int cant, ord, p;
    cargarLista(&LC);
    mostrarContenido(LC);
    printf("\n");
    cantVocales(LC, &cant);
    printf("Cantidad de vocales en la lista circular: %d", cant);
    printf("\n");
    estaOrdenada(LC, &ord);
    if(ord)
        printf("La lista circular esta ordenada\n");
    else
        printf("La lista no esta ordenada\n");
    printf("Ingrese posicion del nodo a eliminar: ");
    scanf("%d", &p);
    eliminarNodo(&LC, p);
    mostrarContenido(LC);
    return 0;
}

void cargarLista(TListaC *LC){
    TListaC nuevo;
    FILE *arch;
    char dato;
    arch = fopen("caracteres.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, " %c", &dato) == 1){
            nuevo = (TListaC)malloc(sizeof(nodo));
            nuevo->dato = dato;
            if(*LC == NULL){
                *LC = nuevo;
                nuevo->sig = nuevo;
            }
            else{
                nuevo->sig = (*LC)->sig;
                (*LC)->sig = nuevo;
                *LC = nuevo;
            }
        }
        fclose(arch);
    }
}

void mostrarContenido(TListaC LC){
    TListaC aux;
    if(LC != NULL){
        aux = LC;
        do{
            aux = aux->sig;
            printf("%c\t", aux->dato);
        }while(aux != LC);
    }
}

int esVocal(char c){
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}


void cantVocales(TListaC LC, int *cant){
    TListaC aux;
    *cant = 0;
    if(LC != NULL){
        aux = LC;
        do{
            aux = aux->sig;
            if(esVocal(aux->dato))
                (*cant)++;
        }while(aux != LC);
    }
}

void estaOrdenada(TListaC LC, int *ord){
    TListaC act, ant;
    *ord = 1;
    if(LC != NULL){
        ant = LC;
        act = ant->sig;
        while(act != LC && ord){
            ant = act;
            act = act->sig;
            if(act->dato < ant->dato)
                *ord = 0;
        }
    }
}


void eliminarNodo(TListaC *LC, int p) {
    TListaC ant, act;
    int i;
    if (*LC != NULL){
        if ((*LC) == (*LC)->sig){
            if (p == 0) {
                free(*LC);
                *LC = NULL;
            }
        }
        else{
            ant = *LC;
            act = (*LC)->sig;
            i = 0;
            while(i < p){
                ant = act;
                act = act->sig;
                i++;
            }
            if(act == *LC){
                ant->sig = act->sig;
                *LC = ant;
            }
            else
                ant->sig = act->sig;
            free(act);
        }
    }
}
