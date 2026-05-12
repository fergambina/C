#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilas.h"

typedef struct nodoC{
    char cod[6];
    struct nodoC *sig;}nodoC;
typedef nodoC *SublistaCorrelativas;

typedef struct nodoM{
    char cod[6];
    char nom[26];
    unsigned int cuatri, cantCreditos;
    SublistaCorrelativas subCorrelativas;
    struct nodoM *sig;}nodoM;
typedef nodoM *TLista;

typedef struct nodoD{
    int cuatri;
    TPila materias;
    struct nodoD *ant, *sig;}nodoD;
typedef nodoD *PnodoD;

typedef struct{
    PnodoD pri, ult;
}TListaD;

int main()
{
    printf("Hello world!\n");
    return 0;
}


void generarArchivo(TLista L, char cod[]){
    FILE *arch;
    TLista aux;
    SublistaCorrelativas actC;
    int cantCorrelativas = 0, totCreditos = 0;
    aux = L;
    while(strcmp(cod, aux->cod) != 0)
        aux = aux->sig;
    arch = fopen(strcat(".TXT", cod), "wt");
    if(arch != NULL){
        fprintf(arch, "%s %d", aux->nom, aux->cuatri);
        actC = aux->subCorrelativas;
        while(actC != NULL){
            //buscaNombre(L, actC->cod, nom, creditos);
            //fprintf(arch, "%s", nom);
            cantCorrelativas++;
           //totCreditos += creditos;
            actC = actC->sig;
        }
        if(cantCorrelativas > 0){
            //fprintf(arch, "%f", (float)totCreditos/cantCorrelativas);
        }
        else
            fprintf(arch, "No tiene correlativas anteriores");
    }
}

void generaLista(TLista L, TListaD *LD){
    PnodoD act, nuevo;
    TLista aux;
    TElementoP materia;
    (*LD).pri = NULL;
    (*LD).ult = NULL;
    aux = L;
    while(aux != NULL){
        nuevo = (PnodoD)malloc(sizeof(nodoD));
        nuevo->cuatri = aux->cuatri;
        strcpy(materia.cod, aux->cod);
        materia.creditos = aux->cantCreditos;
        iniciaP(&(nuevo->materias));
        poneP(&(nuevo->materias), materia);
        if((*LD).pri == NULL || aux->cuatri < (*LD).pri->cuatri){
            nuevo->ant = NULL;
            nuevo->sig = (*LD).pri;
            if((*LD).pri == NULL)
                (*LD).ult = nuevo;
            else
                (*LD).pri->ant = nuevo;
            (*LD).pri = nuevo;
        }
        else{
            if((*LD).ult->cuatri < aux->cuatri){
                nuevo->sig = NULL;
                nuevo->ant = (*LD).ult;
                (*LD).ult->sig = nuevo;
                (*LD).ult = nuevo;
            }
            else{
                act = (*LD).pri;
                while(act != NULL && act->cuatri < aux->cuatri)
                    act = act->sig;
                if(act != NULL && act->cuatri == aux->cuatri){
                    materia.creditos = aux->cantCreditos;
                    strcpy(materia.cod, aux->cod);
                    poneP(&(act->materias), materia);
                    free(nuevo);
                }
                else{
                    nuevo->sig = act;
                    nuevo->ant = act->ant;
                    act->ant->sig = nuevo;
                    act->ant = nuevo;
                }
            }
        }
        aux = aux->sig;
    }
}



void quitarAsignatura(TLista *L, TListaD LD,char cod[]){
    TLista antA, actA, pantA, pactA;
    SublistaCorrelativas antC, actC;
    int cuatriMateria;
    antA = NULL;
    actA = *L;
    while(actA != NULL && strcmp(actA->cod, cod) < 0){
        antA = actA;
        actA = actA->sig;
    }
    if(actA != NULL && strcmp(actA->cod, cod) == 0){
        cuatriMateria = actA->cuatri;
        pantA = antA; //Para eliminar el nodo de la lista simple
        pactA = actA;  //Para eliminar el nodo de la lista simple
        //Recorrido de todas las sublista de correlatividades.
        antA = NULL;
        actA = *L;
        while(actA != NULL){
            if(actA->subCorrelativas != NULL){
                if(strcmp(actA->subCorrelativas->cod, cod) == 0){
                    actC = actA->subCorrelativas;
                    actA->subCorrelativas = actC->sig;
                    free(actC);
                }
                else{
                    actC = actA->subCorrelativas;
                    while(actC != NULL && strcmp(actA->cod, cod) != 0){
                        antC = actC;
                        actC = actC->sig;
                    }
                    if(actC != NULL){
                        antC->sig = actC->sig;
                        free(actC);
                    }
                }
            }
            actA = actA->sig;
        }
        if(pantA == NULL)
            *L = pactA->sig;
        else
            pantA->sig = pactA->sig;
        free(pantA);
        //Eliminacion de la asignatura de la Pila.
        //eliminaDeLaPila(LD, cuatriMateria, cod);
    }
    else
        printf("Codigo de materia invalido...");
}

void sacaMateria(TPila *P, char cod, int *materiaEliminada){ //Llamo con 0
    TElementoP materia;
    if(!vaciaP(*P) && !(*materiaEliminada)){
        sacaP(P, &materia);
        if(strcmp(materia.cod, cod) != 0){
            sacaMateria(P, cod, materiaEliminada);
            poneP(P, materia);
        }
        else
            *materiaEliminada = 1;
    }

}

void eliminaDeLaPila(TListaD LD, int cuatriMateria, char cod[]){
    PnodoD actC;
    actC = LD.pri;
    while(actC->cuatri != cuatriMateria)
        actC = actC->sig;
    sacaMateria(&(actC->materias), cod);
}


