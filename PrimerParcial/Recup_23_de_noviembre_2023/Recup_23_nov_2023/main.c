#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoS{
    char cod[8];
    unsigned int dest, cantProdSolicitados, cantProdEnviados;
    struct nodoS *sig;}nodoS;
typedef nodoS *SublistaProductos;

typedef struct nodoC{
    unsigned int idPuesto, cantTotalProdSolicitados;
    char nom[31];
    SublistaProductos subProductos;
    struct nodoC *sig;}nodoC;
typedef nodoC *TListaC;


typedef struct nodo{
    unsigned int idRobot, idPuesto;
    TCola productos;
    struct nodo *sig;}nodo;
typedef nodo *TLista;

int main()
{
    printf("Hello world!\n");
    return 0;
}


void ubicaPuesto(TListaC *LC, int idPuesto, char nombre[], TListaC *ppuesto){
    TListaC nuevo, ant, act;
    nuevo = (TListaC)malloc(sizeof(nodoC));
    nuevo->idPuesto = idPuesto;
    strcpy(nuevo->nom, nombre);
    nuevo->cantTotalProdSolicitados = 0;
    nuevo->subProductos = NULL;
    if(*LC == NULL){
        nuevo->sig = nuevo;
        *LC = nuevo;
        *ppuesto - *LC;
    }
    else
        if(idPuesto > (*LC)->idPuesto){
            nuevo->sig = (*LC)->sig;
            *LC = nuevo;
            *ppuesto = nuevo;
        }
        else{
            ant = *LC;
            act = (*LC)->sig;
            while(idPuesto > act->idPuesto){
                ant = act;
                act = act->sig;
            }
            if(idPuesto == act->>idPuesto){
                *ppuesto = act;
                free(nuevo);
            }
            else{
                nuevo->sig = act;
                *ppuesto = nuevo;
                ant->sig = nuevo;
            }
        }

}


void actualizaP(TListaC ppuesto, char cod[], int destinatario , int cantProducto){
    SublistaProductos ant, act, nuevo;
    act = ppuesto->subProductos;
    while(act != NULL && (strcpy(act->cod, cod) != 0 || destinatario != act->dest)){
        ant = act;
        act = act->sig;
    }










    nuevo = (SublistaProductos)malloc(sizeof(nodoS));
    strcpy(nuevo->cod, cod);
    nuevo->cod = destinatario;
    nuevo->cantProdSolicitados = cantProducto;
    nuevo->cantProdEnviados = 0;

}


void procesaArch(TListaC *LC){
    TListaC ppuesto;
    int idPuesto, cantProductos, cantProducto, destinatario, i;
    char codProducto[8], nombre[31];
    FILE *arch;
    arch = fopen("pedidos.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%d %s %d", &idPuesto, nombre, &cantProductos) == 3){
            ubicaPuesto(LC, idPuesto, nombre, &ppuesto);
            for(i = 0; i < cantProductos; i++){
                fscanf(arch, "%d %s %d", destinatario, codProducto, cantProducto);
                actualizaSublista(ppuesto, cod, destinatario, cantProducto);
            }
        }
        fclose(arch);
    }
}
