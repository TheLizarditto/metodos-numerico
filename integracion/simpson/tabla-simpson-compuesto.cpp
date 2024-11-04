#include <iostream>
#include <cmath>
using namespace std;

#define N 2 // DEBE SER PAR!!!

int main(int argc, char *argv[]) {
    // límites de integración
    double x[N] = {1, 2};
    double y[N] = {3, 5};
    double h = (x[N - 1] - x[0]) / N;
    double suma = 0;

    for(int i = 2; i < N - 1; i+2) {
        suma += 2 * y[i] + 4 * y[i - 1];
    }

    suma = h/3 * (y[0] + y[N - 1] + suma);
    printf("El resultado es: %lf", suma);

    return 0;
}