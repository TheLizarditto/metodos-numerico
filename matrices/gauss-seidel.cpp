#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

#define n 3
/*
Jacobi pero usando lo que ya calculaste
*/

int main(int argc, char *argv[]) {
    double a[n][n] = {
        { 5, -1,  3},
        { 3,  5,  1},
        {-1,  1,  3},
    };
    double b[n] = {7, 9, 3};
    double xn[n], suma, error, errorv;
    double xv[n] = {0};
    int tol, iteracion = 0, i = 0, j = 0;

    printf("Ingrese la tolerancia: ");
	scanf("%d", &tol);
    tol = pow(10, -tol);

    // Asegurarnos que no hay un x_ii semejante a 0
    for (i = 0; i < n; i++) {
        if (abs(a[i][i]) < 0.01) {
            printf("Hay un x_ii muy chico \n\n");
            return 0;
        }
    }
    
    // ver si la matríz es "diagonalmente dominante", osea que todos los |a_ii| > sum(a_ij) con j distinto de i
    for (i = 0; i < n; i++) {
        suma = 0;

        for (j = 0; j < n; j++) {
            suma += abs(a[i][j]);
        }
        suma -= a[i][i];
        
        if (abs(a[i][i]) <= suma) {
            printf("No es diagonalmente dominante \n\n");
            break;
        }
    }

    do {
        iteracion++;
        
        for (i = 0; i < n; i++) {
            suma = 0;
            
            // Sumar los productos de los elementos de la izquierda de la diagonal
            for(j = 0; j < i; j++){
                suma += a[i][j]*xn[j];
            }

            // Sumar los productos de los elementos de la derecha de la diagonal
            for(j = i+1; j < n; j++){
                suma += a[i][j]*xv[j];
            }
            xn[i] = (b[i] - suma) / (a[i][i]);

        }
        // calcula el error cuadrático
        suma = 0;

        for (i = 0; i < n; i++) {
            suma += pow((xn[i] - xv[i]), 2);
        }
        error = sqrt(suma);

        if (errorv < error && iteracion > 1) {
            printf("El error se agranda, el metodo no converge \n");
            return 0;
        } else {
            errorv = error;

            for(i = 0; i < n; i++) {
                xv[i] = xn[i];
            }
        }
    } while (error > tol && iteracion < 10000);

    printf("El error es: %.12lf \n", error);
    printf("Con %d iteraciones \n", iteracion);

    for (i = 0; i < n; i++) {
        printf("X_%d: %.12lf \n", i, xn[i]);
    }

    return 0;
}