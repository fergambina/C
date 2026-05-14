#define MAX 5

typedef float TElementoC;
typedef struct {
    TElementoC datos[MAX];
    int pri, ult;
}TCola;

void iniciaC (TCola *C);
int vaciaC(TCola C);
void poneC (TCola *C, TElementoC X);
void sacaC (TCola *C, TElementoC *X);
TElementoC consultaC (TCola C);

