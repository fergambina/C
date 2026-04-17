#include <stdio.h>
#include <stdlib.h>
#define DIM 1000

int main()
{
    char expresion[DIM];
    TPila p;
    printf("Ingrese la expresion en notacion postfija: ");
    scanf("%s", expresion);
    cargarOperacion(&p);

    return 0;
}
