#include <stdio.h>
#include "Pila.h"

int main()
{
    TPila P;
    TElementoP x, num;
    int cont = 0;
    cargaP(&P);
    printf("Ingrese X: ");
    scanf("%d", &x);
    while(!vaciaP(P)){
        sacaP(&P, &num);
        if(num == x)
            cont++;
    }
    printf("Cantidad de veces que aparece %d en la pila: %d", x, cont);
    return 0;
}

void cantApariciones(TPila *P, int x, int *cont){
    TElementoP num;
    *cont = 0;
    while(!vaciaP(*P)){
        sacaP(P, &num);
        if(num == x)
            *cont += 1;
    }
}

void cantApariciones(TPila *P, int x, int *cont){
    TPila PAux;
    TElementoP num;
    iniciaP(&PAux);
    while(!vaciaP(*P)){
        sacaP(P, &num);
        poneP(&PAux, num);
        if(num == x)
            *cont += 1;
    }
    while(!vaciaP(PAux)){
        sacaP(&PAux, &num);
        poneP(P, num);
    }
}
