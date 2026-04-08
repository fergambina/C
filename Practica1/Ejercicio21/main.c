#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 30

void leerVector(int [], unsigned int *);
void mostrarVector(int [], int);
void mostrarPosImpares(int [], int);
void generarVectorDivisibles(int [], unsigned int, int [],unsigned int *, int);
int buscaPos(int [], int , int);

int main()
{
    int vec[MAX], vecDiv[MAX];
    unsigned int n, m, pos;
    int k, x;
    char op;
    leerVector(vec, &n);
    printf("Vector cargado: ");
    mostrarVector(vec, n);
    do{
        do{
            printf("Ingrese una opcion (A-B-C o S para salir): ");
            scanf(" %c", &op);
            op = toupper(op);
        }while(op != 'A' && op != 'B' && op != 'C' && op !='S');
        switch(op){
        case 'A': mostrarPosImpares(vec, n);
                  printf("\n");
                  break;
        case 'B': printf("Ingrese un valor: ");
                  scanf("%d", &k);
                  generarVectorDivisibles(vec, n, vecDiv, &m, k);
                  mostrarVector(vecDiv, m);
                  break;
        case 'C': printf("Ingrese un valor: ");
                  scanf("%d", &x);
                  pos = buscaPos(vec, n, x);
                  if(pos == -1)
                    printf("El valor no se encuentra");
                  else
                    printf("El valor %d se encuentra en la posicion %d", x, pos);
                  break;
        case 'S': printf("Usted ha salido del programa...");
                  break;
        default: printf("Opcion incorrecta...");
        }

    }while(op != 'S');


    return 0;
}

void leerVector(int vec[],unsigned int *n){
    int i;
    do{
        printf("Ingrese cantidad de componentes del vector: ");
        scanf("%u", n);
    }while(n < 0);
    for(i = 0; i < *n; i++){
        printf("Ingrese componente %d: ", i);
        scanf("%d", &vec[i]);
    }
}

void mostrarVector(int vec[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d\t", vec[i]);
    }
}

void mostrarPosImpares(int vec[], int n){
    int i;
    for(i = 0; i < n; i++){            //Esta bien si pongo i += 2??
        if(i % 2 != 0)
            printf("%d\t", vec[i]);
    }
}

void generarVectorDivisibles(int vec[], unsigned int n, int vecDiv[], unsigned int *m, int k){
    int i;
    *m = 0;
    for(i = 0; i < n; i++)
        if(vec[i] % k == 0){
            vecDiv[*m] = vec[i];
            (*m)++;
        }
}

int buscaPos(int vec[], int n, int x){
    int i = 0;
    while(i < n && vec[i] != x)
        i++;
    if(i < n)
        return i;
    else
        return -1;
}
