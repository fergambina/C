#include <stdio.h>
#include <stdlib.h>
#define DIM 30

//Carga matriz de adyacencia de un grafo desde un archivo de texto.
void cargaMatrizAdyGrafo(int matAdy[][DIM], int *N){
    FILE *arch;
    arch = fopen("grafo.txt", "rt");
    fscanf(arch, "%d", N);
    for(i = 0; i < *N; i++)
        for(j = 0; j < *N; j++)
            fscanf(arch, "%d", matAdy[i][j]);
    fclose(arch);
}

void kruskal(int matAdy[][DIM], int N, int matAdyAAM[][DIM]){
    int CC[N], auxMatAdy[N][N], i, j, iMin, jMin, min;
    for(i = 0 ; i < N; i++){
        CC[i] = i;
        for(j = 0; j < N; j++){
            auxMatAdy[i][j] = matAdy[i][j];
            matAdyAAM[i][j] = 0;
        }
    }
    while(!esConexo(CC, N)){
        min = 9999;
        for(i = 0; i < N - 1; i++){
            for(j = i + 1; j < N; j++)
                if(CC[i] !== CC[j] && auxMatAdy[i][j] < min && auxMatAdy[i][j] > 0){
                    min = auxMatAdy[i][j];
                    iMin = i;
                    jMin = j;
                }
        }
        mat
    }
}

int esConexo(int CC[], int N){
    int i = 1;
    while(i < N && CC[i] == CC[0])
        i++;
    if(i == N)
        return 1;
    else
        return 0;
}


int main()
{
    int matAdy[DIM][DIM];
    int N;
    cargaMatrizAdyGrafo(matAdy, &N);
    return 0;
}
