#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1, i = 1;
    while (i <= n) {
        fact *= i; // fact = fact * i;
        ++i;
    }
    return fact;
}

double calcularSumatoria(int n) {
    // Declaracion
    double suma, termino;
    int i;
    // Inicializacion
    i = 1;
    suma = 0;
    // Proceso
    cout << "Los terminos son: ";
    while (i <= n) {
        termino = 1.0 * i/factorial(i);
        cout << termino << " ";
        suma += termino; // suma = suma + termino;
        ++i;
    }
    cout << endl;
    // Retorno
    return suma;
}

double calcularSumatoria2(int n) {
    // Declaracion
    double suma, termino;
    int i, fact;
    // Inicializacion
    i = 1;
    suma = 0;
    fact = 1;
    // Proceso
    cout << "Los terminos son: ";
    while (i <= n) {
        fact *= i;
        termino = 1.0 * i / fact;
        cout << termino << " ";
        suma += termino; // suma = suma + termino;
        ++i;
    }
    cout << endl;
    // Retorno
    return suma;
}

int main() {
    int n;
    double suma;
    cout << "Cantidad de terminos: ";
    cin >> n;
    //Debe validar que n sea un número positivo y menor a 12.
    if (n > 0 && n < 12) {
        suma = calcularSumatoria2(n);
        cout << "La suma es: " << suma << endl;
    }
    else {
        cout << "Ingreso invalido\n";
    }
    return 0;
}