/* Desarrollar un programa que lea y procese un archivo de texto generado por un radar vigía.
Cada línea contiene patente de un vehículo (ANU7: alfanumérico de 7 caracteres), velocidad
registrada (entero positivo), velocidad máxima permitida (entero positivo), fecha y hora de la
medición (ANU16, formato aaaa/mm/dd hh:nn). Cada dato está separado por un espacio. El
programa debe generar un archivo binario con los registros donde la velocidad registrada
supere en más de un 20% a la velocidad máxima. Cada registro del archivo binario contiene los
mismos datos que el archivo de texto. Mostrar, al final del proceso, la cantidad de mediciones
procesadas y la cantidad de registros generados en el archivo binario. */

#include <stdio.h>
#include <stdlib.h>

typedef char st7[8];
typedef char st16[17];
typedef struct{
    st7 pat;
    unsigned int vel, vel_permitida;
    st16 fecha_hora;
}TReg;

int main()
{
    FILE *archt, *archb;
    TReg reg;
    unsigned int cant_mediciones = 0, cant_registros = 0;
    archt = fopen("radar_vigia.txt", "rt");
    if(archt != NULL){
        archb = fopen("radar_vigia.dat", "wb");
        if(archb != NULL){
            while(fscanf(archt, "%s %u %u %[^\n]", reg.pat, &reg.vel, &reg.vel_permitida, reg.fecha_hora) == 4){
                cant_mediciones++;
                if(reg.vel > reg.vel_permitida*1.20){
                    fwrite(&reg, sizeof(reg), 1, archb);
                    cant_registros++;
                }
            }
            fclose(archt);
            fclose(archb);
            printf("Cantidad de mediciones: %u", cant_mediciones);
            printf("Cantidad de registros generados en el archivo binario: %u", cant_registros);
        }
        else{
            fclose(archt);
            printf("Error al crear archivo binario.")
        }
    }
    else
        printf("Error al abrir el archivo de texto");
    return 0;
}
