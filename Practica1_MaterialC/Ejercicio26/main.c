/*Declarar un tipo struct para almacenar nombre, matrícula y promedio de un alumno.
Desarrollar una función que realice lectura de una variable del tipo creado. */

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

typedef struct {
    char nombre[DIM];
    int matricula;
    float promedio;
} TAlumno;

void cargarAlumno(TAlumno *alumno);

int main()
{
    TAlumno alumno;
    cargarAlumno(&alumno);
    printf("Datos del alumno: ");
    printf("Nombre: %s\n", alumno.nombre);
    printf("Matricula: %d\n", alumno.matricula);
    printf("Promedio: %5.2f\n", alumno.promedio);
    return 0;
}

void cargarAlumno(TAlumno *alumno){
    printf("Ingrese nombre: ");
    scanf("%s", (*alumno).nombre);
    printf("Ingrese matricula: ");
    scanf("%d", &(*alumno).matricula);
    printf("Ingrese promedio: ");
    scanf("%f", &(*alumno).promedio);
}
