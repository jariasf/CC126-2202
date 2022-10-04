#include <iostream>
using namespace std;

/*
Realice una aplicación en C++ que solicite el ingreso de un número entero, positivo y menor
a 10 (N) y muestre un cuadrado completo de lado N.
*/

int ingresarNumero();
void imprimirCuadrado(int);
void imprimirEspacios(int);

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
    } while (numero <= 0 || numero >= 10);
    return numero;
}

void imprimirEspacios(int num_espacios) {
    for (int i = 1; i <= num_espacios; ++i) {
        cout << " ";
    }
}

void imprimirCuadrado(int n) {
    int num_espacios = 40 - n / 2;
    for (int i = 1; i <= n; ++i) {
        imprimirEspacios(num_espacios);
        for (int j = 1; j <= n; ++j) {
            if (i == 1 || i == n || j == 1 || j == n) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}