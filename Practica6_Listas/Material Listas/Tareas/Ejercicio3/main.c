/*3) Destruir una lista simplemente enlazada */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *sig;
}nodo;
typedef struct nodo *TLista;



void cargarLista(TLista *L){
    TLista nuevo;
    FILE *arch;
    char car;
    *L = NULL;
    arch = fopen("caracteres.TXT","rt");
    if(arch != NULL){
        while(fscanf(arch, " %c", &car) == 1){
            nuevo = (TLista)malloc(sizeof(nodo)); //Los datos se ingresan por la cabeza, es decir quedan invertidos a como esta en el archivo de texto.
            nuevo->car = car;
            nuevo->sig = *L;
            *L = nuevo;
        }
        fclose(arch);
    }
}


void destruirLista(TLista *L){
    TLista aux;
    while(*L != NULL){
        aux = *L;
        *L = (*L)->sig;
        free(aux);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}



//Dada una lista de enteros, eliminar el ultimo nodo.
void eliminaUltimoNodo(TLista *L){
    TLista act ,ant;
    if(*L != NULL){
        if((*L)->sig == NULL){
            act = *L;
            *L = (*L)->sig;
            free(act);
        }
        else{
            ant = NULL;
            act = *L;
            while(act->sig != NULL){
                ant = act;
                act = act->sig;
            }
            free(act);
            ant->sig = NULL;
        }
    }
}
