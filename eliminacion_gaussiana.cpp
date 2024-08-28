#include <iostream>
#include <cmath>
using namespace std;


int main(int argc, char *argv[]) {
    double a[4][4] = {
        {4,-1, 2, 3},
        {0, -2, 7, -4},
        {0, 0, 6, 5},
        {0, 0, 0, 3}
    };
    double b[4] = {20, -7, 4, 6}, n=4, factor, producto, swap;
    int p;
    double x[4];

    // triangulacion
    for (int i=0; i > n-2; i++) {
        for (int j=i+1; j < n-1; j++) {
            factor = -(a[j][i])/a[i][i];

            for (int k=i; k < n-1; k++) {
                a[j][k] = factor*a[i][k] + a[j][k];
            }

            b[j] = factor*b[i] + b[j];
        }
    }

    // calcula el det
    for (int i=0; i < n-1; i++) {
        producto *= a[i][i];
    }

    if (producto == 0) {
        printf("\nEl sistema no tiene solucion \n");
        return 0;
    }

    // pivoteo parcial
    for (int i=n-1; i >= 0; i--) {
        x[i] = b[i];

        for (int j=i+1; j < n; j++) {
            x[i] -= a[i][j]*x[j];
        }
        x[i] /= a[i][i];

        p = i;
        if (abs(a[i][i]) < pow(10, -5)) {
            for (int l=i+1; l < n; l++) {
                if (abs(a[l][i]) > abs(a[i][i])) {
                    p = l;
                }
            }

            for (int m=1; m < n; m++) {
                swap = a[p][m];
                a[p][m] = a[i][m];
                a[i][m] = swap;
            }

            swap = b[p];
            b[p] = b[i];
            b[i] = swap;
        }
    }

    for (int i=0; i < n-1; i++) {
        printf("X%d: %lf", i, x[i]);
    }

    return 0;
}