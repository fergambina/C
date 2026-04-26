/*Corregir los errores en el siguiente programa, el cual incorpora en una lista ordenada de
números los elementos de un arreglo de N números ordenados, respetando el orden de la lista.*/
#define N 4
...
void main(){
  int i, arr[N] = {4,8,9,60};
  TLISTA lista=NULL, act, ant, nuevo;
  ...
  cargarLista(&lista, arr);
  printf("\nLista Original\n");
  muestra(lista);
  act = lista;
  ant = NULL;
  for(i=0; i < N; i++) {
      while(act!=NULL && arr[i] >= act->n) {
          ant = act;
          act = act->sig;
      }
      nuevo = (TLISTA) malloc(sizeof(NODO));
      nuevo->n = arr[i];
      if(ant == NULL) {
         nuevo->sig = lista;
         lista = nuevo;
      }
      else {
        nuevo->sig = act;
        ant->sig = nuevo;
      }
  }
  printf("\nLista Resultado\n");
  muestra(lista);
}
