#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return (pow(x,3) * 2);
}

int main(int argc, char *argv[]) {
    double a = 0;
    double b = 4;
    double c[6];
    double x[6];
    double I = 0;
    int puntos;
    
    do {
        printf("Ingrese el punto que quiera (0 para salir): ");
        scanf("%d", puntos);

        switch (puntos) {
            case 2:
                c[0] = 1;
                c[1] = 1;
                x[0] = -1 / sqrt(3);
                x[1] = 1 / sqrt(3);
                break;

            case 3:
                c[0] = 0.5555556;
                c[1] = 0.8888889;
                c[2] = 0.5555556;
                x[0] = -0.774596669;
                x[1] = 0;
                x[2] = 0.774596669;
                break;

            case 4:
                c[0] = 0.3478548;
                c[1] = 0.6521452;
                c[2] = 0.6521452;
                c[3] = 0.3478548;
                x[0] = -0.861136312;
                x[1] = -0.339981044;
                x[2] = 0.339981044;
                x[3] = 0.861136312;
                break;

            case 5:
                c[0] = 0.2369269;
                c[1] = 0.4786287;
                c[2] = 0.5688889;
                c[3] = 0.4786287;
                c[4] = 0.2369269;
                x[0] = -0.906179846;
                x[1] = -0.538469310;
                x[2] = 0;
                x[3] = 0.538469310;
                x[4] = 0.906179846;
                break;

            case 6:
                c[0] = 0.1713245;
                c[1] = 0.3607616;
                c[2] = 0.4679139;
                c[3] = 0.4679139;
                c[4] = 0.3607616;
                c[5] = 0.1713245;
                x[0] = -0.932469514;
                x[1] = -0.661209386;
                x[2] = -0.238619186;
                x[3] = 0.238619186;
                x[4] = 0.661209386;
                x[5] = 0.932469514;
                break;
            
            case 0:
                printf("Chau");
                break;
                
            default:
                printf("Los puntos van de 2 a 6");
                return 0;
        }

        for (int j = 0; j < puntos; j++) {
            I += c[j] * f(((b - a) * x[j]) / 2 + (b + a) / 2 );
        }
        I *= (b - a) / 2;

        printf("El resultado es: %lf", I);
        
    } while (puntos != 0);
    
    
    return 0;
}