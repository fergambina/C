#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

//Dado un árbol binario proveniente de la conversión de un árbol general:

//a) hallar la cantidad de nodos que habia en niveles impares.
int cantNodosNivImpares(arbol a, int nivelAct){  //Invocacion: cantNodosNivImpares(a, 1);
    if(a == NULL)
        return 0;
    else{
        if(nivelAct % 2 != 0)
            return 1 + cantNodosNivImpares(a->izq, nivelAct + 1) + cantNodosNivImpares(a->der, nivelAct);
        else
            return cantNodosNivImpares(a->izq, nivelAct + 1) + cantNodosNivImpares(a->der, nivelAct);
    }
}

//b) obtener el promedio de las claves cuyo grado era K (dato de entrada).
void promedio(arbol a, int K, int *cant, int *sum){
    int grado;
    arbol hijoAct;
    if(a != NULL){
        grado = 0;
        hijoAct = a->izq;
        while(hijoAct != NULL){
            grado++;
            promedio(hijoAct, K, cant, sum);
            hijoAct = hijoAct->der;
        }
        if(grado == K){
            (*cant)++;
            (*sum) += a->dato;
        }
    }
}

//c) obtener la altura del árbol original
int altura(arbol a){
}

//d) determinar el grado del árbol original.
int gradoArbol(arbol a){
    int grado, gradoSubarbol, maxGrado = 0;
    arbol aux;
    if(a == NULL)
        return 0;
    else{
        grado = 0;
        aux = a->izq;
        while(aux != NULL){
            grado++;
            gradoSubarbol = gradoArbol(aux);
            if(gradoSubarbol > maxGrado)
                maxGrado = gradoSubarbol;
            aux = aux->der;
        }
        if(grado > maxGrado)
            return grado;
        else
            return maxGrado;
    }
}
