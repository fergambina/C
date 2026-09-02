typedef struct{
    int numerador, denominador;
}fraccion;

fraccion crear(int numerador, int denominador);
int numerador(fraccion f1);
int denominador(fraccion f1);
fraccion sumar(fraccion f1, fraccion f2);
fraccion restar(fraccion f1, fraccion f2);
fraccion multiplicar(fraccion f1, fraccion f2);
fraccion dividir(fraccion f1, fraccion f2);
fraccion simplificar(fraccion f1);
int iguales(fraccion f1, fraccion f1);
