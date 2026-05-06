/*Dada una lista doblemente enlazada que contiene los inscriptos a un curso, en la que en cada
nodo se tiene:
• Apellido (ordenada por este campo)
• Nombre (los inscriptos con el mismo apellido, se ordenan por este campo)
• Categoría (docente, alumno, externo)
a) listarlos en orden alfabético, indicando el importe total recaudado. El valor del curso es un
dato leído por teclado, los docentes tienen un 30% de descuento, y los alumnos un 10%.
b) listar los inscriptos externos en orden alfabético descendente.
c) verificar si existe una persona con apellido X (dato) y nombre Y (dato) dentro de la lista de
inscriptos */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct nodoD{
    char apellido[MAX];
    char nombre[MAX];
    char categoria;
    struct nodoD *ant, *sig;}nodoD;
typedef struct nodoD *PnodoD;

typedef struct{
    PnodoD pri, ult;}TListaD;

void listaInscriptos(TListaD LDI, float valor);
void listaExternos(TListaD LDI);
void estaInscripto(TListaD LDI, char nombre[], char apellido[], int *esta);

int main()
{
    TListaD LDI;
    float valor;
    printf("Ingrese valor del curso: ");
    scanf("%f", &valor);
    listaInscriptos(LDI, valor);
    return 0;
}

void listaInscriptos(TListaD LDI, float valor){
    PnodoD actI;
    float importeTotal = 0;
    actI = (LDI).pri;
    printf("INSCRIPTOS AL CURSO: \n");
    while(actI != NULL){
        printf("Apellido: %s\n", actI->apellido);
        printf("Nombre: %s\n", actI->nombre);
        printf("Categoria: %c\n", actI->categoria);
        printf("\n");
        if(actI->categoria == 'D')
            importeTotal = importeTotal + valor*0.70;
        else
            if(actI->categoria == 'A')
                importeTotal = importeTotal + valor*0.90;
            else
                importeTotal = importeTotal + valor;
        actI = actI->sig;
    }
    printf("Importe total recaudado: %5.2f", importeTotal);
}

void listaExternos(TListaD LDI){
    PnodoD actI;
    actI = LDI.ult;
    printf("Lista de inscriptos externos (en orden descendente alfabeticamente): ");
    while(actI != NULL){
        if(actI->categoria == 'E'){
            printf("Apellido: %s\n", actI->apellido);
            printf("Nombre: %s\n", actI->nombre);
            printf("Categoria: %c\n", actI->categoria);
        }
        actI = actI->ant;
    }
}

void estaInscripto(TListaD LDI, char nombre[], char apellido[], int *esta){
    PnodoD actI;
    actI = LDI.pri;
    *esta = 0;
    // Avanzar mientras el nodo sea MENOR que el apellido buscado
    while(actI != NULL && strcmp(actI->apellido, apellido) < 0){
        actI = actI->sig;
    }
    if(actI != NULL && strcmp(actI->apellido, apellido) == 0){
        if(strcmp(actI->nombre, nombre) == 0)
            *esta = 1;
        else{
            while(actI != NULL && strcmp(actI->apellido, apellido) == 0 && strcmp(actI->nombre, nombre) < 0)
                actI = actI->sig;
            if(actI != NULL && strcmp(actI->apellido, apellido) == 0 && strcmp(actI->nombre, nombre) == 0)
                *esta = 1;
        }
    }
}
