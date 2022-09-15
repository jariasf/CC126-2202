#include <iostream>
using namespace std;

/*
S = 1 + 1/2 + 1/3 + 1/4 + 1/5 + ...
*/
double calcularSumatoria(int n) {
    int i;
    double suma, termino, numerador, denominador;

    // Inicializacion
    i = 1;
    suma = 0;
    cout << "Los terminos son: ";
    while (i <= n) {
        numerador = 1;
        denominador = i;
        termino = numerador / denominador;
        //termino = 1.0 / i;
        cout << termino << " ";
        suma = suma + termino;
        ++i; //i++; i = i + 1;
    }
    cout << endl;
    return suma;
}

int main() {
    int n;
    cout << "Cantidad de terminos: ";
    cin >> n;
    if (n > 0) {
        cout << "La suma es: " << calcularSumatoria(n) << endl;
    }
    else {
        cout << "Ingreso invalido\n";
    }
    return 0;
}