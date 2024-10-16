#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x;
}

#define N 3

int main(int argc, char *argv[]) {
    double res;
    int sel;
    double x[N];
    double h;
    int valor;

    switch (sel) {
    case 1: // adelante
        res = (f(x[valor + 1]) - f(x[valor])) / h;
        break;
    
    case 2: // atras
        res = (f(x[valor]) - f(x[valor - 1])) / h;
        break;

    case 3: // centrado
        res = (f(x[valor + 1]) - f(x[valor - 1])) / (2 * h);
        break;

    case 4: // doble adelante
        res = (4 * f(x[valor + 1]) - f(x[valor + 2]) - 3 * f(x[valor])) / (2 * h);
        break;

    default:
        printf("Elegir del 1 al 4");
        return 0;
    }

    printf("El resultado es: %lf", res);

    return 0;
}