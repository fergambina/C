/*Desarrollar un programa que cree un arreglo estático de punteros a enteros, y luego cargue en
él una cantidad desconocida de enteros (se encuentran en un archivo de texto). Posteriormente
a la carga, mostrar aquellos que sean positivos. Luego, para finalizar, liberar la memoria
solicitada en tiempo de ejecución. */

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int main()
{
    int *ptr[DIM], n = 0, num, i;
    FILE *arch;
    arch = fopen("numeros.txt", "r");
    if(arch == NULL)
        printf("Archivo no existente...");
    else{
        while(fscanf(arch,"%d", &num) == 1){
            ptr[n] = (int *) malloc(sizeof(int));
            *ptr[n] = num;
            n++;
        }
        fclose(arch);
        printf("Numeros positivos...\n");
        for(i = 0; i < n; i++)
            if(*ptr[i] > 0)
                printf("%d\t", *ptr[i]);
        for(i = 0; i < n; i++)
            free(ptr[i]);
    }
    return 0;
}
