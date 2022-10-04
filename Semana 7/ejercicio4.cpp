#include <iostream>
using namespace std;

int ingresarNumero();
double ingresarConstante();
double calcularSumatoria(int, double);
double calcularSumatoriaCambioDeSigno(int, double);

int main() {
    int n;
    double a, suma;
    n = ingresarNumero();
    a = ingresarConstante();
    suma = calcularSumatoria(n, a);
    cout << "\nResultado: " << suma << endl;   
    return 0;
}

int ingresarNumero() {
    int n;
    do {
        cout << "Ingrese el valor de N: ";
        cin >> n;
    } while (n <= 0);
    return n;
}

double ingresarConstante() {
    double a;
    do {
        cout << "Ingrese el valor de a: ";
        cin >> a;
    } while (a < 1 || a > 4);
    return a;
}

double calcularSumatoria(int n, double a) {
    double termino, suma{0.}, numerador, denominador;
    for (int i = 1; i <= n; ++i) {
        numerador = a;
        denominador = i * (i + 1);
        termino = numerador / denominador;
        suma += termino;
    }
    return suma;
}

double calcularSumatoriaCambioDeSigno(int n, double a) {
    double termino, suma{0.}, numerador, denominador;
    int signo{1.};
    for (int i = 1; i <= n; ++i) {
        numerador = a;
        denominador = i * (i + 1);
        termino = signo * numerador / denominador;
        suma += termino;
        signo *= -1;
    }
    return suma;
}