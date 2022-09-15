#include <iostream>
using namespace std;
/*
S = 1 + 4 + 9 + 16 + 25 + ... + n^2

S = sum_{i=1}^{n} i^2
*/
int calcularSumatoria(int n) {
    int i, termino, suma;
    i = 1;
    suma = 0;
    cout << "Los terminos son: ";
    while (i <= n) {
        termino = i*i;
        cout << termino << " ";
        suma += termino;
        ++i;
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