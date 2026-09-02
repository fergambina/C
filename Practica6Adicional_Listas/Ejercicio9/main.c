/*A partir de una lista circular no ordenada con los DNI (cadena de 8), sexo (carácter F-M), emitió
voto? (S-N)  de los votantes en el padrón de una mesa, resolver mediante una función para
cada item:
a) listar los votantes femeninos que han emitido el voto
b) contar los votantes de cada sexo (hayan o no votado).
c) buscar un DNI, que es dato, en la lista de votantes y mostrar si votó o no.
d) eliminar los votantes que no han emitido el voto y almacenar sus DNI en un archivo binario
(almacenando DNI y sexo). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char dni[9];
    char sexo, voto;
    struct nodo *sig;}nodo;
typedef struct nodo *TListaC;

void cargaVotantes(TListaC *LC);
void listarFemeninos(TListaC LC);
void cuentaVotantes(TListaC LC, int *cantMasc, int *cantFem);
void dniVoto(TListaC LC, char dni[]);

int main()
{
    TListaC LC;
    int cantMasc, cantFem;
    char dni[9];
    cargaVotantes(&LC);
    listarFemeninos(LC);
    printf("\n");
    cuentaVotantes(LC, &cantMasc, &cantFem);
    printf("Cantidad de votantes masculinos: %d\n", cantMasc);
    printf("Cantidad de votantes femeninos: %d\n", cantFem);
    printf("\n");
    printf("Ingrese un DNI: ");
    scanf("%s", dni);
    dniVoto(LC, dni);
    return 0;
}

void cargaVotantes(TListaC *LC){
    FILE *arch;
    TListaC nuevo;
    char dni[9], sexo, voto;
    *LC = NULL;
    arch = fopen("votantes.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%8s %c %c", dni, &sexo, &voto) == 3){
            nuevo = (TListaC)malloc(sizeof(nodo));
            strcpy(nuevo->dni, dni);
            nuevo->sexo = sexo;
            nuevo->voto = voto;
            if(*LC == NULL){
                nuevo->sig = nuevo;
                *LC = nuevo;
            }
            else{
                nuevo->sig = (*LC)->sig;
                (*LC)->sig = nuevo;
            }
        }
        fclose(arch);
    }
}

void listarFemeninos(TListaC LC){
    TListaC act;
    act = LC;
    printf("DNI'S DE PERSONAS FEMENINAS QUE HAN EMITIDO SU VOTO\n");
    if(LC != NULL){
        do{
            act = act->sig;
            if(act->sexo == 'F' && act->voto == 'S')
                printf("DNI: %s\n", act->dni);
        }while(act != LC);
    }
}

void cuentaVotantes(TListaC LC, int *cantMasc, int *cantFem){
    TListaC act;
    *cantMasc = 0;
    *cantFem = 0;
    act = LC;
    if(LC != NULL){
        do{
            act = act->sig;
            if(act->sexo == 'M')
                (*cantMasc)++;
            else
                (*cantFem)++;

        }while(act != LC);
    }
}

void dniVoto(TListaC LC, char dni[]){
    TListaC act;
    act = LC;
    if(LC != NULL){
        do{
            act = act->sig;
        }while(act != LC && strcmp(act->dni, dni) != 0);
        if(strcmp(act->dni, dni) == 0){
            if(act->voto == 'S')
                printf("La persona con DNI %s voto.", dni);
            else
                printf("La persona con DNI %s no voto.", dni);
        }
        else
            printf("El DNI ingresado no existe.");
    }
}

void dniQueNoVotaron(TListaC *LC){
    FILE *archB;
    TReg datos;
    TListaC act, ant, elim;
    archB = fopen("dnis.DAT", "wb");
    if(archB != NULL){
        if(*LC != NULL){
            ant = *LC;
            act = (*LC)->sig;
            do{
                if(act->voto == 'N'){
                    elim = act;
                    datos.sexo = act->sexo;
                    strcpy(datos.dni, act->dni);
                    fwrite(&datos, sizeof(TReg), 1, archB);
                    if(act == *LC && ant == *LC)
                        *LC = NULL;
                    else{
                        if(act == *LC){
                            ant->sig = (*LC)->sig;
                            *LC = ant;
                        }
                        else
                            ant->sig = act->sig;
                    }
                    act = act->sig;
                    free(elim);
                }
                else{
                    ant = act;
                    act = act->sig;
                }
            }while(*LC != NULL);
        }
        fclose(archB);
    }
}


