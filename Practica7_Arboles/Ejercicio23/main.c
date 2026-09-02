#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

//Dado un árbol N-ario de enteros, desarrollar funciones utilizando TDA N.ARIO para:

//a) retornar la cantidad de nodos que posee.
int cantNodos(arbolN A, posicion p){
    posicion c;
    int cont;
    if(!nulo(p)){
        cont = 0;
        c = hijoMasIzq(p , A);
        while(!nulo(c)){
            cont = cont + cantNodos(A, c);
            c = hermanoDer(c, A);
        }
        return cont + 1;
    }
    else
        return 0;
}

//b) hallar el porcentaje de claves pares
void clavesPares(arbolN A, posicion p, int *contNodos, int *contPares){
    posicion c;
    if(!nulo(p)){
        (*contNodos) += 1;
        if(info(p, A) % 2 == 0)
            (*contPares) += 1;
        c = hijoMasIzq(p, A);
        while(!nulo(c)){
            clavesPares(A, c, contNodos, contPares);
            c = hermanoDer(c, A);
        }
    }
}

//c) retornar su grado.
int grado(arbolN A, posicion p){
    int grado, gradoSubarbol, maxGrado = 0;
    posicion c;
    if(!nulo(p)){
        grado = 0;
        c = hijoMasIzq(p, A);
        while(!nulo(c)){
            grado++;
            gradoSubarbol = grado(A, c);
            if(gradoSubarbol > maxGrado)
                maxGrado = gradoSubarbol;
            c = hermanoDer(c, A);
        }
        if(grado > maxGrado)
            return grado;
        else
            return maxGrado;
    }
    else
        return 0;
}

//d) hallar la cantidad de nodos de grado impar que hay en niveles impares.
int cantNodosGradoImparNivImpares(arbolN A, posicion p, int nivelAct){
    int grado, cont = 0;
    posicion c;
    if(!nulo(p)){
        grado = 0;
        c = hijoMasIzq(p, A);
        while(!nulo(c)){
            grado++;
            cont += cantNodosGradoImparNivImpares(A, c, nivelAct + 1);
            c = hermanoDer(c, A);
        }
        if(nivelAct % 2 != 0 && grado % 2 != 0)
            return cont + 1;
        else
            return cont;
    }
    else
        return 0;
}

//e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual
//a la cantidad de hijos. (función int y función void)

//void
void clavesCumplen(arbolN A, posicion p, int *cumple){
    int cantHijos;
    posicion c;
    if(!nulo(p) && *cumple){
        if(!nulo(hijoMasIzq(p, A))){
            cantHijos = 0;
            c = hijoMasIzq(p, A);
            while(!nulo(c) && *cumple){
                cantHijos++;
                clavesCumplen(A, c, cumple);
                c = hermanoDer(c, A);
            }
            if(cantHijos != info(p, A))
                *cumple = 0;
        }
    }
}
