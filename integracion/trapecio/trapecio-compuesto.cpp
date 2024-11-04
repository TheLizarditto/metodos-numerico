#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x;
}

double fp(double x) {
    return 1;
}

int main(int argc, char *argv[]) {
    // límites de integración
    double a = 5;
    double b = 8;
    int n = 3;
    double x = 0;
    double h = (b - a)/n;
    double suma = f(a) + f(b);

    for(int i = 1; i < n; i++) {
        x = a + i * h;
        suma += 2 * f(x);
    }
    suma *= h/2;
    printf("El resultado es: %lf", suma);

    double error = ((-1/12 * pow(b - a, 2)) / pow(n, 2)) * (fp(b) - fp(a));
    printf("\nEl error es: %lf", error);

    return 0;
}