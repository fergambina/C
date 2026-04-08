#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int suma = 0, num;
    printf("Ingrese un numero: ");
    scanf("%u", &num);
    while(num != 0){
        suma += num;
        printf("Ingrese un numero: ");
        scanf("%u", &num);
    }
    printf("La suma de los numeros ingresados es: %u", suma);
    return 0;
}
