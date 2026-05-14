/*Calcular cociente y resto entre dos números enteros positivos a partir de restas sucesivas*/

#include <stdio.h>
#include <stdlib.h>

void division(int a, int b, int *c, int *r);

int main()
{
    int a, b, c, r;
    printf("Ingrese dos numeros positivos: ");
    scanf("%d %d", &a, &b);
    division(a, b, &c, &r);
    printf("Cociente; %d\nResto: %d", c, r);
    return 0;
}

void division(int a, int b, int *c, int *r){
    if(a < b){
        *c = 0;
        *r = a;
    }
    else{
        division(a - b, b, c, r);
        *c += 1;
    }


}


