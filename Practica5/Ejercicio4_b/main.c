/*Ingresar en una cola los números almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la cola. Utilizar la implementación estática no circular. */

#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

void cargarCola(TCola *C);
void mostrarCola(TCola *C);

int main()
{
    TCola C;
    cargarCola(&C);
    printf("Mostrando elementos de la cola...\n");
    mostrarCola(&C);
    return 0;
}

void cargarCola(TCola *C){
    TElementoC num;
    FILE *archT;
    archT = fopen("numeros.txt", "rt");
    iniciaC(C);
    if(archT != NULL){
        while(fscanf(archT, "%f/n", &num) == 1)
            poneC(C, num);
        fclose(archT);
    }
    else
        printf("Archivo no existente...");
}

void mostrarCola(TCola *C){
    TElementoC num;
    while(!vaciaC(*C)){
        sacaC(C, &num);
        printf("%5.2f\n", num);
    }
}
