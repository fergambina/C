/*Corregir los errores en el siguiente programa, el cual incorpora en una lista ordenada de
números los elementos de un arreglo de N números ordenados, respetando el orden de la lista.*/
#define N 4
...
void main(){
  int i, arr[N] = {4,8,9,60};
  TLISTA lista=NULL, act, ant, nuevo;
  ...
  cargarLista(&lista);
  printf("\nLista Original\n");
  muestra(lista);
  act = lista;
  ant = NULL;
  for(i=0; i < N; i++){
      nuevo = (TLISTA) malloc(sizeof(NODO));
      nuevo->n = arr[i];
      while(act!=NULL && nuevo->n > act->n) {
          ant = act;
          act = act->sig;
      }
      if(ant == NULL) {
         nuevo->sig = lista;
         lista = nuevo;
      }
      else {
        nuevo->sig = act;
        ant->sig = nuevo;
      }
      ant = nuevo;
  }
  printf("\nLista Resultado\n");
  muestra(lista);
}

void main(){
  int i, arr[N] = {4,8,9,60};
  TLISTA lista=NULL, act, ant, nuevo;
  ...
  cargarLista(&lista, arr);
  printf("\nLista Original\n");
  muestra(lista);
  for(i=0; i < N; i++) {
      nuevo = (TLISTA) malloc(sizeof(NODO));
      nuevo->n = arr[i];
      if(nuevo->n < lista->n){
        nuevo->sig = lista;
        lista = nuevo;
      }
      else{
        act = lista;
        while(act != NULL && nuevo->n > act->n){
            ant = act;
            act = act->sig;
        }
        nuevo->sig = act;
        ant->sig = nuevo;
      }
  }
  printf("\nLista Resultado\n");
  muestra(lista);
}

