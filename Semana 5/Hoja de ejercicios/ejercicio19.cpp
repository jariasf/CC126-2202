#include <iostream>
#include <cmath>
using namespace std;

int ingresarCantidadTerminos();
double calcularSumatoria(int, double, double);
double potencia(double, int);
int factorial(int);
double ingresarValorA();
double ingresarValorB();

int main() {
    double a = ingresarValorA();
    double b = ingresarValorB();
    int n = ingresarCantidadTerminos();

    double sumatoria = calcularSumatoria(n, a, b);
    cout << "\nEl valor de la sumatoria es S: " << sumatoria << endl;

    return 0;
}

int ingresarCantidadTerminos() {
    int n;
    do {
        cout << "Ingrese el valor de n: ";
        cin >> n;
    } while (!(n >= 1 && n <= 10));
    return n;
}

double ingresarValorA() {
    double a;
    do {
        cout << "Ingrese el valor de a: ";
        cin >> a;
    } while (!(a >= 4 && a <= 6)) ;
    return a;
}

double ingresarValorB() {
    double b;
    do {
        cout << "Ingrese el valor de b: ";
        cin >> b;
    } while (!(b >= 1 && b <= 3));
    return b;
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
        prod = prod * i;
    }
    return prod;
}

double calcularSumatoria(int n, double a, double b) {
    double suma, numerador, denominador, termino;
    int signo;
    suma = 0.;

    //cout << "Los terminos son: ";
    for (int i = 1; i <= n; ++i) {
        // Hallamos el numerador y denominador
        numerador = potencia(a, i) * potencia(b, i+1); // a^i * b^(i+1)
        denominador = (a - b) * factorial(i); // (a-b)*i!

        // Hallamos el signo
        signo = potencia(-1, i+1); // (-1)^(i+1)

        // Hallamos el i-esimo termino
        termino = signo * numerador / denominador;
        //cout << termino << " ";

        // Lo agregramos a la suma
        suma += termino;
    }
    //cout << endl;
    return suma;
}

