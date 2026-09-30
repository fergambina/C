#include <stdio.h>
#include <stdlib.h>
#include "PilaDinamica.h"
#include "ColaDinamica.h"

void cargaJugadores(TCola *C, int *N){
    TElementoC jugador;
    //Cargo nombres de jugadores desde un archivo de texto.
    FILE *arch;
    *N = 0;
    iniciaC(C);
    arch = fopen("jugadores.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%s", jugador.nombre) == 1){
            jugador.puntaje = 0;
            poneC(C, jugador);
            (*N)++;
        }
        fclose(arch);
    }
}

void cargaMazo(TPila *P){
    TElementoP carta;
    FILE *arch;
    iniciaP(P);
    arch = fopen("mazo.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, " %c %u", &carta.palo, &carta.num) == 2)
            poneP(P, carta);
        fclose(arch);
    }
}

void simulaJuego(TCola *C, TPila *P){
    TElementoC jugador;
    TElementoP cartaAct, cartaAnt;
    cartaAnt.palo = '\0';
    while(!vaciaP(*P)){
        sacaP(P, &cartaAct);
        sacaC(C, &jugador);
        if(cartaAct.palo == cartaAnt.palo)
            jugador.puntaje += 2*cartaAct.num;
        else
            jugador.puntaje += cartaAct.num;
        poneC(C, jugador);
        cartaAnt = cartaAct;
    }
}

void mostrarPuntajes(TCola *C, int N){
    TElementoC jugador;
    int i;
    for(i = 0; i < N; i++){
        sacaC(C, &jugador);
        printf("Jugador: %s\n", jugador.nombre);
        printf("Puntaje: %u\n", jugador.puntaje);
        poneC(C, jugador);
        printf("\n");
    }
}

int main()
{
    TCola C;
    TPila P;
    int N;
    cargaJugadores(&C, &N);
    cargaMazo(&P);
    simulaJuego(&C, &P);
    mostrarPuntajes(&C, N);
    return 0;
}
