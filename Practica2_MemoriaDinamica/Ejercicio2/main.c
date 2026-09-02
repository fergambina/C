/*Corregir el siguiente programa para que los valores de las variables  a y b resulten ordenados de
manera ascendente:
#include <stdio.h>
int main(){
int a = 30, b = 20;
ordenadas(a, b);
printf(" valor de a %d\tvalor de b %d\n", &a, &b);
return 0;
}
void ordenadas(int x, int y){
int* aux;
if(x > y) {
aux = x;
x = y;
y = aux;
}
} */

#include <stdio.h>
#include <stdlib.h>

void ordenadas(int *x, int *y){
    int aux;
    if(*x > *y){
        aux = *x;
        *x = *y;
        *y = aux;
    }
}

int main()
{
    int a = 30, b = 20;
    ordenadas(&a, &b);
    printf(" valor de a %d\tvalor de b %d\n", a, b);
    return 0;
}
