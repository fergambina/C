#include "ColaEstaticaCircular.h"

void iniciaC (TCola *C){
    (*C).pri= (*C).ult=-1;  // C->pri = C -> ult = -1;
}

int vaciaC(TCola C){
  return C.pri==-1;
}

// Función para encolar (poner) un elemento en la cola circular
void poneC(TCola *C, TElementoC X) {
    // Verifica si la cola no está llena
    if (!(((*C).ult == MAX - 1) && ((*C).pri == 0)) || ((*C).ult + 1 == (*C).pri)) {
        // Caso en que la cola está vacía
        if ((*C).pri == -1) {
            (*C).pri = 0;
            (*C).ult = 0;
        } else {
            // Si llegó al final del arreglo, vuelve al inicio (cola circular)
            if ((*C).ult == MAX - 1) {
                (*C).ult = 0;
            } else {
                (*C).ult += 1;
            }
        }
        // Coloca el nuevo elemento en la posición correspondiente
        (*C).datos[(*C).ult] = X;
    }
}

// Función para desencolar (sacar) un elemento de la cola circular
void sacaC(TCola *C, TElementoC *X) {
    // Verifica si la cola no está vacía
    if ((*C).pri != -1) {
        // Guarda el elemento que se va a sacar
        *X = (*C).datos[(*C).pri];

        // Si solo había un elemento, se reinicia la cola
        if ((*C).pri == (*C).ult) {
            iniciaC(C);  // Suponiendo que existe esta función para reiniciar la cola
        } else {
            // Si el índice llega al final del arreglo, vuelve al inicio (cola circular)
            if ((*C).pri == MAX - 1) {
                (*C).pri = 0;
            } else {
                (*C).pri += 1;
            }
        }
    }
}

TElementoC consultaC (TCola C){
    if (C.pri !=-1)
       return C.datos[C.pri];
}

