#include <stdio.h>
#include <stdlib.h>

void cargarLista(TLista *L){
    TLista nuevo;
    FILE *arch;
    int num;
    *L = NULL;
    arch = fopen("numeros.TXT","rt");
    if(arch != NULL){
        while(fscanf(arch, "%d", &num) == 1){
            nuevo = (TLista)malloc(sizeof(nodo)); //Los datos se ingresan por la cabeza, es decir quedan invertidos a como esta en el archivo de texto.
            nuevo->num = num;
            nuevo->sig = *L;
            *L = nuevo;
        }
        fclose(arch);
    }
}

void eliminaAparicionesX(TLista *L, int x){
    TLista elim, ant = NULL, act = *L;
    while(act != NULL && act->num < x){
        ant = act;
        act = act->sig;
    }
    if(act != NULL && act->num == x){
        while(act != NULL && act->num == x){
            elim = act;
            act = act->sig;
            free(elim);
        }
        if(ant == NULL)
            *L = act;
        else
            ant->sig = act;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}

