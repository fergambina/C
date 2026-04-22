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

int main()
{
    TLista L;
    cargaLista(&L);
    printf("Lista cargada con insercion al incio: \n");
    muestraLista(L);
    printf("\n");
    printf("Cantidad de vocales que contiene la lista: %d", cantVocales(L));
    if(estaOrdenada(L))
        printf("La lista esta ordenada.");
    else
        printf("La lista no esta ordenada.");
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
    int ordenada = 1;

}
