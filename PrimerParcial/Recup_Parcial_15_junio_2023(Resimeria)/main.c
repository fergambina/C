#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoC{
    char pat[8], radio[4], vip, libre;
    int cantMaximaPasajeros;
    struct nodoC *sig;}nodoC;
typedef nodoC *TListaC;

typedef struct{
    int cantPasajeros;
    char vip, radio;
}TElementoC;   //VA EN COLA.H

typedef struct nodo{
    char pat[7]; //Ordenada por este campo
    TCola viajes;
    struct nodo *sig;}nodo;
typedef nodo *TLista;

int main()
{
    printf("Hello world!\n");
    return 0;
}

void procesaPedidos(TListaC LC, TLista *LV){
    FILE *archb;
    TElementoC viaje;
    TListaC actC;
    int cocheEncontrado;
    archb = fopen("VIAJES.DAT", "rb");
    if(archb != NULL){
        while(fread(&viaje, sizeof(viaje), 1, archb) == 1){
            cocheEncontrado = 0;
            actC = LC;
            do{
                actC = actC->sig;
                if(actC->libre == 'S'){
                    if(viaje.cantPasajeros <= actC->cantMaximaPasajeros && !(actC->vip == 'N' && viaje.vip == 'S') && strcmp(viaje.radio, actC->radio) <= 0){ //Corregir radio
                        actC->libre = 'N';
                        asignaViaje(LV, actC->pat, viaje);
                        cocheEncontrado = 1;
                        printf("Patente: %s", actC->pat);
                    }
                }
            }while(actC != LC && !cocheEncontrado);
        }
        fclose(archb);
    }
}

void asignaViaje(TLista *LV, char pat[], TElementoC viaje){
    TLista act, ant, nuevo;
    nuevo = (TLista)malloc(sizeof(nodo));
    strcpy(nuevo->pat, pat);
    iniciaC(&nuevo->viajes);
    poneC(&nuevo->viajes, viaje);
    act = *LV;
    if(*LV == NULL || strcmp(pat, (*LV)->pat) < 0){
        nuevo->sig = *LV;
        *LV = nuevo;
    }
    else{
        ant = NULL;
        while(act != NULL && strcmp(pat, act->pat) > 0){
            ant = act;
            act = act->sig;
        }
        if(act != NULL && strcmp(pat, act->pat) == 0){
            free(nuevo);
            poneC(act->viajes, viaje);
        }
        else{
            ant->sig = nuevo;
            nuevo->sig = act;
        }
    }
}

void eliminaViajes(TLista LV){
    TLista act;
    int cantEliminaciones, mayorElim = -1;
    char patMayor[8];
    TElementoC cent, viaje;
    cent.cantPasajeros = -1;
    act = LV;
    while(act != NULL){
        cantEliminaciones = 0;
        poneC(&(act->viajes), cent);
        saca(&(act->viajes), &viaje);
        while(viaje.cantPasajeros != cent.cantPasajeros){
            if(viaje.cantPasajeros != 0)
                poneC(&(act->viajes), viaje);
            else{
                cantEliminaciones++;
            }
            sacaC(&(act->viajes), viaje);
        }
        if(cantEliminaciones >= mayorElim){
            mayorElim = cantEliminaciones;
            strcpy(patMayor, act->pat);
        }
        act = act->sig;
    }
    if(mayorElim != -1)
        printf("Patente con mayor cantidad de eliminaciones: %s", patMayor);
    else
        printf("No hubo coches con eliminaciones.");
}


void eliminaCocheEInforma(TListaC *LC, TLista *LV, char pat[]){
    TListaC actC, antC;

    //Eliminacion lista circular
    actC = *LC;
    do{
        antC = act;
        actC = actC->sig;
    }while(actC != (*LC) && strcmp(actC->pat, pat) == 0);
    if((*LC)->sig == (*LC)){
        *LC = NULL;
        free(act);
    }
    else{
        if(act == (*LC)){
            antC->sig = actC->sig;
            *LC = antC;
        }
        else
            antC->sig = actC->sig;
        free(actC);
    }
}
