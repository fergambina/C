/*Dada una lista simplemente enlazada de caracteres, contar la cantidad de vocales en los
primeros k nodos*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    char car;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

int esVocal(char car){
    car = toupper(car);
    return car == 'A' || car == 'E' || car == 'I' || car == 'O' || car == 'U';
}

int cantVocales(TLista L, int k){
    int cont = 0, i = 1;
    while(L != NULL && i <= k){
        if(esVocal(L->car))
            cont++;
        L = L->sig;
        i++;
    }
    return cont;
}

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

int main()
{
    TLista L;
    int k;
    cargarLista(&L);
    printf("Ingrese K: ");
    scanf("%d", &k);
    printf("Cantidad de vocales en los primeros %d nodos: %d", k, cantVocales(L, k));
    return 0;
}



