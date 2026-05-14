/* Corregir los errores de la siguiente función, que elimina el nodo de una lista circular que
contiene un valor pasado como parámetro (elem)
void lc_eliminaelem(TLISTAC *pult, TELEMENTOLC elem, int *eliminado) {
    TLISTAC ant, act = *pult->sig;
    eliminado = 0;
    if (pult = NULL) {
        do{
           ant = act;
           act->sig = act;
        }while ( *pult != act && elem < act.dato);
        if (elem = act->dato){
           if (*pult != (*pult)->sig)
              *pult= NULL;
           else {
                act->sig = ant->sig;
                if (act == *pult)
                  pult = *ant;
           }
           free (ant);
           eliminado = 1;
        }
    }
} */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

//Correccion del codigo
void ll_elimnaelem(TLista *pult, TElemento elem){
    TLista ant, act;
    if (*pult != NULL){
        ant = *pult;
        act = (*pult)->sig;
        while (act != *pult && elem > act->dato){
            ant = act;
            act = act->sig;
        }
        if (elem == act->dato){
            if (act == *pult){
                ant->sig = act->sig;
                *pult = ant;
            }
            else
                ant->sig = act->sig;
            free(act);
        }
    }
}
