typedef struct{
    long unsigned int legajo;
    unsigned int momento_arribo;
    unsigned int duracion_uso;
}TElementoC;

typedef struct nodo {
  TElementoC dato;
  struct nodo * sig;} nodo;

typedef struct {
 nodo *pri, *ult;} TCola;

void iniciaC (TCola *C);
int vaciaC(TCola C);
void sacaC (TCola *C, TElementoC *X);
void poneC (TCola *C, TElementoC X);
TElementoC consultaC (TCola C);
TElementoC crearEmpleado(long unsigned int legajo, unsigned int momento_arribo, unsigned int duracion_uso);
long unsigned int obtenerLegajo(TElementoC empleado);
unsigned int obtenerMomentoArribo(TElementoC empleado);
unsigned int obtenerDuracionUso(TElementoC empleado);
