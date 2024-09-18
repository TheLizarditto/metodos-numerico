#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
	return pow(x, 5) - 3*pow(x, 3) - 2*pow(x, 2) + 2;
}

int main(int argc, char *argv[]) {
	// xv y xvv no pueden ser muy chicos
	double xv = 1, xn = 0, xvv = 1.3, error = 0;
	int tol = 0, iteraciones = 0;
	
	printf("Ingrese la tolerancia: ");
	scanf("%d", &tol);
	double tolerancia = pow(10,-tol);
	
	do{
		iteraciones++;
		xn = xv - f(xv)*(xvv - xv)/(f(xvv) - f(xv));
			
		error = abs(xn-xv);
        xvv = xv;
		xv = xn;
		
	} while(error > tolerancia && iteraciones <= 10000);
	
	printf("Xnuevo = %.12lf \n", xn);
	if(f(xn) < tolerancia){
		printf("Iteraciones = %d \n", iteraciones);
		printf("Error = %.10lf", error);
	}
	
	return 0;
}
