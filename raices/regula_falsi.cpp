#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

double f(double x){
	return pow(x,10)-1;
}
	
void diseccion(double a, double b, double tolerancia, short int porcentaje){
	double c = 0;
	int rondas = 0;
	double error = 0;
	
	if (f(a)*f(b) > 0){
		printf("No hay una raiz en el intervalo dado, o hay una cantidad par de ellas");
	} else {
		if (porcentaje == 1) {
			do {
				c = (a*f(b) - b*f(a))/(f(b) - f(a));
				
				if (f(a)*f(c) < 0){
					b = c;
				} else {
					if (f(b)*f(c) < 0){
						a = c;
					} else {
						printf("Encontraste la raiz exacta!");
						printf("La raiz es: %.20lf", c);
					}
				}
				
				error = (((b-a)/2)/c)*100;
				rondas++;
			} while(error >= tolerancia);
		} else {
			do {
				c = (a+b)/2;
				
				if (f(a)*f(c) < 0){
					b = c;
				} else {
					if (f(b)*f(c) < 0){
						a = c;
					} else {
						printf("Encontraste la raiz exacta!");
						printf("La raiz es: %.20lf", c);
					}
				}
				
				error = ((b-a)/2)/c;
				rondas++;
			} while(error >= tolerancia);
		}
		
		printf("Tras %d rondas se encontro que el valor de la raiz es: %.20lf +- %.20lf", rondas, c, error);
	}
}
	
int main(int argc, char *argv[]) {
	int relativo;
	double valor;
	double a,b;
	printf("Elija si quiere usar error \n 0 - Relativo \n 1 - Porcentual \n: ");
	scanf("%d", &relativo);
	
	
	printf("Ingrese el valor de a: ");
	scanf("%lf", &a);
	
	printf("Ingrese el valor de b: ");
	scanf("%lf", &b);
	
	if (relativo == 0) {
		printf("Ingrese la cantidad de cifras decimales de tolerancia: ");
		scanf("%lf", &valor);
		
		diseccion(a, b, pow(10, -valor), 0);
	} else {
		printf("Ingrese el porcentaje de error: ");
		scanf("%lf", &valor);
		
		diseccion(a, b, valor, 1);
	}
	
	
	return 0;
}
