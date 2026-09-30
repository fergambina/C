#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
#define CANT_LETRAS 26

typedef struct nodoS{
    char titulo[MAX], autor[MAX];
    unsigned int anio_edicion;
    struct nodoS *sig;
}nodoS;
typedef nodoS *Sublista;

typedef struct nodo{
    char autor[MAX];
    Sublista sub;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

typedef struct nodoLP{
    char titulo[MAX], autor[MAX];
    unsigned int anio_edicion;
    struct nodoLP *sig;
}nodoLP;
typedef nodoLP *SublistaLP;

typedef struct nodoSocios{
    char socio[MAX];
    SublistaLP subLibrosPrestados;
}nodoSoci;
typedef nodoSocios *TListaSocios;

void iniciaListaAutores(TLista biblioteca[]){
    int i;
    for(i = 0; i < CANT_LETRAS; i++)
        biblioteca[i] = NULL;

}

void cargaAutores(TLista biblioteca[]){
    FILE *arch;
    int indice_letra;
    char autor[MAX];
    TLista nuevo;
    arch = fopen("autores.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%s", autor) == 1){
            nuevo = (TLista)malloc(sizeof(nodo));
            strcpy(nuevo->autor, autor);
            nuevo->sub = NULL;
            indice_letra = toupper(autor[0]) - 'A';
            nuevo->sig = biblioteca[indice_letra];
            biblioteca[indice_letra] = nuevo;
        }
    }
}

void cargaLibros(TLista biblioteca[]){
    FILE *arch;
    char titulo[MAX], autor[MAX];
    unsigned int anio_edicion, indice_letra;
    Sublista antS, actS, nuevoS;
    TLista aux;
    arch = fopen("libros.TXT", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%49[^;];%49[^;];%d", titulo, autor, &anio_edicion) == 3){
            indice_letra = toupper(autor[0]) - 'A';
            aux = biblioteca[indice_letra];
            while(strcmp(aux->autor, autor) != 0) //Al cargar el libro asumo que el autor existe en la lista correspondiente.
                aux = aux->sig;
            nuevoS = (Sublista)malloc(sizeof(nodoS));
            strcpy(nuevoS->titulo, titulo);
            strcpy(nuevoS->autor, autor);
            nuevoS->anio_edicion = anio_edicion;
            if(aux->sub == NULL || strcmp(aux->sub->titulo, titulo) > 0){
                nuevoS->sig = aux->sub;
                aux->sub = nuevoS;
            }
            else{
                actS = aux->sub;
                while(actS != NULL && strcmp(actS->titulo, titulo) < 0){
                    antS = actS;
                    actS = actS->sig;
                }
                nuevoS->sig = actS;
                antS->sig = nuevoS;
            }
        }
        fclose(arch);
    }
}

/*Busco el autor del libro en la lista correspondiente. Una vez encontrado recorro la sublista de libros del autor
buscando el libro. Una vez hecho eso recorro la lista de socios buscando el socio y luego hago los enlaces.
*/


void prestamo(TLista biblioteca[], TListaSocios socios, char socio[], char autor[], char titulo[], unsigned int anio_edicion){
    TLista actA;
    Sublista antS, actS;
    TListaSocios actSocios;
    SublistaLP actLP;


}

void mostrarBiblioteca(TLista biblioteca[]) {
    TLista auxAutor;
    Sublista auxLibro;
    int i, hayAlgo;

    hayAlgo = 0;
    printf("\n================== BIBLIOTECA ==================\n");

    for (i = 0; i < 26; i++) {
        if (biblioteca[i] != NULL) {
            hayAlgo = 1;
            printf("\n[ %c ]\n", 'A' + i);
            printf("------------------------------------------------\n");

            auxAutor = biblioteca[i];
            while (auxAutor != NULL) {
                printf("  Autor: %s\n", auxAutor->autor);

                auxLibro = auxAutor->sub;
                if (auxLibro == NULL) {
                    printf("    (Sin libros registrados)\n");
                } else {
                    printf("    %-35s %s\n", "Titulo", "Anio");
                    printf("    %-35s %s\n", "-----------------------------------", "----");
                    while (auxLibro != NULL) {
                        printf("    %-35s %u\n", auxLibro->titulo, auxLibro->anio_edicion);
                        auxLibro = auxLibro->sig;
                    }
                }
                printf("\n");
                auxAutor = auxAutor->sig;
            }
        }
    }

    if (hayAlgo == 0) {
        printf("\n  La biblioteca esta vacia.\n\n");
    }
    printf("================================================\n");
}

void insertaLibro(TLista biblioteca[], char titulo[], char autor[], unsigned int anio_edicion){
    TLista actA, antA, nuevoA;
    Sublista antS, actS, nuevoS;
    int indice_letra;
    nuevoS = (Sublista)malloc(sizeof(nodoS));
    strcpy(nuevoS->titulo, titulo);
    strcpy(nuevoS->autor, autor);
    nuevoS->anio_edicion = anio_edicion;
    indice_letra = toupper(autor[0]) - 'A';
    actA = biblioteca[indice_letra];
    antA = NULL;
    while(actA != NULL && strcmp(actA->autor, autor) != 0){
        antA = actA;
        actA = actA->sig;
    }
    if(actA != NULL){  //Existe el autor.
        antS = NULL;
        actS = actA->sub;
        while(actS != NULL && strcmp(titulo, actS->titulo) < 0){
            antS = actS;
            actS = actS->sig;
        }
        if(actS == actA->sub){
            nuevoS->sig = actA->sub;
            actA->sub = nuevoS;
        }
        else{
            antS->sig = nuevoS;
            nuevoS->sig = actS;
        }
    }
    else{
        nuevoA = (TLista)malloc(sizeof(nodo));
        strcpy(nuevoA->autor, autor);
        if(antA == NULL){
            nuevoA->sig = NULL;
            biblioteca[indice_letra] = nuevoA;
        }
        else{
            antA->sig = nuevoA;
            nuevoA->sig = NULL;
        }
        nuevoS->sig = NULL;
        nuevoA->sub = nuevoS;
    }
}

int main()
{
    TLista biblioteca[CANT_LETRAS]; //Arreglo de listas simplemente enlazadas.
    iniciaListaAutores(biblioteca); //Pone NULL en el puntero de cada lista.
    cargaAutores(biblioteca); //Carga autores inicialmente.
    cargaLibros(biblioteca);
    mostrarBiblioteca(biblioteca);
    insertaLibro(biblioteca, "Hola", "Roberto", 2001);
    insertaLibro(biblioteca, "Ab", "Dumas", 2001);
    mostrarBiblioteca(biblioteca);
    return 0;
}
