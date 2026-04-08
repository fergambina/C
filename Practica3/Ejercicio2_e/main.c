#include <stdio.h>
#include <stdlib.h>

void leerVector(int v[], int *n);

int main()
{
    int A[DIM], B[DIM], C[DIM], a, b, c;
    leerVector(A, a);
    leerVector(B, b);
    return 0;
}


void leerVector(int v[], int *n){
    int i;
    printf("Ingrese cantidad de componentes: ");
    scanf("%d", n);
    for(i = 0; i < *n; i++){
        printf("Ingrese v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void generaVector(int A[]), int B[], int a, int b, int C[], int *c){



}
