#include <iostream>
#include <cmath>
using namespace std;

#define n 3
/*
consiste en despejar cada incógnita de un sistema de ecuaciones lineales y resolverlas iterativamente. 
Para cada ecuación, despejamos la incógnita actual usando los valores de las demás incógnitas,
que son aproximaciones de la iteración anterior
*/

int main(int argc, char *argv[]) {
    double a[n][n] = {
        { 5, -1,  3},
        { 3,  5,  1},
        {-1,  1,  3},
    };
    double b[n] = {7, 9, 3};
    double xn[n], suma, error, errorv;
    double xv[n] = {0}; // se podría ingresar a mano
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
        // el acumulador tmb sumo a[i][i], así que hay que eliminarlo
		suma -= abs(a[i][i]);
        
        if (abs(a[i][i]) <= suma) {
            printf("La matriz no es diagonalmente dominante, el metodo podria no converger \n\n");
            break;
        }
    }

    // que el error se achique con cada iteracion
    do {
        iteracion++;
        
        for (i = 0; i < n; i++) {
            suma = 0;
            
            for (j = 0; j < n; j++) {
                suma += a[i][j]*xv[j];
            }

			suma -= a[i][i] * xv[i];
            xn[i] = (b[i] - suma)/a[i][i];
        }

        // calculo del error usando Xn y Xv
        suma = 0;
		for(i = 0; i < n; i++){
			suma += pow((xn[i] - xv[i]), 2);
		}

        // calcula el error absoluto
        error = sqrt(suma);
        
        // chequeamos si el error se agranda
        if (errorv < error && iteracion > 1) {
            printf("El error se agranda, el metodo no converge \n");
            return 0;
        } else {
            errorv = error;
            
			for(i = 0; i < n; i++){
				xv[i] = xn[i];
			}
        }
    } while (error > tol && iteracion <= 10000);

    printf("El error es: %.12lf \n", error);
    printf("Con %d iteraciones \n", iteracion);

    for (i = 0; i < n; i++) {
        printf("X_%d: %.12lf \n", i, xn[i]);
    }

    return 0;
}