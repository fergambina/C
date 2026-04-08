/*Rehacer el ejercicio 12 suponiendo que los números se encuentran en un archivo de texto,
todos en la misma línea. ¿Como modificaría la lectura, si hubiera un valor por línea?
    Desarrollar un programa que muestre la suma de un conjunto de números naturales ingresados
    por teclado. La serie finaliza al ingresar el número 0.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archt;
    int suma = 0, num;
    archt = fopen("numeros.txt", "r");
    if(archt == NULL)
        printf("Archivo no existente...\n");
    else{
        while(fscanf(archt,"%d ", &num) == 1){
            suma += num;
        }
        printf("La suma de los numeros del archivo es: %d", suma);
        fclose(archt);
    }
    return 0;
}
