/* Realizar un programa iterativo que calcule e imprima el equivalente binario de un número
entero positivo dado.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    unsigned int bin[MAX], n = 0, num, i;
    printf("Ingrese un numero: ");
    scanf("%u", &num);
    while(num != 0){
        bin[n] = num % 2;
        n++;
        num /= 2;
    }
    printf("Convertido a binario ===> ");
    for(i = n - 1; i >= 0; i--)
        printf("%u", bin[i]);
    return 0;
}
