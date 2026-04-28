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

void listarJugadores(TListaE LE, char K);
void listarClubes(TListaE LE, int x);
int verificaEquipo(TListaE LE, char equipo[], int P);
void eliminaJugadoresSuspendidos(TListaE LE);

int main()
{
    TListaE LE;
    char K, equipo[MAX];
    int x, P;
    //cargaEquipos(&LE);
    printf("Ingrese una letra: ");
    scanf("%c", &K);
    listarJugadores(LE, K);
    printf("Ingrese puntaje: ");
    scanf("%d", &x);
    listarClubes(LE, x);
    printf("Ingrese equipo: ");
    scanf("%s", equipo);
    printf("Ingrese puntaje: ");
    scanf("%d", P);
    verificaEquipo(LE, equipo, P);
    eliminaJugadoresSuspendidos(LE);
    return 0;
}

void listarJugadores(TListaE LE, char K){
    TListaE aux;
    SublistaJugadores actS;
    char equipoMaxJugadores[MAX] = "";
    int cantJugadoresListados = 0, maxJugadoresListados = -1, cantJugadoresListadosPorEquipo;
    aux = LE;
    while(aux != NULL){ //Recorro toda la lista de clubes.
        printf("Club: %s", aux->equipo);
        cantJugadoresListadosPorEquipo = 0;
        actS = aux->sub;
        while(actS != NULL){  //Recorro toda la sublista de jugadores.
            if(actS->nombre[0] == K){
                printf("%s", actS->nombre);
                cantJugadoresListados++;
                cantJugadoresListadosPorEquipo++;
            }
            actS = actS->sig;
        }
        if(cantJugadoresListadosPorEquipo > maxJugadoresListados){
            maxJugadoresListados = cantJugadoresListadosPorEquipo;
            strcpy(equipoMaxJugadores, aux->equipo);
        }
        aux = aux->sig;
    }
    if(cantJugadoresListados > 0){
        printf("Cantidad de jugadores listados: %u", cantJugadoresListados);
        printf("Club que tiene mas jugadores que empiezan con la letra %c: %s", K, equipoMaxJugadores);
    }
    else
        printf("Ningun jugador cumple con el criterio.");
}

void listarClubes(TListaE LE, int x){
    TListaE aux;
    SublistaJugadores actS;
    int cantJugadores, sumaEdades;
    aux = LE;
    while(aux != NULL && aux->puntaje >= x){
        cantJugadores = 0;
        sumaEdades = 0;
        actS = aux->sub;
        printf("Club: %s.", aux->equipo);
        while(actS != NULL){
            printf("%s.", actS->nombre);
            cantJugadores++;
            sumaEdades += actS->edad;
            actS = actS->sig;
        }
        if(cantJugadores > 0)
            printf("La edad promedio de los jugadores de este club es: %5.2f.", (float)sumaEdades/cantJugadores);
        else
            printf("No se registraron jugadores en este equipo.");
        aux = aux->sig;
    }
}

int verificaEquipo(TListaE LE, char equipo[], int P){
    TListaE aux;
    aux = LE;
    while(aux != NULL && aux->puntaje >= P && strcmp(aux->equipo, equipo) != 0)
        aux = aux->sig;
    return aux != NULL && strcmp(aux->equipo, equipo) == 0 && aux->puntaje = P;
}

void eliminaJugadoresSuspendidos(TListaE LE){
    TListaE aux;
    SublistaJugadores antS, actS, elim;
    aux = LE;
    while(aux != NULL){
        antS = NULL;
        actS = aux->sub;
        while(actS != NULL){
            if(actS->estado == 'S'){
                elim = actS;
                if(antS == NULL){
                    aux->sub = actS->sig;
                    actS = actS->sig;
                }
                else{
                    antS->sig = actS->sig;
                    actS = actS->sig;
                }
                free(elim);
            }
            else{
                antS = actS;
                actS = actS->sig;
            }
        }
        aux = aux->sig;
    }
}
