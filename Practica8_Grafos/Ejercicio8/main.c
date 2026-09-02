#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}


/*Desarrollar funciones recursivas para:
generar un vector de registros con grado y vértice para aquellos vértices, de un grafo
almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3.  */

void generaVectorGrMayorA3(int mat[][DIM], TVec vec[], int N, int *nvec, int i, int j, int gr){
    if(i >= 0){
        gr += mat[i][j];
        if(gr > 3){
            vec[*nvec].vertice = i;
            vec[*nvec].grado = gr;
            (*nvec)++;
            generaVectorGrMayorA3(mat, vec, N, nvec, i - 1, N, 0);
        }
        else
            if(j > 0)
                generaVectorGrMayorA3(mat, vec, N, nvec, i, j - 1, gr);
            else
                generaVectorGrMayorA3(mat, vec, N, nvec, i - 1, N, gr);
    }
}
