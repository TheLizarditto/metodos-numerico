#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define n 2
using namespace std;

/*
encontrar los coeficientes del polinomio interpolador
resolver un sistema de ecuaciones lineales utilizando
el método de eliminación de Gauss para encontrar los coeficientes 
de un polinomio interpolador que pase por un conjunto de puntos dados
*/

void gauss(double A[n][n], double B[n], double X[n]);
void armar(double A[n][n], double B[n], double Xi[n], double X[n], double Y[n]);
void obtener_valor(double Xi[n]);

int main(int argc, char *argv[]) {
	//declaracion de variables
	double X[n]={1, 2}, Y[n]={4, 7};
	double A[n][n], B[n], Xi[n];

	printf("----------------------------------\n");
	printf("Armamos el polinomio interpolador:\n");
	printf("----------------------------------");
	
	armar(A, B, Xi, X, Y);
	
	printf("----------------------------------\n");
	printf("Obtenemos valor interpolado:\n");
	printf("----------------------------------");
	
	obtener_valor(Xi);
	return 0;
}

void gauss(double A[n][n], double B[n], double X[n]) {
	double factor = 0;
	double swap = 0;
	double prod = 1;
	
	// Triangulacion -> Obtener matriz triangular superior (Elementos por debajo de la diagonal principal = 0)
	for(int i = 0; i < (n - 1); i++) {
		int p = i; // p va a ser el indice de la fila en la que estemos
		
		// Pivoteo parcial -> encuentra la fila con el mayor valor absoluto en la columna i e intercambia
		if (fabs(A[i][i]) < pow(10, -5)) {
			// Busca la fila con el mayor valor absoluto en la columna i
			for(int l = i + 1; l < n; l++) {
				if(fabs(A[l][i]) > fabs(A[p][i])) {
					p = l;
				}
			}
			//intercambio de filas
			if(p != i) {
				for(int m = 0; m < n; m++) {
					swap = A[p][m];
					A[p][m] = A[i][m];
					A[i][m] = swap;
				}
				swap = B[p];
				B[p] = B[i];
				B[i] = swap;
			}
		}

		//continuamos con triangulacion
		//este bucle hace cero todos los elementos debajo de la diagonal princial
		for (int j = i + 1; j < n; j++) {
			factor = -(A[j][i])/(A[i][i]);
			//este bucle actualiza los elementos de la fila j a partir de la columna i
			for(int k = i;k < n; k++) {
				A[j][k] += factor*A[i][k];
			}
			//También se debe actualizar el término independiente correspondiente en el vector B
			B[j] += factor*B[i];
		}	
	}
	
	//Chequeo del determinante->Nuestra matriz debe tener
	for(int i = 1; i < n; i++) {
		prod = prod*A[i][i];
	}
	if(prod == 0) {
		printf("\nEl sistema no tiene solucion (su determinante es 0)");
		exit(0);
	}
	
	//Restrosusticion-> sustituir los valores encontrados en las ecuaciones más simples en las más complejas, de atrás hacia adelante.
	for(int i = n - 1; i >= 0; i--) {
		X [i] = B [i];
		for(int j = i + 1; j < n; j++) {
			X[i] = X[i] - A[i][j]*X[j];
		}
		X[i] = X[i]/A[i][i];
	}
	
	//Impresion de los valores de X
	printf("\nLos valores de las incognitas son:\n");
	for(int i = 0; i < n; i++) {
		printf("X[%d]= %.2lf \n", i + 1, X[i]);
	}
}

void armar(double A[n][n], double B[n], double Xi[n], double X[n], double Y[n]){
	for(int i = 0; i < n; i++) {
		// creamos la matriz a partir de los datos
		for(int j = 0; j < n; j++) {
			A[i][j] = pow(X[i], j);
		}
		B[i] = Y[i];
	}
	gauss(A, B, Xi);
	
	//armamos el polinomio para visualizarlo mejor
	printf("\nEl polinomio interpolador obtenido es:\nP(x)= ");
	for(int i = 0; i < n; i++) {
		if(i > 0) {
			printf(" %s ", Xi[i] >= 0 ? "+ " : "- ");
		}
		if(i == 0) {
			printf("%.2lf", Xi[i]);
		} else {
			if (i == 1) {
				printf("%.2lfx", fabs(Xi[i]));
			} else {
				printf("%.2lfx^%d", fabs(Xi[i]), i);
			}
		}
	}
	printf("\n\n");
}

void obtener_valor(double Xi[n]){
	double v_interpolar=0;
	double suma=0;
	
	// Solicitar al usuario el valor de X para el que quiere estimar Y
	printf("\nIngrese el valor a interpolar (^x):");
	scanf("%lf", &v_interpolar);
	//calculo del valor interpolado
	for(int i = 0; i < n; i++) {
		suma += Xi[i]*pow(v_interpolar, i);
	}
	printf("\nEl valor interpolado es %.2lf", suma);
}
