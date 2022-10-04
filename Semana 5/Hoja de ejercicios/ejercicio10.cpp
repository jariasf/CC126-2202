#include <iostream>
#include <cmath>
using namespace std;

int ingresarCantidadTerminos();
double calcularSumatoria(int);
double potencia(double, int);
int factorial(int);

int main() {
    int n = ingresarCantidadTerminos();
    double sumatoria = calcularSumatoria(n);
    cout << "La suma es: " << sumatoria << endl;
    return 0;
}

int ingresarCantidadTerminos() {
    int n;
    do {
        cout << "Cantidad de terminos: ";
        cin >> n;
    } while ( !(n > 0 && n < 11) );
    return n;
}

double potencia(double base, int exponente) {
    double prod = 1.;
    for (int i = 1; i <= exponente; ++i) {
        prod *= base;
    }
    return prod;
}

int factorial(int n) {
    int prod = 1.;
    for (int i = 1; i <= n; ++i) {
        prod *= i;
    }
    return prod;
}

double calcularSumatoria(int n) {
    double suma, numerador, denominador, termino;
    suma = 0.;
    
    cout << "Los terminos son: ";
    for (int i = 1; i <= n; ++i) {
        // Hallamos el numerador y denominador
        numerador = potencia(i, i + 1);
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

