#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Pilas.h"
#define CANT_LETRAS 26

void iniciaCompetidores(TPila competidores[]);
void cargaCompetidores(TPila competidores[]);
void mostrarCompetidores(TPila competidores[], char letra);

int main()
{
    TPila competidores[CANT_LETRAS];  //Vector de pilas.
    char letra;

    iniciaCompetidores(competidores); //Inicializo las pilas
    cargaCompetidores(competidores);  //Carga competidores en las pilas
    printf("Ingrese una letra: ");
    scanf(" %c", &letra);
    letra = tolower(letra);

    mostrarCompetidores(competidores, letra);  //Muestra una pila
    return 0;
}

void iniciaCompetidores(TPila competidores[]){
    int i;
    for(i = 0; i < CANT_LETRAS; i++)
        iniciaP(&competidores[i]);
}

void cargaCompetidores(TPila competidores[]){
    FILE *arch;
    char apellido[MAX];
    arch = fopen("competidores.txt", "rt");
    if(arch != NULL){
        while(fgets(apellido, sizeof(apellido), arch) != NULL){   //Buscar funcion fgets
            apellido[strcspn(apellido, "\n")] = '\0';
            apellido[0] = tolower(apellido[0]);
            poneP(&competidores[apellido[0] - 'a'], apellido);
        }
        fclose(arch);
    }
    else
        printf("No se registraron competidores...\n");
}

void mostrarCompetidores(TPila competidores[], char letra){
    TPila aux;
    char apellido[MAX];
    iniciaP(&aux);
    while(!vaciaP(competidores[letra - 'a'])){
        sacaP(&competidores[letra - 'a'], apellido);
        printf("%s\n", apellido);
        poneP(&aux, apellido);
    }
    while(!vaciaP(aux)){
        sacaP(&aux, apellido);
        poneP(&competidores[letra - 'a'], apellido);
    }
}
