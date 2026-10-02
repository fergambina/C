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
    struct nodoSocios *sig;
}nodoSocios;
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
    nuevoS = (Sublista)malloc(sizeof(nodoS));  //Creacion del nodo de la sublista de libros.
    strcpy(nuevoS->titulo, titulo);
    strcpy(nuevoS->autor, autor);
    nuevoS->anio_edicion = anio_edicion;
    indice_letra = toupper(autor[0]) - 'A';
    actA = biblioteca[indice_letra];  //Me posiciono en la lista correspondiente.
    antA = NULL;
    while(actA != NULL && strcmp(actA->autor, autor) != 0){  //Busco el autor del libro a ingresar.
        antA = actA;
        actA = actA->sig;
    }
    if(actA != NULL){  //Existe el autor. Inserto el libro en la sublista.
        antS = NULL;
        actS = actA->sub;
        while(actS != NULL && strcmp(titulo, actS->titulo) > 0){  //Busqueda de la posicion a insertar.
            antS = actS;
            actS = actS->sig;
        }
        if(actS == actA->sub){ //Inserto en la cabeza de la sublista de libros.
            nuevoS->sig = actA->sub;
            actA->sub = nuevoS;
        }
        else{
            antS->sig = nuevoS;
            nuevoS->sig = actS;
        }
    }
    else{ //El autor no existe.
        nuevoA = (TLista)malloc(sizeof(nodo));  //Creo un autor.
        strcpy(nuevoA->autor, autor);
        if(antA == NULL){  //Modifico la cabeza de la lista de autores.
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

//registrar préstamos (mover el nodo de la sublista del autor al final de la sublista de libros prestados para el socio)
void prestamo(TLista biblioteca[], TListaS *LS, char autor[], char socio[], char titulo[], int edicion) {
    TLista actA;
    TSublista antS, actS, actLP, antLP;
    TListaS actSocio, antSocio, nuevoSocio;
    int indice_letra = toupper(autor[0] - 'A';
    actA = biblioteca[indice_letra];
    while (actA != NULL && strcmp(actA->autor, autor) != 0) {
        actA = actA->sig;
    }
    if (actA != NULL) {                 // existe el autor
        antS = NULL;
        actS = actA->sub;
        while (actS != NULL && strcmp(actS->titulo, titulo) < 0 ||
               strcmp(actS->titulo, titulo) == 0 && edicion != actS->edicion) {
            antS = actS;
            actS = actS->sig;
        }
        if (actS != NULL && strcmp(actS->titulo, titulo) == 0) {   // libro encontrado
            antS->sig = actS->sig;
            actS->sig = NULL;
            antSocio = NULL;
            actSocio = *LS;
            while (actSocio != NULL && strcmp(actSocio->socio, socio) != 0) {
                antSocio = actSocio;
                actSocio = actSocio->sig;
            }
            if (actSocio != NULL) {
                antLP = NULL;           // ¿Es necesario ant en la lista?
                actLP = actSocio->subLP;
                while (actLP != NULL) {
                    antLP = actLP;
                    actLP = actLP->sig;
                }
                if (antLP == NULL)
                    actSocio->subLP = actS;
                else
                    antLP->sig = actS;
            }
            else {                      // Inserto socio
                nuevoSocio = (TListaS) malloc(sizeof(nodoSocio));
                strcpy(nuevoSocio->socio, socio);
                nuevoSocio->sig = NULL;
                nuevoSocio->subLP = actS;
                if (antSocio == NULL)
                    *LS = nuevoSocio;
                else
                    antSocio->sig = nuevoSocio;
            }
        }
    }
}

// Registrar devoluciones (mover el nodo del libro prestado de la sublista
// del socio a la sublista del autor, de forma ordenada)
void devoluciones(TLista biblioteca[], TListaS LS, char nom[], char autor[], char libro[], int edicion) {
    int indice_letra = toupper(autor[0]) - 'A';
    TListaS actSoc;
    Nodo antLP, actLP, antS, actS;
    TLista actA;
    actSoc = LS;
    while (actSoc != NULL && strcmp(actSoc->nom, nom) != 0)   // búsqueda del socio
        actSoc = actSoc->sig;
    if (actSoc != NULL){
        antLP = NULL;
        actLP = actSoc->sublP;
        while (actLP != NULL && !(strcmp(actLP->titulo, titulo) == 0 && strcmp(actLP->autor, autor) == 0 && actLP->edicion == edicion)){  // búsqueda del libro en sublista de socio
            antLP = actLP;
            actLP = actLP->sig;
        }

        if (actLP != NULL){
            if (actLP == actSoc->sublP)
                actSoc->sublP = actLP->sig;
            else
                antLP->sig = actLP->sig;
            actA = biblioteca[indice_letra];
            while (strcmp(actA->autor, autor) != 0)
                actA = actA->sig;
            antS = NULL;
            actS = actA->sub;
            while (actS != NULL && strcmp(actS->titulo, titulo) < 0) {  // búsqueda del autor y de la posición a insertar
                antS = actS;
                actS = actS->sig;
            }
            if (actS == actA->sub){
                actA->sub = actLP;
                actLP->sig = actS;
            }
            else{
                actLP->sig = actS;
                antS->sig = actLP;
            }
        }
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
