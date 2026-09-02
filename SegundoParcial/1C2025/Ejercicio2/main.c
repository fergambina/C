#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

int determina(arbolN a, posicion p, int nivel, int K){
    posicion c;
    int cumple = 1;
    int gr = 0;
    int acumClaves = 0;

    if(!nulo(p) && !nulo(hijoMasIzq(p,a)) && nivel < K){
        c = hijoMasIzq(p, a);

        if(info(p, a) <= 0){
            while(!nulo(c) && cumple){
                cumple = determina(a, c, nivel + 1, K);
                c = hermanoDer(c, a);
            }
            return cumple;
        }
        else{
            while(!nulo(c) && cumple){
                gr++;
                cumple = determina(a, c, nivel + 1, K);
                acumClaves += info(c, a);
                c = hermanoDer(c, a);
            }

            if(gr % 2 == 0){
                if((float)acumClaves / gr >= 2 * info(p, a))
                    return 1;
                else
                    return 0;
            }
            else
                return 1;
        }
    }

    return cumple;
}
