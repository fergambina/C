/*2) Dada una lista de enteros modificar cada aparición de X por X+1 */

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

void modificaLista(TLista L, int x){
    while(L != NULL){
        if(L->num == x)
            L->num += 1;
        L = L->sig;
    }
}

//Si la lista estuviera ordenada...
void modificaLista(TLista L, int x){
    aux = L;
    while(aux != L && aux->num < x){
        aux = aux->sig;
    }
    while(aux != NULL && aux->num == x){
        aux->num += 1;
        aux = aux->sig;
    }

}

void mostrarLista(TLista L){
    while(L != NULL){
        printf("%d\t", L->num);
        L = L->sig;
    }
}

int main()
{
    TLista L;
    int x;
    cargarLista(&L);
    printf("Ingrese x: ");
    scanf("%d", &x);
    mostrarLista(L);
    printf("\n");
    modificaLista(L, x);
    mostrarLista(L);
    return 0;
}

