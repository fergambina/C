#include <stdlib.h>
#define MAX 30

typedef struct{
    char nombre[MAX];
    unsigned int puntaje;
}TElementoC;

typedef struct nodo {
    TElementoC dato;
    struct nodo *sig;
}nodo;

typedef struct {
    nodo *pri;
    nodo *ult;
}TCola;

void iniciaC(TCola *C);
int vaciaC(TCola C);
void poneC(TCola *C, TElementoC X);
void sacaC(TCola *C, TElementoC *X);
TElementoC consultaC(TCola C);

