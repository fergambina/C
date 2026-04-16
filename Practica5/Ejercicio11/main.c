#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

void carga_empleados(TCola *c);
void procesa_empleados(TCola *c);

int main()
{
    TCola c;
    carga_empleados(&c);
    procesa_empleados(&c);
    return 0;
}

void carga_empleados(TCola *c){
    TElementoC empleado;
    long unsigned int legajo;
    unsigned int momento_arribo, duracion_uso;
    FILE *arch;
    arch = fopen("empleados.txt", "rt");
    if(arch != NULL){
        iniciaC(c);
        while(fscanf(arch, "%lu %u %u\n", &legajo, &momento_arribo, &duracion_uso) == 3){
            empleado = crearEmpleado(legajo, momento_arribo, duracion_uso);
            poneC(c, empleado);
        }
        fclose(arch);
    }
}

void procesa_empleados(TCola *c){
    TElementoC empleado;
    unsigned int momento_arribo, duracion_uso;
    long unsigned int legajo, legajo_mayor_tiempo = 0;
    unsigned int tiempo_horno_libre = 0, cant_empleados = 0, mayor_tiempo_espera = 0, total_espera = 0;
    unsigned int inicio_uso, fin_uso, tiempo_espera;
    float prom_espera;

    while(!vaciaC(*c)){
        sacaC(c, &empleado);
        cant_empleados++;
        legajo = obtenerLegajo(empleado);
        momento_arribo = obtenerMomentoArribo(empleado);
        duracion_uso = obtenerDuracionUso(empleado);

        if(momento_arribo > tiempo_horno_libre)
            inicio_uso = momento_arribo;
        else
            inicio_uso = tiempo_horno_libre;

        if(inicio_uso >= momento_arribo)
            tiempo_espera = inicio_uso - momento_arribo;
        else
            tiempo_espera = 0;

        total_espera += tiempo_espera;

        if(tiempo_espera > mayor_tiempo_espera){
            mayor_tiempo_espera = tiempo_espera;
            legajo_mayor_tiempo = legajo;
        }

        fin_uso = inicio_uso + duracion_uso;

        printf("Legajo: %lu || Arribo: %u || Inicio de uso: %u seg || Fin de uso: %u seg\n", legajo, momento_arribo, inicio_uso, fin_uso);

        tiempo_horno_libre = fin_uso;
    }

    if(cant_empleados > 0){
        prom_espera = (float)total_espera / cant_empleados;
        printf("\n--- Resultados Finales ---\n");
        printf("Tiempo promedio de espera: %.2f segundos.\n", prom_espera);
        printf("Legajo con mayor tiempo de espera: %lu (espero %u segundos).\n", legajo_mayor_tiempo, mayor_tiempo_espera);
    }
    else {
        printf("No se registraron empleados.\n");
    }
}
