#include <iostream>
using namespace std;

#define N 3 // cantidad de datos

int main(int argc, char *argv[]) {
    double x[N] = {1, 1.5, 2};
    double y[N] = {2, 5, 6};
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