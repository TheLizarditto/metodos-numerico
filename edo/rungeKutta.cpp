#include <iostream>
#include <vector>
using namespace std;

#define N 5

double f(double x, double y) {
    return (-2 * x * y);
}

int main(int argc, char *argv[]) {
    double x[N + 1];
    double y[N + 1];
    double h, k1, k2, k3, k4;
    int n, sel;

	FILE *file = fopen("rungeKutta_tabla.txt", "w");
	
    if (file == NULL) {
		printf("Error al abrir el archivo\n");
		return 1;
	}

    printf("Ingrese x_0: ");
    scanf("%lf", &x[0]);

    printf("Ingrese x_n: ");
    scanf("%lf", &x[N]);

    printf("Ingrese y_0: ");
    scanf("%lf", &y[0]);


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

    for (int i = 0; i < N - 1; i++) {
        k1 = f(x[i], y[i]);
        k2 = f(x[i] + h / 2, y[i] + (h * k1) / 2);
        k3 = f(x[i] + h / 2, y[i] + (h * k2) / 2);
        k4 = f(x[i] + h, y[i] + h * k3);

        y[i + 1] = y[i] + (h * (k1 + 2 * k2 + 2 * k3 + k4)) / 6;
        x[i + 1] = x[i] + h;
        printf("\nX%d = %lf \tY%d = %lf", i+1, x[i+1], i+1, y[i+1]);
		fprintf(file, "%lf\t%lf\n", x[i+1], y[i+1]);
    }

    fclose(file);
    
    return 0;
}