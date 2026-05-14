/*Se tiene una lista con equipos de fútbol (nombre y puntaje en el torneo), la cual está ordenada
descendentemente por puntaje (los equipos con el mismo puntaje están ordenados
alfabéticamente). Cada equipo cuenta con una sublista de jugadores (nombre y edad, estado
([A]ctivo, [S]uspendido)).
a) Listar para todos los clubes los jugadores cuyo nombre comienza con la letra K (dato). Al
finalizar mostrar cantidad de jugadores listados y el club que tiene más jugadores que
cumplan el criterio solicitado.
b) Listar los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
mostrando edad promedio de cada equipo.
c) Verificar si el equipo E (dato) tiene P (dato) puntos.
d) Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct nodoJugadores{
    char nombre[MAX];
    unsigned int edad;
    char estado;
    struct nodoJugadores *sig;
}nodoJugadores;
typedef nodoJugadores *SublistaJugadores;

typedef struct nodoEquipos{
    char equipo[MAX];
    unsigned int puntaje;
    struct nodoEquipos *sig;
    SublistaJugadores sub;
}nodo;
typedef nodo *TListaE;

typedef struct nodoD{
    char equipo[MAX];
    int cantJugadores;
    float edadProm;
    struct nodoD *ant, *sig;}nodoD;
typedef struct nodoD *PnodoD;

typedef struct{
    PnodoD pri, ult;}TListaD;


void generaListaDoble(TListaE, TListaD *LD);

int main()
{
    return 0;
}

void generaListaDoble(TListaE LE, TListaD *LD){
    TListaE aux;
    SublistaJugadores actS;
    PnodoD nuevo;
    int cantJugadores, sumaEdades, mayorA30;
    (*LD).pri = NULL;
    (*LD).ult = NULL;
    aux = LE;
    while(aux != NULL){
        actS = aux->sub;
        cantJugadores = 0;
        sumaEdades = 0;
        mayorA30 = 0; //Bandera
        while(actS != NULL){
            sumaEdades += actS->edad;
            cantJugadores++;
            if(actS->edad > 30)
                mayorA30 = 1;
            actS = actS->sig;
        }
        if(mayorA30){
            nuevo = (PnodoD)malloc(sizeof(nodoD));
            strcpy(nuevo->equipo, aux->equipo);
            nuevo->cantJugadores = cantJugadores;
            nuevo->edadProm = (float)sumaEdades / cantJugadores;
            if((*LD).pri == NULL){
                nuevo->sig = NULL;
                nuevo->ant = NULL;
                (*LD).pri = nuevo;
                (*LD).ult = nuevo;
            }
            else{
                nuevo->ant = (*LD).ult;
                nuevo->sig = NULL;
                (*LD).ult->sig = nuevo;
                (*LD).ult = nuevo;
            }
        }
        aux = aux->sig;
    }
}
