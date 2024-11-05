#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x;
}

#define N 11 // cantidad de elementos

int main(int argc, char *argv[]) {
    double res[N];
    double x[N]= {0.098, -0.043, -0.201215, -0.368834, -0.535837, -0.693, -0.831723, -0.945, -1.024802, -1.058003, -1.053};
    double h = 0.1;

    /*
    printf("Ingrese los datos: \n");

    for (int i = 0; i < N; i++) {
        printf("Ingrese el dato %d: ", i + 1);
        scanf("%lf", &x[i]);
    }
    */
    
    // adelante para el primero
    res[0] = (f(x[1]) - f(x[0])) / h;
    
    // centrado para el resto
    for (int i = 1; i < N - 1; i++) {
        res[i] = (f(x[i + 1]) - f(x[i - 1])) / (2 * h);
    }
    
    // atras para el ultimo
    res[N - 1] = (f(x[N - 1]) - f(x[N - 2])) / h;
    
    // adelante
    // res = (f(x[i + 1]) - f(x[i])) / h;
    
    // atras
    // res = (f(x[i]) - f(x[i - 1])) / h;

    // centrado
    // res = (f(x[i + 1]) - f(x[i - 1])) / (2 * h);

    // doble adelante
    // res = (4 * f(x[i + 1]) - f(x[i + 2]) - 3 * f(x[i])) / (2 * h);
    
    for(int i = 0; i < N; i++) {
        printf("El resultado de %d es: %lf \n", i + 1, res[i]);
    }

    return 0;
}