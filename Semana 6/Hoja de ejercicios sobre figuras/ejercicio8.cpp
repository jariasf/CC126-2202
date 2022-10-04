#include <iostream>
using namespace std;

int ingresarNumero();
void imprimirEspacios(int);
void imprimirFigura(int);

int main() {
    int n = ingresarNumero();
    imprimirFigura(n);
    return 0;
}

int ingresarNumero() {
    int n;
    do {
        cout << "Ingrese el valor N: ";
        cin >> n;
    } while (!(n > 0 && n < 10));
    return n;
}

void imprimirEspacios(int n) {
    for (int i = 0; i < n; ++i) {
        cout << " ";
    }
}

void imprimirFigura(int n) {
    int num_espacios = 40 - n / 2;
    for (int fila = 1; fila <= n; ++fila) {
        // Espacios para centrar
        imprimirEspacios(num_espacios);
        // La figura fila por fila
        for (int columna = 1; columna <= fila; ++columna) {
            if (columna == 1 || fila == n || fila == columna) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}