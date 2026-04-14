#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}


void cantApariciones(TCola *C, int *cont, TElementoC x){
    TElementoC dato;
    *cont = 0;
    while(!VaciaC(*C)){
        sacaC(C, &dato);
        if(dato == x)
            (*cont)++;
    }
}

void cantApariciones(TCola *C, int *cont, TElementoC x){
    TCola CAux;
    TElementoC num;
    *cont = 0;
    iniciaC(&CAux);
    while(!vaciaC(*C)){
        sacaC(C, &num);
        poneC(&CAux, num);
        if(dato == x)
            (*cont)++;
    }
    while(!vaciaC(CAux)){
        sacaC(&CAux, &num);
        poneC(C, num);
    }
}
