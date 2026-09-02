#include <stdio.h>

// Declaración de las funciones
void generarArch();
void leeArch();

int main() {
    printf("--- Iniciando proceso ---\n");

    // 1. Generamos el archivo binario a partir del txt
    generarArch();

    printf("\n--- Resultados del Sensor ---\n");

    // 2. Leemos el binario y mostramos los cálculos
    leeArch();

    printf("\n--- Proceso finalizado ---\n");

    return 0;
}

void generarArch(){
    FILE *archt, *archb;
    float temp;
    archt = fopen("temperaturas.txt", "rt");
    if(archt != NULL){
        archb = fopen("temperaturas.dat", "wb");
        while(fscanf(archt, "%f", &temp) == 1)
            fwrite(&temp, sizeof(temp), 1, archb);
        fclose(archb);
        fclose(archt);
        printf("Archivo temperaturas.dat generado correctamente.\n");
    }
    else{
        printf("Archivo temperaturas.txt no existe.\n");
    }
}

void leeArch(){
    float temp, min = 999, max = -999, tot = 0;
    int cantMediciones = 0;
    FILE *archb;
    archb = fopen("temperaturas.dat", "rb");

    if(archb != NULL){
        while(fread(&temp, sizeof(temp), 1, archb) == 1){
            tot += temp;
            cantMediciones++;
            if(temp > max)
                max = temp;
            if(temp < min)
                min = temp;
        }
        fclose(archb);

        if(cantMediciones > 0){
            printf("Temperatura maxima: %5.2f\n", max);
            printf("Temperatura minima: %5.2f\n", min);
            printf("Temperatura promedio: %5.2f\n", tot / cantMediciones);
        } else {
            printf("El archivo estaba vacio.\n");
        }
    }
    else{
        printf("Archivo binario de temperaturas no existente...\n");
    }
}
