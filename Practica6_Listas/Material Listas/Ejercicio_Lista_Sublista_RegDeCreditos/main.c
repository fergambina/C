/* Se tiene una lista de clientes que registran pagos de un crédito con el siguiente diseño:
o Numero de Cliente (no se repite, ordenado ascendente)
o Total Credito, Total Adeudado (en $)
o Sublista de Pagos - Fecha  (Ordenada descendente, no se repite)  - Importe
Se pide:
a.- Dado un número de cliente correcto, una fecha y un importe, insertar el pago actualizando el valor
adeudado.
b.- Dado un número de cliente y una fecha, eliminar el pago (si existe) actualizando el valor adeudado.
c.- Dado un número de cliente, eliminarlo de la lista. Informar la cantidad de pagos que había realizado.
d.- Eliminar de la lista los clientes que ya no tienen deuda. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11

typedef struct nodito{
    char fecha[MAX]; //Ordenada descendentemente
    float importe;
    struct nodito *sig;
}nodito;
typedef struct nodito *Sublista;


typedef struct nodoC{
    int numC; //Ordenado ascendentemente por este campo.
    float cred, deuda;
    struct nodoC *sig;
    Sublista sub;
}nodoC;
typedef struct nodoC *TListaC;



void cargaClientes(TListaC *LC){
    TListaC antC, actC, nuevoC;
    int numC;
    float cred, deuda;
    FILE *arch;
    *LC = NULL;
    arch = fopen("clientes.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%d %f %f", &numC, &cred, &deuda) == 3){
            nuevoC = (TListaC)malloc(sizeof(nodoC));
            nuevoC->numC = numC;
            nuevoC->cred = cred;
            nuevoC->deuda = deuda;
            nuevoC->sub = NULL;
            if(*LC == NULL || (*LC)->numC > numC){
                nuevoC->sig = *LC;
                *LC = nuevoC;
            }
            else{
                actC = *LC;
                while(actC != NULL && actC->numC < numC){
                    antC = actC;
                    actC = actC->sig;
                }
                nuevoC->sig = actC;
                antC->sig = nuevoC;
            }
        }
    }
}


void cargaPagosInicialesClientes(TListaC LC){
    FILE *arch;
    char fecha[MAX];
    float imp;
    int numC;
    TListaC aux;
    Sublista antS, actS, nuevoS;
    arch = fopen("pagos.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%s %f %d", fecha, &imp, &numC) == 3){
            aux = LC;
            while(aux != NULL && aux->numC != numC)
                aux = aux ->sig;
            nuevoS = (Sublista)malloc(sizeof(nodito));
            nuevoS->importe = imp;
            strcpy(nuevoS->fecha, fecha);
            actS = aux->sub;
            while(actS != NULL && strcmp(actS->fecha, fecha) > 0){
                antS = actS;
                actS = actS->sig;
            }
            if(actS == aux->sub){
                nuevoS->sig = aux->sub;
                aux->sub = nuevoS;
            }
            else{
                nuevoS->sig = actS;
                antS->sig = nuevoS;
            }
        }
    }
}


void mostrarClientes(TListaC LC){
    Sublista actS;
    while(LC != NULL){
        printf("Numero de cliente: %d\t", LC->numC);
        printf("Total credito: %5.2f\t", LC->cred);
        printf("Total adeudado: %5.2f\n", LC->deuda);
        printf("Pagos: \n");
        actS = LC->sub;
        while(actS != NULL){
            printf("\t - Fecha: %s  Importe: %5.2f\n", actS->fecha, actS->importe);
            actS = actS->sig;
        }
        printf("\n");
        LC = LC->sig;
    }
}

void mostrarDatosCliente(TListaC LC, int numC){
    Sublista actS;
    while(LC != NULL && numC != LC->numC)
        LC = LC->sig;
    printf("Numero de cliente: %d\t", LC->numC);
    printf("Total credito: %5.2f\t", LC->cred);
    printf("Total adeudado: %5.2f\n", LC->deuda);
    printf("Pagos: \n");
    actS = LC->sub;
    while(actS != NULL){
        printf("\t - Fecha: %s  Importe: %5.2f\n", actS->fecha, actS->importe);
        actS = actS->sig;
    }
    printf("\n");
}




/*Dado un número de cliente correcto, una fecha y un importe, insertar el pago actualizando el valor adeudado*/
void insertaPago(TListaC LC, int numC, char fecha[], float importe){
    Sublista antS, actS, nuevo;
    while(LC->numC != numC)  //El numero de cliente pasado como parametro es correcto. Por eso uso el '!='
        LC = LC->sig;
    LC->deuda -= importe;
    nuevo = (Sublista)malloc(sizeof(nodito));
    strcpy(nuevo->fecha, fecha);
    nuevo->importe = importe;
    actS = LC->sub;
    while(actS != NULL && strcmp(actS->fecha, fecha) > 0){
        antS = actS;
        actS = actS->sig;
    }
    if(actS == LC->sub){
        nuevo->sig = LC->sub;
        LC->sub = nuevo;
    }
    else{
        nuevo->sig = actS;
        antS->sig = nuevo;
    }
}

/*b) Dado un número de cliente y una fecha, eliminar el pago (si existe) actualizando el valor adeudado.*/
void eliminaPago(TListaC LC, int numC, char fecha[]){
    Sublista antS, actS;
    TListaC aux = LC;
    while(aux != NULL && numC > aux->numC)
        aux = aux->sig;
    if(aux != NULL && numC == aux->numC){ //Existe cliente.
        actS = aux->sub;
        while(actS != NULL && strcmp(actS->fecha, fecha) > 0){
            antS = actS;
            actS = actS->sig;
        }
        if(actS != NULL && strcmp(actS->fecha, fecha) == 0){ //Existe el pago.
            aux->deuda += actS->importe;
            if(actS == aux->sub)
                aux->sub = actS->sig;
            else
                antS->sig = actS->sig;
            free(actS);
        }
    }
}

/*c)Dado un número de cliente, eliminarlo de la lista. Informar la cantidad de pagos que había realizado*/
void eliminaCliente(TListaC *LC, int numC, unsigned int *cantPagos){
    TListaC antC, actC;
    Sublista elim;
    *cantPagos = 0;
    actC = *LC;
    while(actC != NULL && actC->numC < numC){
        antC = actC;
        actC = actC->sig;
    }
    if(actC != NULL && actC->numC == numC){
        while(actC->sub != NULL){
            elim = actC->sub;
            actC->sub = elim->sig;
            *cantPagos += 1;
            free(elim);
        }
        if(actC == *LC)
            *LC = (*LC)->sig;
        else
            antC->sig = actC->sig;
        free(actC);
    }
}

/*d) Eliminar de la lista los clientes que ya no tienen deuda. */
void eliminaClientesSinDeuda(TListaC *LC){
    TListaC antC, actC, elimC;
    Sublista elim;
    actC = *LC;
    while(actC != NULL){
        if(actC->deuda == 0){
            while(actC->sub != NULL){ //Eliminacion de la sublista de pagos
                elim = actC->sub;
                actC->sub = elim->sig;
                free(elim);
            }
            elimC = actC; //Eliminacion del cliente
            actC = actC->sig;
            if(elimC == *LC)
                *LC = (*LC)->sig;
            else
                antC->sig = actC;
            free(elimC);
        }
        else{
            antC = actC;
            actC = actC->sig;
        }
    }
}


int main()
{
    TListaC LC;
    unsigned int op, cantPagos;
    int numC;
    char fecha[MAX];
    float importe;
    cargaClientes(&LC);
    cargaPagosInicialesClientes(LC);
    do{
        system("cls");
        printf("--SISTEMA DE GESTION DE CREDITOS--\n");
        printf("1 - Insertar pago.\n");
        printf("2 - Eliminar pago.\n");
        printf("3 - Eliminar cliente.\n");
        printf("4 - Eliminar todos los clientes que no tienen deuda.\n");
        printf("5 - Mostrar clientes.\n");
        printf("6 - Finalizar.\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 1:
                printf("Ingrese numero de cliente: ");
                scanf("%d", &numC);
                printf("Ingrese fecha [aaaa/mm/dd]: ");
                scanf("%s", fecha);
                printf("Ingrese importe: ");
                scanf("%f", &importe);
                insertaPago(LC, numC, fecha, importe);
                break;
            case 2:
                printf("Ingrese numero de cliente: ");
                scanf("%d", &numC);
                printf("Ingrese fecha [aaaa/mm/dd]: ");
                scanf("%s", fecha);
                eliminaPago(LC, numC, fecha);
                break;
            case 3:
                printf("Ingrese numero de cliente: ");
                scanf("%d", &numC);
                eliminaCliente(&LC, numC, &cantPagos);
                printf("Cantidad de pagos del cliente: %d\n", cantPagos);
                break;
            case 4:
                eliminaClientesSinDeuda(&LC);
                break;
            case 5:
                mostrarClientes(LC);
                break;
            default: printf("Opcion no valida...Por favor ingrese una opcion nuevamente.\n");
        }
        if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5){
            printf("\n");
            system("pause"); // Esto mostrará "Presione una tecla para continuar..." y esperará.
        }
    }while(op != 6);
    return 0;
}
