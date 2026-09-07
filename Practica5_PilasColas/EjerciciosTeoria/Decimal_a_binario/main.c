#include <stdio.h>
#include <stdlib.h>

int main()
{
    TPila P;
    TElementoP bit;
    int num, numero;
    iniciaP(&P);
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    num = numero;
    while(numero != 0){
        poneP(&P, numero % 2);
        numero /= 2;
    }
    printf("Representacion de %d en base 2\n", num);
    while(!vaciaP(P)){
        sacaP(&P, &bit);
        printf("%d", bit);
    }
    return 0;
}
