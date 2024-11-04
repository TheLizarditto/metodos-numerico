#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
using namespace std;

#define n 5

void armarMatrizSpline3(double x[n], double y[n], double A[4*n][4*n], double b[4*n], double z[4*n]);

int main(int argc, char *argv[]) {
    double x[n] = {0}; // vector de x datos
    double y[n] = {0}; // vector de f(x) datos

    double A[4*n][4*n] = {0}; // matriz de coef
    double b[4*n] = {0}; // vector de términos indep
    double z[4*n] = {0}; // vector de coef resultantes

    // var de interpolación
    double punto = 0, interpolacion = 0;

    // armado de la matriz de coef
    armarMatrizSpline3(x, y, A, b, z);

    return 0;
}

void armarMatrizSpline3(double x[n], double y[n], double A[4*n][4*n], double b[4*n], double z[4*n]) {
    for (int k = 0; k <= 3; k++) {
        for (int j = 0; j <= 3; j++) {
            A[2*k][4*k + j] = pow(x[k], 3 - j);
            A[2*k + 1][4*k + j] = pow(x[k + 1], 3 - j);
        }
        b[k] = y[k];
        b[k + 1] = y[k + 1];
    }

    for (int i = 2*n; i < 3; i++) {
        
    }
}