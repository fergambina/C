/* Copiar el contenido completo de una lista simplemente enlazada en una lista doblemente
enlazada y en una lista circular, ambas inicialmente vacías. Ambas copias deben realizarse en la
misma función. En ambos casos se debe mantener el orden de la lista original, siendo el último
elemento de la lista simple el último de la circular. La lista original no debe ser modificada.  */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *sig;
}nodo;
typedef struct nodo *TLista;

typedef struct nodoD{
    int num;
    struct nodoD *ant, *sig;
}nodoD;
typedef struct nodoD *PnodoD;

typedef struct{
    PnodoD pri, ult;
}TListaD;

void cargaLista(TLista *L);
void mostrarListaSE(TLista L);
void mostrarListaD(TListaD LD);
void mostrarListaC(TLista LC);
void generaListas(TLista L, TLista *LC, TListaD *LD);

int main()
{
    TLista L;
    TListaD LD;
    TLista LC;
    cargaLista(&L);
    //printf("Lista Simplemente Enlazada: ");
    mostrarListaSE(L);
    printf("\n");
    generaListas(L ,&LC, &LD);
    //printf("Lista Doblemente Enlazada: ");
    mostrarListaD(LD);
    printf("\n");
    //printf("Lista Circular: ");
    mostrarListaC(LC);
    return 0;
}

void cargaLista(TLista *L){
    FILE *arch;
    int num;
    TLista nuevo;
    *L = NULL;  //incializar en NULL en main o funcion??
    arch = fopen("numeros.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%d", &num) == 1){
            nuevo = (TLista)malloc(sizeof(nodo));
            nuevo->num = num;
            nuevo->sig = *L;   //Inserto al inicio (caso de la pila)
            *L = nuevo;
        }
        fclose(arch);
    }
    else
        printf("Archivo no existente...");
}

void mostrarListaSE(TLista L){
    TLista aux;
    aux = L;
    while(aux != NULL){
        printf("%d\t", aux->num);
        aux = aux->sig;
    }
}

void mostrarListaD(TListaD LD){
    PnodoD aux;
    aux = LD.pri;
    while(aux != NULL){
        printf("%d\t", aux->num);
        aux = aux->sig;
    }
}

void mostrarListaC(TLista LC){
    TLista aux;
    if(LC != NULL){
        aux = LC;
        do{
            aux = aux->sig;
            printf("%d\t", aux->num);
        }while(aux != LC);
    }
}


void generaListas(TLista L, TLista *LC, TListaD *LD){
    TLista aux;
    PnodoD nuevoD;
    TLista nuevoC;
    (*LD).pri = NULL;
    (*LD).ult = NULL;
    *LC = NULL;
    if(L != NULL){
        aux = L;
        while(aux != NULL){
            nuevoD = (PnodoD)malloc(sizeof(nodoD));
            nuevoD->num = aux->num;
            nuevoC = (TLista)malloc(sizeof(nodo));
            nuevoC->num = aux->num;
            if((*LD).pri == NULL){
                nuevoD->ant = NULL;
                nuevoD->sig = NULL;
                (*LD).pri = nuevoD;
                (*LD).ult = nuevoD;
                nuevoC->sig = nuevoC;
                *LC = nuevoC;
            }
            else{
                nuevoD->sig = NULL;
                nuevoD->ant = (*LD).ult;
                (*LD).ult->sig = nuevoD;
                (*LD).ult = nuevoD;
                nuevoC->sig = (*LC)->sig;
                (*LC)->sig = nuevoC;
                (*LC) = nuevoC;
            }
            aux = aux->sig;
        }
    }
}
