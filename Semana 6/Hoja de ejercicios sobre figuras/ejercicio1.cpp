#include <iostream>
using namespace std;

/*
Realice una aplicación en C++ que solicite el ingreso de un número entero, positivo y menor
a 10 (N) y muestre un cuadrado completo de lado N.
*/

int ingresarNumero();
void imprimirCuadrado(int);

int main() {
    int n = ingresarNumero();
    imprimirCuadrado(n);
    return 0;
}

int ingresarNumero() {
    int numero;
    do {
        cout << "Ingresar N: ";
        cin >> numero;
    } while ( numero <= 0 || numero >= 10 );
    return numero;
}

void imprimirCuadrado(int n) {
    // Bucles anidados
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}