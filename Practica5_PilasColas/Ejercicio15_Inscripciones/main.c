#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "PilaDinamica.h"
#include "ColaEstatica.h"
#define CANT_LETRAS 26

void iniciaPilas(TPila inscripciones[]);
void cargaCompetidores(TCola *C);
void generaInscripciones(TCola *C, TPila inscripciones[]);
void mostrarInscripciones(TPila inscripciones[], char letra);

int main()
{
    TCola C;
    TPila inscripciones[CANT_LETRAS];
    char letra;
    iniciaPilas(inscripciones);
    cargaCompetidores(&C);
    generaInscripciones(&C, inscripciones);
    printf("Ingrese una letra: ");
    scanf(" %c", &letra);
    letra = tolower(letra);
    mostrarInscripciones(inscripciones, letra);
    return 0;
}

void iniciaPilas(TPila inscripciones[]){
    int i;
    for(i = 0; i < CANT_LETRAS; i++)
        iniciaP(&inscripciones[i]);
}

void cargaCompetidores(TCola *C){
    FILE *arch;
    TElementoC competidor;
    arch = fopen("competidores.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%s %s", competidor.apellido, competidor.nombre) == 2)
            poneC(C, competidor);
        fclose(arch);
    }
}

void generaInscripciones(TCola *C, TPila inscripciones[]){
    TElementoC competidor;
    TElementoP inscripcionCompetidor;
    int n = 1;
    while (!vaciaC(*C)) {
        sacaC(C, &competidor);
        inscripcionCompetidor.id = n;
        strcpy(inscripcionCompetidor.apellido, competidor.apellido);
        strcpy(inscripcionCompetidor.nombre, competidor.nombre);
        poneP(&inscripciones[competidor.apellido[0] - 'A'], inscripcionCompetidor);
        n++;
    }
}

void mostrarInscripciones(TPila inscripciones[], char letra){
    TElementoP inscripcionCompetidor;
    TPila pAux;
    iniciaP(&pAux);
    while(!vaciaP(inscripciones[letra - 'A'])){
        sacaP(&inscripciones[letra - 'A'], &inscripcionCompetidor);
        printf("Apellido: %s\n", inscripcionCompetidor.apellido);
        printf("Nombre: %s\n", inscripcionCompetidor.nombre);
        printf("ID: &lu", inscripcionCompetidor.id);
        poneP(&pAux, inscripcionCompetidor); // pone pAux para no perder la pila.
    }
    while(!vaciaP(pAux)){
        sacaP(&pAux, &inscripcionCompetidor);
        poneP(&inscripciones[letra - 'A'], inscripcionCompetidor);
    }
}
