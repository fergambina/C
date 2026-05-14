/* Dada una lista simplemente enlazada de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro.  */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo{
    char car;
    struct nodo *sig;} nodo;
typedef nodo *TLista;

void cargaLista(TLista *L);
void muestraLista(TLista L);
int cantVocales(TLista L);
int estaOrdenada(TLista L);
void eliminaElemento(TLista *L, int P);

int main()
{
    TLista L;
    cargaLista(&L);
    int P;
    printf("Lista cargada con insercion al incio: \n");
    muestraLista(L);
    printf("\n");
    printf("Cantidad de vocales que contiene la lista: %d\n", cantVocales(L));
    if(estaOrdenada(L))
        printf("La lista esta ordenada.\n");
    else
        printf("La lista no esta ordenada.\n");
    printf("Ingrese posicion: ");
    scanf("%d", &P);
    eliminaElemento(&L, P);
    printf("Lista cargada con el elemento de la posicion %d eliminada: \n", P);
    muestraLista(L);
    return 0;
}

void cargaLista(TLista *L){
    FILE *arch;
    char car;
    TLista nuevo;
    *L = NULL;  //incializar en NULL en main o funcion??
    arch = fopen("caracteres.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, " %c", &car) == 1){
            nuevo = (TLista)malloc(sizeof(nodo));
            nuevo->car = car;
            nuevo->sig = *L;   //Inserto al inicio (caso de la pila)
            *L = nuevo;
        }
        fclose(arch);
    }
    else
        printf("Archivo no existente...");
}

void muestraLista(TLista L){
    TLista aux;
    aux = L;
    while(aux != NULL){
        printf("%c\t", aux->car);
        aux = aux->sig;
    }
}

int esVocal(char car){
    car = toupper(car);
    if(car == 'A' || car == 'E' || car == 'I' || car == 'O' || car == 'U')
        return 1;
    else
        return 0;
}

int cantVocales(TLista L){
    int cont = 0;
    TLista aux;
    aux = L;
    while(aux != NULL){
        if(esVocal(aux->car))
            cont++;
        aux = aux->sig;
    }
    return cont;
}

int estaOrdenada(TLista L){
    TLista act, ant;
    if(L == NULL || L->sig == NULL) //Si la lista esta vacia o tiene un solo elemento: esta ordenada
        return 1;
    else{ //Si tiene dos elementos o mas recorro la lista
        ant = L;
        act = ant->sig;
        while(act != NULL && act->car < ant->car){
            ant = act;
            act = act->sig;
        }
        return act == NULL;
    }
}

void eliminaElemento(TLista *L, int P){
    TLista act, ant, aux;
    int i;
    if(*L != NULL)
        if(P > 0){
            if(P == 1){
                aux = *L;
                *L = (*L)->sig;
                free(aux);
            }
            else{
                i = 1;
                ant = NULL;
                act = *L;
                while(act != NULL && i != P){
                    ant = act;
                    act = act->sig;
                    i++;
                }
                if(act != NULL && i == P){
                    ant->sig = act->sig;
                    free(act);
                }
            }
        }
}
