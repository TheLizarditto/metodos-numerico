#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x;
}

// N debe ser par

const int p = 11; // cantidad de puntos a emplear
const int n = p-1; // cantidad de subintervalos a emplear // debe ser un nro par

int main(int argc, char *argv[])
{
    // tabla de datos EQUIESPACIADA
    double x[p] = {1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2};
    double y[p] = {-1.41, -1.496075, -1.62917, -1.67311, -1.62083, -1.47943, -1.26, -0.965395, -0.565015, -0.14099, 0.05003};
    
    double I = 0; // integral aproximada

    // auxiliares
    double h = (double) (x[1] - x[0]); // asume que la tabla esta equiespaciada
    double suma_impares = 0, suma_pares = 0; 

    // calculo de I
    for(int i = 1; i <= (n-1); i++){ // i impares
        if(i % 2 == 1){
            suma_impares += y[i];
        }
    }
    for(int i = 2; i <= (n-2); i++){ // i pares
        if(i % 2 == 0){
            suma_pares += y[i];
        }
    }
    I = (double) h/3 * (y[0] + y[n] + 4 * suma_impares + 2 * suma_pares);

    // impresion de resultados
    printf("Valor aproximado de la integral de f(x): I = %d", I);

    return 0;
}