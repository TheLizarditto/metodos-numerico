#include <iostream>
#include <cmath>
using namespace std;

#define n 4

int main(int argc, char *argv[]) {
    double a[n][n] = {
        {4, -1,  2,  3},
        {0, -2,  7, -4},
        {0,  0,  6,  5},
        {0,  0,  0,  3}
    };
    double b[n], xn[n], suma, error, errorv;
    double xv[n] = {1, 1, 1, 1};
    int tol, iteracion = 0;
    bool bandera = false;

    printf("Ingrese la tolerancia: ");
	scanf("%d", &tol);
    tol = pow(10, -tol);

    // Asegurarnos que no hay un x_ii semejante a 0
    for (int i = 0; i < n; i++) {
        if (abs(a[i][i]) < 0.01) {
            printf("Hay un x_ii muy chico \n\n");
            return 0;
        }
    }
    
    // ver si la matríz es "diagonalmente dominante", osea que todos los |a_ii| > sum(a_ij) con j distinto de i
    for (int i = 0; i < n; i++) {
        suma = 0;

        for (int j = 0; j < n; j++) {
            if (j != i) {
                suma += abs(a[i][j]);
            }    
        }
        
        if (abs(a[i][i]) <= suma) {
            printf("No es diagonalmente dominante \n\n");
            break;
        }
    }


    // que el error se achique con cada iteracion
    do {
        if (errorv < error && bandera == true) {
            printf("El error se agranda");
            return 0;
        } else {
            if (bandera == false) {
                bandera = true;
            }
        }

        iteracion++;
        
        for (int i = 0; i < n; i++) {
            suma = 0;
            
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    suma += a[i][j]*xv[j];
                }
            }
            xn[i] = (b[i] - suma)/a[i][i];
        }

        // calcula el error absoluto
        suma = pow(xn[0] - xv[0], 2);

        for (int i = 0; i < n; i++) {
            suma += pow(xn[i] - xv[i], 2);
        }
        errorv = error;
        error = sqrt(suma);

        for(int i = 0; i < n; i++) {
            xv[i] = xn[i];
        }
    } while (error > tol && iteracion <= 10000);

    printf("El error es: %.10lf \n", error);
    printf("Con %d iteraciones \n", iteracion);

    for (int i = 0; i < n; i++) {
        printf("X_%d: %.10lf \n", i, xn[i]);
    }

    return 0;
}