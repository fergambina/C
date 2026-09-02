/*El ranking de una asociación de tenistas es registrada en un archivo binario. Para cada jugador
se registra apellido y nombre, nacionalidad y puntaje. Realizar un subprograma que muestre los
datos del jugador ubicado en una posición recibida como parámetro. */

#include <stdio.h>
#include <stdlib.h>

typedef char st30[31];
typedef struct{
    st30 apellido, nombre, nacionalidad;
    float puntaje;
}TTenista;

int main()
{
    int n;
    cargarArch();
    return 0;
}

void cargarArch(){
    TTenista tenista;
    FILE *archb, *archt;
    archt = fopen("ranking.txt", "rt");
    if(archt != NULL){
        archb = fopen("ranking.dat", "wb");
        if(archb != NULL){
            while(fscanf(archt, "%s %s %s %f", tenista.apellido, tenista.nombre, tenista.nacionalidad, &tenista.puntaje) == 4)
                fwrite(&tenista, sizeof(tenista), 1, archb);
            fclose(archt);
            fclose(archb);
        }
        else
            fclose(archt);
    }
}

void escribirTenista(unsigned int n){
    FILE *archb;
    TTenista tenista;
    int i = 0;
    archb = fopen("ranking.dat", "rb");
    if(archb != NULL){
        while(fread(tenista, sizeof(tenista), 1, archb) && i <= n)
    }
}
