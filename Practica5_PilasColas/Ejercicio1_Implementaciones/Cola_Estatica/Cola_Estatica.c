#include "Cola_Estatica.h"

void iniciaC(TCola *C){
    (*C).pri = (*C).ult = -1;
}

TElementoC consultaC(TCola C){
    if(C.pri != - 1)
        return C.datos[C.pri];
}

int vaciaC(TCola C){
    return C.pri == -1;
}

void poneC(TCola *C, TElementoC x){
    if((*C).ult != MAX - 1){
        if((*C).pri == -1)
            (*C).pri = 0;
        (*C).ult += 1;
        (*C).datos[(*C).ult] = x;
    }
}

void sacaC(TCola *C, TElementoC *x){
    if((*C).pri != -1){
        *x = (*C).datos[(*C).pri];
        if((*C).pri == (*C).ult)
            iniciaC(C);
        else
            (*C).pri += 1;
    }
}
