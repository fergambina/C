/* Desarrollar un subprograma que reciba una cantidad de segundos y devuelva su equivalente en
el formato horas:minutos:segundos */

#include <stdio.h>
#include <stdlib.h>

void devuelvehms(unsigned int totalSeg, unsigned int *hora, unsigned int *min, unsigned int *seg);

int main()
{
    unsigned int totalSeg, hora, min, seg;
    printf("Ingrese segundos: ");
    scanf("%u", &totalSeg);
    devuelvehms(totalSeg, &hora, &min, &seg);
    printf("%u: %u: %u", hora, min, seg);
    return 0;
}

void devuelvehms(unsigned int totalSeg, unsigned int *hora, unsigned int *min, unsigned int *seg){
    unsigned int segRes;
    *hora = totalSeg / 3600;
    segRes = totalSeg % 3600;
    *min = segRes / 60;
    *seg = segRes % 60;
}
