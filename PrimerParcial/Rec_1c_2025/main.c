#include <stdio.h>
#include <stdlib.h>

typedef nodoC{
    char razonSocial[41];
    char prov[31];
    float porcComisionVenta;
    struct nodoC *sig;
}nodoC;
typedef struct nodoC *TListaC;

typedef struct{
    char razonSocial[41];
    float recauBruta, recauNeta;
}TResumen;

int main()
{
    printf("Hello world!\n");
    return 0;
}

void procesaVentas(TListaC LC, TPila *P){
    FILE *archB, *archT;
    arch = fopen("")

}
