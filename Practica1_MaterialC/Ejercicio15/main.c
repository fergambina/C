/*Desarrollar una función que reciba tres números enteros y devuelva si son consecutivos entre sí
o si no lo son. */

#include <stdio.h>
#include <stdlib.h>

void consecutivos(int n1, int n2, int n3);

int main()
{
    int n1, n2, n3;
    printf("Ingrese n1: ");
    scanf("%d", &n1);
    printf("Ingrese n2: ");
    scanf("%d", &n2);
    printf("Ingrese n3: ");
    scanf("%d", &n3);
    consecutivos(n1, n2, n3);
    return 0;
}

void consecutivos(int n1, int n2, int n3){
    if((n1 - n2 == 1 && n2 - n3 == 1)||(n3 + n2 == -1 && n2 + n1 == -1))
        printf("Los numeros son consecutivos");
    else
        printf("Los numeros no son consecutivos");
}
