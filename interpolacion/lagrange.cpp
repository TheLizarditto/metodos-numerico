#include <iostream>
#include <ctime>
using namespace std;

#define n 3
 
void cargar(double X[n], double Y[n]);
void imprimir(double X[n], double Y[n]);
void interpolacion(double X[n], double Y[n]);

int main(int argc, char *argv[]) {
	double X[n]={1, 2, 2.35}, Y[n]={3, 3, 3.3};
    int i, j;
	srand(time(NULL));
	
	imprimir(X, Y);
	interpolacion(X, Y);
	return 0;
}

void cargar(double X[n], double Y[n]) {
    int i;

	printf("Datos en X:\n");
	for(i = 0; i < n; i++) {
		X[i] = rand() % 100;
		printf("%.2lf\n", X[i]);
	};

	printf("\nDatos en Y:\n");
	for(i = 0; i < n; i++) {
		Y[i] = rand() % 100;
		printf("%.2lf\n", Y[i]);
	};
}

void imprimir(double X[n], double Y[n]) {
	printf("Tabla de datos:\n");
	printf("_X___|_Y___\n");

	for(int i = 0; i < n; i++) {
		printf("%.2lf", X[i]);
		printf("|%.2lf\n", Y[i]);
	};
}

void interpolacion(double X[n], double Y[n]) {
	double v_interpolar = 0, suma = 0, producto = 0;
    int i, j;

	// Solicitar al usuario el valor de X para el que quiere estimar Y
	printf("\nIngrese el valor de x a interpolar: ");
	scanf("%lf", &v_interpolar);
	
    //calculo del valor interpolado
	for(i = 0; i < n; i++) {
		producto = 1;
		for(j = 0; j < n; j++){
			if(i != j){
				producto = producto * (v_interpolar - X[j])/(X[i] - X[j]);
			}
		}
		suma = suma + (Y[i] * producto);
	}

	printf("\nEl valor interpolado es %.10lf", suma);
}
