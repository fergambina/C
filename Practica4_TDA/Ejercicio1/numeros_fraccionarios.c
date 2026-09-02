#include "numeros_fraccionarios.h"

fraccion crear(int numerador, int denominador){
    fraccion nueva_fraccion;
    if(denominador != 0){
        nueva_fraccion.numerador = numerador;
        nueva_fraccion.denominador = denominador;
    }
    else{
        nueva_fraccion.numerador = 0;
        nueva_fraccion.denominador = 1;
    }
    return nueva_fraccion;
}

int numerador(fraccion f1){
    return f1.numerador;
}

int denominador(fraccion f1){
    return f1.denominador;
}

fraccion sumar(fraccion f1, fraccion f2){
    fraccion res;
    res.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    res.denominador = f1.denominador * f2.denominador;
    return res;
}

fraccion restar(fraccion f1, fraccion f2){
    fraccion res;
    res.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
    res.denominador = f1.denominador * f2.denominador;
    return res;
}

fraccion multiplicar(fraccion f1, fraccion f2){
    fraccion res;
    res.numerador = f1.numerador * f2.numerador;
    res.denominador = f1.denominador * f2.denominador;
    return res;
}


fraccion dividir(fraccion f1, fraccion f2){
    fraccion res;
    res.numerador = f1.numerador * f2.denominador;
    res.denominador = f1.denominador * f2.numerador;
    return res;
}




