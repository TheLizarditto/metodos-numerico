#include <iostream>
using namespace std;

#define N 11 // cantidad de datos

int main(int argc, char *argv[]) {
    double x[N] = {1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2};
    double y[N] = {-1.41, -1.496075, -1.62917, -1.67311, -1.62083, -1.47943, -1.26, -0.965395, -0.565015, -0.14099, 0.05003};
    double suma = y[0] + y[N - 1];
    double h = x[1] - x[0];

    for (int i = 1; i < N - 1; i++) {
        // usarlo en caso de no completar todos los datos a mano
        //x[i] = x[0] + i * h; // se puede usar a = x[0], pero así ahorramos memoria
        suma += 2 * y[i];
    }

    suma *= h/2;
    printf("El resultado es: %lf", suma);
    return 0;
}