#include <stdio.h>
#include <stdlib.h>

int producto(int a, int b);

int main()
{
    int a, b;
    printf("Ingrese dos numeros positivos: ");
    scanf("%d %d", &a, &b);
    printf("El producto de %d por %d es: %d", a, b, producto(a, b));
    return 0;
}

int producto(int a, int b){
    if(b == 0)
        return 0;
    else
        return a + producto(a, b-1);

}
