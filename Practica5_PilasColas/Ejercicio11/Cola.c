#include <stdlib.h>
#include "Cola.h"

void iniciaC (TCola *C){
 (*C).pri = (*C).ult = NULL; // C->pri = C -> ult = NULL;
}

int vaciaC(TCola C){
  return C.pri==NULL;
}

void poneC (TCola *C, TElementoC X){
   nodo * aux;
   aux = (nodo *) malloc (sizeof(nodo));
   aux->dato = X;
   aux->sig = NULL;
   if ((*C).pri==NULL)
      (*C).pri=aux;
   else
      (*C).ult->sig=aux;
  (*C).ult=aux;
}

void sacaC (TCola *C, TElementoC *X){
  nodo * aux;
  if ((*C).pri !=NULL) {
     aux = (*C).pri;
   *X = aux->dato;
   (*C).pri = (*C).pri->sig;
   if ((*C).pri == NULL)
      (*C).ult = NULL;
   free(aux);
   }
}

TElementoC consultaC (TCola C){
    if (C.pri !=NULL)
       return C.pri-> dato;
}

TElementoC crearEmpleado(long unsigned int legajo, unsigned int momento_arribo, unsigned int duracion_uso){
    TElementoC empleado;
    empleado.legajo = legajo;
    empleado.momento_arribo = momento_arribo;
    empleado.duracion_uso = duracion_uso;
    return empleado;
}

long unsigned int obtenerLegajo(TElementoC empleado){
    return empleado.legajo;
}

unsigned int obtenerMomentoArribo(TElementoC empleado){
    return empleado.momento_arribo;
}

unsigned int obtenerDuracionUso(TElementoC empleado){
    return empleado.duracion_uso;
}
