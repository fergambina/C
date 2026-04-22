#define MAX 30 //Dimension del nombre

typedef char TElementoP[MAX];

typedef struct nodop{
 TElementoP dato;
 struct nodop *sig;
}nodop;
typedef nodop *TPila;

void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP x);
//TElementoP consultaP(TPila P);
int vaciaP(TPila P);
void iniciaP(TPila *P);
