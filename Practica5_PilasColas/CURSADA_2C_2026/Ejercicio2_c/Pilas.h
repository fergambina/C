#define MAX 50

typedef char TElementoP;

typedef struct {
 TElementoP datos[MAX];
 int tope; } TPila;

void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP* x);
TElementoP consultaP(TPila P);
int vaciaP(TPila P);
void iniciaP (TPila *P);
