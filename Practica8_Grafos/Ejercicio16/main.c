#include <stdio.h>
#include <stdlib.h>
#define DIM 30

//Carga matriz de adyacencia de un grafo desde un archivo de texto.
void cargaMatrizAdyDigrafo(int matAdy[][DIM], int *N){
    int i, j;
    FILE *arch;
    arch = fopen("digrafo.txt", "rt");
    fscanf(arch, "%d", N);
    for(i = 0; i < *N; i++)
        for(j = 0; j < *N; j++)
            fscanf(arch, "%d", &matAdy[i][j]);
    fclose(arch);
}

int conjuntoCompleto(int S[], int N){
    int i = 0;
    while(i < N && S[i])
        i++;
    return i == N;
}

int posMinimoValor(int D[], int S[], int N){
    int minAux = 9999, iMin = -1, i;
    for(i = 0; i < N; i++){
        if(D[i] < minAux && !S[i]){
            minAux = D[i];
            iMin = i;
        }
    }
    return iMin;
}

int min(int a, int b){
    return a < b ? a : b;
}


void dijkstra(int matAdy[][DIM], int N, int origen, int D[], int P[]){
    int S[N];
    int j, k, d;
    for(j = 0; j < N; j++){
        S[j] = 0;
        if(matAdy[origen][j] > 0){
            D[j] = matAdy[origen][j];
            P[j] = 0;
        }
        else
            D[j] = P[j] = 9999;
    }
    D[origen] = 0;
    S[origen] = 1;
    P[origen] = 0;
    while(!conjuntoCompleto(S, N)){
        k = posMinimoValor(D, S, N); //Elegi el vertice k (de V-S) tal que D[k] sea minima. Agregar W a S.
        S[k] = 1;
        for(j = 0; j < N; j++){
            d = D[j];
            if(S[j] == 0 && matAdy[k][j] != 0)
                D[j] = min(D[j], D[k] + matAdy[k][j]);
            if(d != D[j])
                P[j] = k + 1;
        }
    }
}


int main()
{
    int digrafo[DIM][DIM], N, D[DIM], P[DIM], i, j;
    cargaMatrizAdyDigrafo(digrafo, &N);
    for (i = 0; i < N; i++)
    {
        dijkstra(digrafo, N, i, D, P);
        for (j = 0; j < N; j++)
            printf("%d\t", P[j]);
        printf("\n");
    }
    return 0;
}

