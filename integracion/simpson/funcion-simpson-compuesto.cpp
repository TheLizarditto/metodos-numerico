#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x;
}

double fpppp(double x) {
    return 0;
}

int main(int argc, char *argv[]) {
    // límites de integración
    double a = 5;
    double b = 8;
    double n; // DEBE SER PAR!!!
    double h = (b - a) / n;
    double x;
    double suma = 0;

    for(int i = 1; i < n - 1; i++) {
        x = a + 2 * i * h;
        suma += 2 * f(x) + 4 * f(x - h);
    }

    suma = h/3 * (f(a) + f(b) + suma);
    printf("El resultado es: %lf", suma);

    double error = ( (-1 * pow((b - a), 5)) / (180 * pow(n, 4)) ) * fpppp(); // preguntar que va en fpppp()

    return 0;
}