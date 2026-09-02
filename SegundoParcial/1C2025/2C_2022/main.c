#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}



int verifica(arbol A, int posicion p){
    int cumple = 0;
    if(!nulo(p)){
        if(!nulo(hijoMasIzq(p, A)) && esVocal(info(p, A))){
            c = hijoMasIzq(p, A);
            gr = 0;
            todosVoc = 1;
            while(!nulo(C) && ! cumple){
                gr++;
                if(!esVocal(info(c, A)))
                    todosVoc = 0;
                cumple = verifica(A, c);
                c = hermanoDer(c, A);
            }
            return (gr % 2 == 0 && todosVoc) || cumple;
        }
        else
            return 0;
    }
    else
        return 0;
}
