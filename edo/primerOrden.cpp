#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define N 5

// hacemos las pp funciones
double f1(double x, double y1, double y2) {
    return 3 * x + y2;
}

double f2(double x, double y1, double y2) {
    return pow(x, 2) - y1 - y2;
}

int main(int argc, char *argv[]) {
    double x[N + 1];
    // hacemos los p arreglos de y
    double y1[N + 1];
    double y2[N + 1];
    double h;
    int n, sel, metodo;
    
    FILE *file = fopen("primerOrdenEuler_tabla.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    FILE *file2 = fopen("primerOrdenRk4_tabla.txt", "w");       
    if (file2 == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    do {
        printf("Elija si usar Euler o Rk4 (0: Euler, 1: Rk4): ");
        scanf("%d", &metodo);

        switch (metodo) {
        // Euler
        case 0:
            printf("Ingrese x_0: ");    
            scanf("%lf", &x[0]);

            printf("Ingrese x_n: ");
            scanf("%lf", &x[N]);

            printf("Ingrese y_1_0: ");
            scanf("%lf", &y1[0]);

            printf("Ingrese y_2_0: ");
            scanf("%lf", &y2[0]);

            do {
                printf("Elija si ingresar h o n (0 para h y 1 para n): ");
                scanf("%d", &sel);
                
                switch (sel) {
                    case 0:
                        printf("Ingrese h: ");
                        scanf("%lf", &h);

                        n = (x[N] - x[0]) / h;
                        break;

                    case 1:
                        printf("Ingrese n: ");
                        scanf("%d", &n);

                        h = (x[N] - x[0]) / n;
                        break;
                    
                    default:
                        printf("Ingrese 0 o 1");
                        break;
                }
            } while (sel != 0 && sel != 1);

            for(int i = 0; i < n - 1; i++) {
                x[i + 1] = x[i] + h;
                y1[i + 1] = y1[i] + h * f1(x[i], y1[i], y2[i]);
                y2[i + 1] = y2[i] + h * f2(x[i], y1[i], y2[i]);
                printf("\nX%d = %lf \tY1%d = %lf \tY2%d = %lf", i+1, x[i+1], i+1, y1[i+1], y2[i+1]);
                fprintf(file, "%lf\t%lf\t%lf\n", x[i+1], y1[i+1], y2[i+1]);
            }
            break;
        
        // RK4
        case 1:
            // son 4 k con p elementos adentro
            double k1[2];
            double k2[2];
            double k3[2];
            double k4[2];

            printf("Ingrese x_0: ");    
            scanf("%lf", &x[0]);

            printf("Ingrese x_n: ");
            scanf("%lf", &x[N]);

            printf("Ingrese y10: ");
            scanf("%lf", &y1[0]);

            printf("Ingrese y20: ");
            scanf("%lf", &y2[0]);
            
            do {
                printf("Elija si ingresar h o n (0 para h y 1 para n): ");
                scanf("%d", &sel);
                
                switch (sel) {
                    case 0:
                        printf("Ingrese h: ");
                        scanf("%lf", &h);

                        n = (x[N] - x[0]) / h;
                        break;

                    case 1:
                        printf("Ingrese n: ");
                        scanf("%d", &n);

                        h = (x[N] - x[0]) / n;
                        break;
                    
                    default:
                        printf("Ingrese 0 o 1");
                        break;
                }
            } while (sel != 0 && sel != 1);
            
            for(int i = 0; i < n - 1; i++) {
                x[i + 1] = x[i] + h;
                k1[0] = f1(x[i], y1[i], y2[i]);
                k1[1] = f2(x[i], y1[i], y2[i]);
                k2[0] = f1(x[i] + h/2, y1[i] + k1[0] * h/2, y2[i] + k1[1] * h/2);
                k2[1] = f2(x[i] + h/2, y1[i] + k1[0] * h/2, y2[i] + k1[1] * h/2);
                k3[0] = f1(x[i] + h/2, y1[i] + k2[0] * h/2, y2[i] + k2[1] * h/2);   
                k3[1] = f2(x[i] + h/2, y1[i] + k2[0] * h/2, y2[i] + k2[1] * h/2);
                k4[0] = f1(x[i] + h, y1[i] + k3[0] * h, y2[i] + k3[1] * h);  
                k4[1] = f2(x[i] + h, y1[i] + k3[0] * h, y2[i] + k3[1] * h);
                y1[i + 1] = y1[i] + (k1[0] + 2*k2[0] + 2*k3[0] + k4[0])/6;
                y2[i + 1] = y2[i] + (k1[1] + 2*k2[1] + 2*k3[1] + k4[1])/6;
                printf("\nX%d = %lf \tY1%d = %lf \tY2%d = %lf", i+1, x[i+1], i+1, y1[i+1], y2[i+1]);
                fprintf(file2, "%lf\t%lf\t%lf\n", x[i+1], y1[i+1], y2[i+1]);                             
            }
            break;

        default:
            printf("Debe ingresar 0 o 1");
            break;
        }
    } while (metodo != 0 && metodo != 1);


    fclose(file);
    fclose(file2);

    return 0;
}