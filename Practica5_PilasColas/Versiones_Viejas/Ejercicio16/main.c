/*Simular un juego de naipes donde N jugadores van tomando un naipe del mazo por turno.  El
juego finaliza cuando el mazo queda vacío. El puntaje de cada jugador consiste en la sumatoria
de los números de los naipes que fue tomando. Si el palo del naipe tomado coincide con el palo
del levantado en el turno anterior el número se duplica. Implementar utilizando las estructuras
(pilas y/o colas) que considere necesarias. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PilaEstatica.h"
#include "ColaEstaticaCircular.h"

void cargaMazo(TPila *mazo);
void cargaTurnos(TCola *turnos, int N);
void procesaJuego(TPila *mazo, TCola *turnos, int jugadores[], int N);
void inicializaPuntajes(int jugadores[], int N);
void mostrarResultados(int jugadores[], int N);

int main()
{
    TPila mazo;
    TCola turnos;
    int N = 5;
    int jugadores[N];
    cargaMazo(&mazo);
    cargaTurnos(&turnos, N);
    procesaJuego(&mazo, &turnos, jugadores, N);
    mostrarResultados(jugadores, N);
    return 0;
}

void mostrarResultados(int jugadores[], int N){
    int i;
    for(i = 0; i < N; i++){
        printf("Jugador %d: %d\n", i + 1, jugadores[i]);
    }
}

void inicializaPuntajes(int jugadores[], int N){
    int i;
    for(i = 0; i < N; i++){
        jugadores[i] = 0;
    }
}

void procesaJuego(TPila *mazo, TCola *turnos, int jugadores[], int N){
    TElementoP carta;
    TElementoC numJugador;
    int puntaje;
    char paloAnterior = '\0';

    inicializaPuntajes(jugadores, N);

    while(!vaciaP(*mazo)){
        sacaP(mazo, &carta);
        sacaC(turnos, &numJugador);
        puntaje = carta.numero;
        if(paloAnterior != '\0' && paloAnterior == carta.palo)
            puntaje *= 2;
        jugadores[numJugador] += puntaje;
        paloAnterior = carta.palo;
        poneC(turnos, numJugador);
    }
}

void cargaTurnos(TCola *turnos, int N){
    int i;
    iniciaC(turnos);
    for(i = 0; i < N; i++){
        poneC(turnos, i);
    }
}

void cargaMazo(TPila *mazo){
    TElementoP carta;
    FILE *arch;
    arch = fopen("mazo.txt", "rt");
    iniciaP(mazo);
    if(arch != NULL){
        while(fscanf(arch, " %c %d", &carta.palo, &carta.numero) == 2){
            poneP(mazo, carta);
        }
        fclose(arch);
    }
    else{
        printf("No hay cartas disponibles...");
    }
}
