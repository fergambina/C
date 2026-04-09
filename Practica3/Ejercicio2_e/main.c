/*Dado dos arreglos de enteros A y B ordenados ascendentemente, mezcle ambos arreglos en
otro C manteniendo el orden pero sin pasar los elementos repetidos.*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 30

void leerVector(int v[], int *n);
void escribirVector(int v[], int n);
void mezcla(int A[], int i, int n1, int B[], int j, int n2, int C[], int *n3);

int main()
{
    int A[DIM], B[DIM], C[DIM], n1, n2, n3;
    leerVector(A, &n1);
    leerVector(B, &n2);
    mezcla(A, 0, n1, B, 0, n2, C, &n3);
    printf("Vector A: ");
    escribirVector(A, n1);
    printf("\n");
    printf("Vector B: ");
    escribirVector(B, n2);
    printf("\n");
    printf("Vector C: ");
    escribirVector(C, n3);
    printf("\n");
    return 0;
}

void escribirVector(int v[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d\t", v[i]);
    }
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

void mezcla(int A[], int i, int n1, int B[], int j, int n2, int C[], int *n3) {
    if (i < n1 && j < n2) {
        if (A[i] < B[j]) {
            if (A[i] != C[*n3 - 1]) {
                C[*n3] = A[i];
                (*n3)++;
            }
            mezcla(A, i + 1, n1, B, j, n2, C, n3);
        } else {
            if (B[j] != C[*n3 - 1]) {
                C[*n3] = B[j];
                (*n3)++;
            }
            mezcla(A, i, n1, B, j + 1, n2, C, n3);
        }
    } else {
        if (i < n1) {
            if (A[i] != C[*n3 - 1]) {
                C[*n3] = A[i];
                (*n3)++;
            }
            mezcla(A, i + 1, n1, B, j, n2, C, n3);
        } else {
            if (j < n2) {
                if (B[j] != C[*n3 - 1]) {
                    C[*n3] = B[j];
                    (*n3)++;
                }
                mezcla(A, i, n1, B, j + 1, n2, C, n3);
            }
        }
    }
}
