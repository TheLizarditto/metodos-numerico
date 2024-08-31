#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
	return pow(x,10)-1;
}
	
double fp(double x){
	return 10*pow(x,9);
}

int main(int argc, char *argv[]) {
	double xv = 10, xn = 0, error = 0;
	int tol = 0, iteraciones = 0;
	
	printf("Ingrese la tolerancia: ");
	scanf("%d", &tol);
	double tolerancia = pow(10, -tol);
	
	do{
		iteraciones++;
		xn = xv - f(xv)/fp(xv);
		
		if(abs(fp(xn)) < pow(10,-10)){
			printf("Demasiado grande");
			exit(1);
		}
			
		error = abs(xn-xv);
		xv = xn;
		
	} while(error > tolerancia && iteraciones <= 1000);
	
	if(f(xn) < tolerancia){
		printf("Xnuevo = %.10lf \n", xn);
		printf("Iteraciones = %d \n", iteraciones);
		printf("Error = %.10lf", error);
	}
	
	return 0;
}

