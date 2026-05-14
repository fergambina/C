#define MAX 50

typedef int TElementoP;
typedef struct{
    TElementoP datos[MAX];
    int tope;
}TPila;

void iniciaP(TPila *P);
int vaciaP(TPila P);
TElementoP consultaP(TPila P);
void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP *x);
