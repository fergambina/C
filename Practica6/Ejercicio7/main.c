/*Implementar un programa de biblioteca que administre la siguiente estructura: un arreglo de
listas simples ordenadas alfabéticamente con los autores que comiencen con la misma letra, o
sea que habrá un elemento del arreglo por cada letra del abecedario, aunque no existan
autores que comiencen con dicha letra.  Para cada autor existe una sublista, ordenada por
título, con los libros disponibles para ser prestados de cada autor:
• Autor
• Sublista de libros de dicho autor
o Titulo
o Autor
o Año de edición
Se debe poder agregar libros a esta estructura.
Además, gestionar una lista de socios con una sublista de libros prestados. Permitir las
operaciones de registrar préstamos (mover el nodo de la sublista del autor al final de la sublista
de libros prestados para el socio) y devoluciones (mover nodo del libro prestado de dicha
sublista a la sublista del autor de acuerdo al orden indicado). Dicha lista posee la siguiente
estructura:
• Socio
• Sublista de libros prestados
o Titulo
o Autor
o Año de edición */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CANT_LETRAS 27
#define DIM 50

typedef struct nodoLibros{
    char titulo[DIM], autor[DIM];
    int edicion;
    struct nodoLibros *sig;
} nodoLibros;
typedef nodoLibros *SublistaLibros;

typedef struct nodo{
    char autor[DIM];
    SublistaLibros sub;
    struct nodo *sig;
} nodo;
typedef nodo *TListaAutores;

typedef struct nodoS{
    char nombre[DIM];
    SublistaLibros subLibrosPrestados;
    struct nodoS *sig;
}nodoS;
typedef nodoS *TListaSocios;

void iniciaAutores(TListaAutores vectorAutores[]);
void cargarAutores(TListaAutores vectorAutores[]);
void insertarAutor(TListaAutores *listaAutores, char nombreAutor[]);
void insertarLibros(TListaAutores vectorAutores[]);
void agregarLibro(TListaAutores vectorAutores[], char titulo[], char autor[], int edicion);
void insertarLibroOrdenado(SublistaLibros *sublista, char titulo[], char autor[], int edicion);
void prestamo(TListaAutores vectorAutores[], TListaSocios vectorSocios[], char autor[], char titulo[], char nombreSocio[]);


int main(){
    TListaAutores vectorAutores[CANT_LETRAS];
    TListaSocios vectorSocios[DIM];
    iniciaAutores(vectorAutores);
    cargarAutores(vectorAutores);
    insertarLibros(vectorAutores);

    return 0;
}

void prestamo(TListaAutores vectorAutores[], TListaSocios vectorSocios[], char autor[], char titulo[], char nombreSocio[]){
    TListaAutores aux;
    TListaSocios auxS;
    SublistaLibros ant, act, libro, actLibroPres;
    int indiceLetra;
    indiceLetra = toupper(autor[0]) - 'A';
    aux = vectorAutores[indiceLetra];
    while (aux != NULL && strcmp(aux->autor, autor) != 0) //Busco el autor del libro solicitado
        aux = aux->sig;
    if(aux != NULL){ //Encontre el autor del libro solicidado
        ant = NULL;
        act = aux->sub;
        while (act != NULL && strcmp(act->titulo, titulo) < 0){  //Busco el libro solicitado en la sublista
            ant = act;
            act = act->sig;
        }
        if(act != NULL && strcmp(act->titulo, titulo) == 0){
            auxS = buscarSocio(vectorSocios, nombreSocio);  //Busco el socio que solicito el libro
            libro = act;
            if(ant == NULL) //Saco el primero de la sublista de autores
                aux->sub = libro->sig;
            else
                ant->sig = libro->sig;
            libro->sig = NULL;
            if(auxS->subLibrosPrestados == NULL)
                auxS->subLibrosPrestados = libro;
            else{
                actLibroPres = auxS->subLibrosPrestados;
                while(actLibroPres->sig != NULL)
                    actLibroPres = actLibroPres->sig;
                actLibroPres->sig = libro;
            }
        }
    }
}

void insertarLibroOrdenado(SublistaLibros *sublista, char titulo[], char autor[], int edicion){
    SublistaLibros nuevo, ant, act;
    nuevo = (SublistaLibros)malloc(sizeof(nodoLibros));
    strcpy(nuevo->titulo, titulo);
    strcpy(nuevo->autor, autor);
    nuevo->edicion = edicion;
    if((*sublista == NULL) || strcmp((*sublista)->titulo, titulo) > 0){
        nuevo->sig = *sublista;
        *sublista = nuevo;
    }
    else{
        ant = NULL;
        act = *sublista;
        while(act != NULL && strcmp(act->titulo, titulo) < 0){
            ant = act;
            act = act->sig;
        }
        nuevo->sig = act;
        ant->sig = nuevo;
    }
}

void agregarLibro(TListaAutores vectorAutores[], char titulo[], char autor[], int edicion){
    int indiceLetra;
    TListaAutores aux;
    indiceLetra = toupper(autor[0]) - 'A';
    aux = vectorAutores[indiceLetra];
    while(aux != NULL && strcmp(aux->autor, autor) != 0)
        aux = aux->sig;
    if(aux != NULL){
        insertarLibroOrdenado(&aux->sub, titulo, autor, edicion);
    }

}

void insertarLibros(TListaAutores vectorAutores[]){
    FILE *arch;
    char titulo[DIM], autor[DIM];
    int edicion;
    arch = fopen("libros.txt", "rt");
    if(arch != NULL){
        while(fscanf(arch, "%49[^;];%49[^;];%d", titulo, autor, &edicion) == 3)
            agregarLibro(vectorAutores, titulo, autor, edicion);
    }

}

void insertarAutor(TListaAutores *listaAutores, char nombreAutor[]){
    TListaAutores nuevoAutor;
    nuevoAutor = (TListaAutores)malloc(sizeof(nodo));
    strcpy(nuevoAutor->autor, nombreAutor);
    nuevoAutor->sub = NULL;
    nuevoAutor->sig = *listaAutores;
    *listaAutores = nuevoAutor;
}
void cargarAutores(TListaAutores vectorAutores[]){
    FILE *archivo;
    int indiceLetra;
    char nombreAutor[DIM];
    archivo = fopen("autores.txt", "rt");
    if(archivo != NULL){
        while(fscanf(archivo, "%s", nombreAutor) == 1){
            indiceLetra = toupper(nombreAutor[0]) - 'A';
            insertarAutor(&vectorAutores[indiceLetra], nombreAutor);
        }
        fclose(archivo);
    }
}

void iniciaAutores(TListaAutores vectorAutores[]){
    int i;

    for(i = 0; i < CANT_LETRAS; i++){
        vectorAutores[i] = NULL;
    }
}
