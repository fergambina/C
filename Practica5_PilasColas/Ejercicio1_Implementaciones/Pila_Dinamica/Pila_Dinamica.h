typedef int TElementoP;
typedef struct nodop{
    TElementoP dato;
    struct nodop *sig;
}nodop;
typedef struct nodop *TPila;

void iniciaP(TPila *P);
int vaciaP(TPila P);
TElementoP consultaP(TPila P);
void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP *x);
