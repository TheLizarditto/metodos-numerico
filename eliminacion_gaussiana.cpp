#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
    double a[4][4] = {
        {4, -1,  2,  3},
        {0, -2,  7, -4},
        {0,  0,  6,  5},
        {0,  0,  0,  3}
    };
    double b[4] = {20, -7, 4, 6}, n=4, factor, swap, x[4];
    int pivot, producto;

    //modifica la matriz para que sea triangulable
    for (int i=n-1; i >= 0; i--) {
        pivot = i;
        if (abs(a[i][i]) < pow(10, -5)) {
            for (int j=i+1; j < n; j++) {
                if (abs(a[j][i]) > abs(a[i][i])) {
                    pivot = j;
                }
            }

            for (int m=1; m < n; m++) {
                swap = a[pivot][m];
                a[pivot][m] = a[i][m];
                a[i][m] = swap;
            }

            swap = b[pivot];
            b[pivot] = b[i];
            b[i] = swap;
        }
    }

    // triangulacion
    for (int i=0; i < n-1; i++) {
        for (int j=i+1; j < n; j++) {
            factor = - (a[j][i])/a[i][i];

            for (int k=i; k < n; k++) {
                a[j][k] = factor*a[i][k] + a[j][k];
            }

            b[j] = factor*b[i] + b[j];
        }
    }

    // calcula el det
    producto = a[0][0];
    for (int i=1; i < n; i++) {
        producto *= a[i][i];
    }

    if (producto == 0) {
        printf("\nEl sistema no tiene solucion \n");
        return 0;
    } else {
        printf("\nEl determinante es: %d \n\n", producto);
    }

    // pivoteo parcial
    for (int i=n-1; i >= 0; i--) {
        x[i] = b[i];

        for (int j=i+1; j < n; j++) {
            x[i] -= a[i][j]*x[j];
        }
        x[i] /= a[i][i];
    }

    for (int i=0; i < n; i++) {
        printf("X%d: %lf \n", i, x[i]);
    }

    return 0;
}