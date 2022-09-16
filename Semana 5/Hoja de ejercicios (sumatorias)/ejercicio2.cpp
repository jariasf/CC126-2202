#include <iostream>
using namespace std;
/*
S = 1 - 2 + 3 - 4 + 5 ...
*/

int calcularSumatoria(int n) {
    int suma, i, termino, signo;
    // Inicializacion
    suma = 0;
    i = 1;
    signo = 1;
    // Proceso
    cout << "Los terminos son: ";
    while (i <= n) {
        termino = signo * i;
        cout << termino << " ";
        suma += termino;
        signo = signo * -1;
        ++i;
    }
    cout << endl;
    return suma;
}


int main() {
    int n, suma;
    cout << "Cantidad de terminos: ";
    cin >> n;
    if (n > 0) {
        suma = calcularSumatoria(n);
        cout << "La suma es: " << suma << endl;
    }
    else {
        cout << "Ingreso invalido\n";
    }
    return 0;
}