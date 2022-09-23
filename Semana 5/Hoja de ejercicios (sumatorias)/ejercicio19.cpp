#include <iostream>
#include <cmath>
using namespace std;

int ingresarCantidadTerminos();
double calcularSumatoria(int, double);
double potencia(double, int);
int factorial(int);
double ingresarValor();

int main() {
    int n = ingresarCantidadTerminos();
    double x = ingresarValor();
    double sumatoria = calcularSumatoria(n, x);
    cout << "La suma es: " << sumatoria << endl;
    return 0;
}

int ingresarCantidadTerminos() {
    int n;
    do {
        cout << "Cantidad de terminos: ";
        cin >> n;
    } while (!(n > 0 && n < 11));
    return n;
}

double ingresarValor() {
    double x;
    do {
        cout << "Ingrese el valor de x: ";
        cin >> x;
    } while (!(x > 0 && x < 5.5));
    return x;
}

/*
2^5 = 2*2*2*2*2

prod = 1;
i=1 prod = 1 * 2 = 2;
i=2 prod = 2 * 2 = 4;
i=3 prod = 4 * 2 = 8;
i=4 prod = 8 * 2 = 16;
i=5 prod = 16 * 2 = 32;

prod = prod * 2;
*/
double potencia(double base, int exponente) {
    double prod = 1.;
    for (int i = 1; i <= exponente; ++i) {
        prod *= base;
    }
    return prod;
}

/*
5! = 1*2*3*4*5

int prod = 1;
i
1 prod = 1 * 1 = 1;
2 prod = 1 * 2 = 2;
3 prod = 2 * 3 = 6;
4 prod = 6 * 4 = 24;
5 prod = 24 * 5 = 120;

i=4 prod = 24;
i=5 prod = prod * 5 = 120;

*/
int factorial(int n) {
    int prod = 1.;
    for (int i = 1; i <= n; ++i) {
        prod = prod * i;
    }
    return prod;
}

double calcularSumatoria(int n, double x) {
    double suma, numerador, denominador, termino;
    suma = 0.;

    cout << "Los terminos son: ";
    for (int i = 1; i <= n; ++i) {
        // Hallamos el numerador y denominador
        numerador = potencia(x, i - 1);
        denominador = factorial(i);

        // Hallamos el i-esimo termino
        termino = numerador / denominador;
        cout << termino << " ";

        // Lo agregramos a la suma
        suma += termino;
    }
    cout << endl;
    return suma;
}

