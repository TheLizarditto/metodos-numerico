#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

double g(double x){
	return exp(-x);
}
	
int main(int argc, char *argv[]) {
	double xv = 0, xn = 0, error = 0;
	int iteraciones = 0, tol = 0;
	
	printf("Ingrese la tolerancia: ");
	scanf("%d", &tol);
	double tolerancia = pow(10, -tol);
	
	do{
		iteraciones++;
		xn = g(xv);
		
		if (abs((g(xv + 0.002) - g(xv))/0.002) > 1) {
			printf("Diverge");
			exit(1);
		}
		
		error = abs(xn - xv);
		xv = xn;
	} while(error > tolerancia);
	
	printf("Raiz = %.10lf\n", xv);
	printf("Error = %.10lf\n", error);
	printf("Iteraciones = %d", iteraciones);
	return 0;
}
	
