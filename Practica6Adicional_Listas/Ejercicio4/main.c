/*Desarrollar un programa que gestione las reservas de pasajes para los vuelos de una aerolínea.
Para ello se cuenta con una lista de destinos con la siguiente estructura:
• Destino
• Sublista ordenada de Vuelos (a dicho destino)
o Código de vuelo
o Fecha y horario de salida
o Capacidad de pasajeros
o Sublista de pasajes vendidos (para dicho vuelo)
 Documento del pasajero
Tanto para la reserva como para su cancelación se solicita: destino, código de vuelo y
documento del pasajero. El programa debe además permitir agregar destinos y vuelos. Cada
vuelo tiene una fecha y horario de salida y capacidad de pasajeros. El programa debe también
listar el estado (cantidad de reservas, lugares disponibles, etc.) de todos los vuelos de un
destino solicitado al operador.
NOTA: Dado que no se requieren cálculos con las fechas y horarios de salida, se sugiere almacenar dicho campo
como una cadena.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoPasajero{
    long unsigned int dni;
    struct nodoPasajero *sig;}nodoPasajero;
typedef nodoPasajero *SublistaPasajeros;

typedef struct nodoVuelo{
    int codVuelo;
    char fechaSalida[14];
    int capacidadPasajeros;
    SublistaPasajeros subPasajeros;
    struct nodoVuelo *sig;}nodoVuelo;
typedef nodoVuelo *SublistaVuelos;

typedef struct nodoDestino{
    char destino[20];
    SublistaVuelos subVuelos;
    struct nodoDestino *sig;}nodoDestino;
typedef nodoDestino *TListaDestinos;

void reservaPasaje(TListaDestinos LD, char destino[], int codVuelo, long unsigned int dni);
void cancelaPasaje(TListaDestinos LD, char destino[], int codVuelo, unsigned long int dni);
void generaDestinos(TListaDestinos *LD);
void generaVuelos(TListaDestinos LD);
void agregaDestino(TListaDestinos *LD, char destino[20]);
void agregaVuelos(TListaDestinos LD, char destino[], int codVuelo, char fechaSalida[], int capacidadPasajeros);
void listaEstadoDestino(TListaDestinos LD, char destino[]);


int main()
{
    //probar...
    return 0;
}


void reservaPasaje(TListaDestinos LD, char destino[], int codVuelo, long unsigned int dni){
    int capacidadActual;
    TListaDestinos actD;
    SublistaVuelos actV;
    SublistaPasajeros nuevo, actP, antP;
    actD = LD;
    while(actD != NULL && strcmp(actD->destino, destino) != 0){
        actD = actD->sig;
    }
    if(actD != NULL){
        actV = actD->subVuelos;
        while(actV != NULL && codVuelo > actV->codVuelo)
            actV = actV->sig;
        if(actV != NULL  && codVuelo == actV->codVuelo){
            capacidadActual = 0;
            antP = NULL;
            actP = actV->subPasajeros;
            while(actP != NULL){
                antP = actP;
                actP = actP->sig;
                capacidadActual++;
            }
            if(capacidadActual < actV->capacidadPasajeros){
                nuevo = (SublistaPasajeros)malloc(sizeof(nodoPasajero));
                nuevo->dni = dni;
                nuevo->sig = NULL;
                if(actV->subPasajeros == NULL)
                    actV->subPasajeros = nuevo;
                else
                    antP->sig = nuevo;
            }
        }
    }
}

void cancelaPasaje(TListaDestinos LD, char destino[], int codVuelo, unsigned long int dni){
    TListaDestinos actD;
    SublistaVuelos actV;
    SublistaPasajeros actP, antP;
    actD = LD;
    while(actD != NULL && strcmp(actD->destino, destino) != 0)
        actD = actD->sig;
    if(actD != NULL){
        actV = actD->subVuelos;
        while(actV != NULL && codVuelo > actV->codVuelo)
            actV = actV->sig;
        if(actV != NULL && codVuelo == actV->codVuelo){
            antP = NULL;
            actP = actV->subPasajeros;
            while(actP != NULL && actP->dni != dni){
                antP = actP;
                actP = actP->sig;
            }
            if(actP != NULL){
                if(actP == actV->subPasajeros)
                    actV->subPasajeros = actP->sig;
                else
                    antP->sig = actP->sig;
                free(actP);
                actV->capacidadPasajeros -= 1;
            }
        }
    }
}

void generaDestinos(TListaDestinos *LD){
    TListaDestinos nuevoD;
    char destino[20];
    FILE *arch;
    arch = fopen("destinos.txt", "rt");
    *LD = NULL;
    if(arch != NULL){
        while(fscanf(arch, "%s", destino) == 1){
            nuevoD = (TListaDestinos)malloc(sizeof(nodoDestino));
            strcpy(nuevoD->destino, destino);
            nuevoD->subVuelos = NULL;
            if(*LD == NULL){
                *LD = nuevoD;
                nuevoD->sig = NULL;
            }
            else{
                nuevoD->sig = *LD;
                *LD = nuevoD;
            }
        }
        fclose(arch);
    }
}

void generaVuelos(TListaDestinos LD) {
    TListaDestinos actD;
    SublistaVuelos nuevoV;
    int i, codVuelo, capacidad;
    char fechaSalida[14];
    FILE *arch;

    actD = LD;
    arch = fopen("vuelos.txt", "rt");
    if(arch != NULL) {
        // Recorrer cada destino
        while(actD != NULL) {
            // Para cada destino, leer 3 vuelos
            for(i = 0; i < 3; i++) {
                // Leer datos del vuelo
                if(fscanf(arch, "%d %13s %d", &codVuelo, fechaSalida, &capacidad) == 3) {
                    // Crear nuevo vuelo
                    nuevoV = (SublistaVuelos)malloc(sizeof(nodoVuelo));
                    nuevoV->codVuelo = codVuelo;
                    strcpy(nuevoV->fechaSalida, fechaSalida);
                    nuevoV->capacidadPasajeros = capacidad;
                    nuevoV->subPasajeros = NULL;

                    // Insertar al inicio de la sublista de vuelos
                    nuevoV->sig = actD->subVuelos;
                    actD->subVuelos = nuevoV;
                }
            }
            // Pasar al siguiente destino
            actD = actD->sig;
        }
        fclose(arch);
    }
}

void agregaDestino(TListaDestinos *LD, char destino[20]){
    TListaDestinos nuevoD;
    nuevoD = (TListaDestinos)malloc(sizeof(nodoDestino));
    strcpy(nuevoD->destino, destino);
    nuevoD->subVuelos = NULL;
    nuevoD->sig= *LD;
    *LD = nuevoD;
}

void agregaVuelos(TListaDestinos LD, char destino[], int codVuelo, char fechaSalida[], int capacidadPasajeros){
    TListaDestinos actD;
    SublistaVuelos nuevoV, actV, antV;
    actD = LD;
    while(actD != NULL && strcmp(actD->destino, destino) != 0){
        actD = actD->sig;
    }
    if(actD != NULL){
        nuevoV = (SublistaVuelos)malloc(sizeof(nodoVuelo));
        nuevoV->codVuelo = codVuelo;
        strcpy(nuevoV->fechaSalida, fechaSalida);
        nuevoV->capacidadPasajeros = capacidadPasajeros;
        nuevoV->subPasajeros = NULL;
        if(actD->subVuelos == NULL || actD->subVuelos->codVuelo > codVuelo){
            nuevoV->sig = actD->subVuelos;
            actD->subVuelos = nuevoV;
        }
        else{
            antV = NULL;
            actV = actD->subVuelos;
            while(actV != NULL && actV->codVuelo < codVuelo){
                antV = actV;
                actV = actV->sig;
            }
            nuevoV->sig = actV;
            antV->sig = nuevoV;
        }
    }
}

void listaEstadoDestino(TListaDestinos LD, char destino[]){
    TListaDestinos actD;
    int cantReservas, lugaresDisponibles;
    SublistaVuelos actV;
    SublistaPasajeros actP;
    actD = LD;
    while(actD != NULL && strcmp(actD->destino, destino) != 0)
        actD = actD->sig;
    if(actD != NULL){
        printf("DESTINO: %s\n", actD->destino);
        actV = actD->subVuelos;
        while(actV != NULL){
            cantReservas = 0;
            actP = actV->subPasajeros;
            while(actP != NULL){
                cantReservas++;
                actP = actP->sig;
            }
            lugaresDisponibles = actV->capacidadPasajeros - cantReservas;
            printf("\nVuelo: %d\n", actV->codVuelo);
            printf("  Fecha y hora de salida: %s\n", actV->fechaSalida);
            printf("  Cantidad de reservas: %d\n", cantReservas);
            printf("  Lugares disponibles: %d\n", lugaresDisponibles);
            actV = actV->sig;
        }
    }
    else
        printf("El destino no existe.\n");
}
