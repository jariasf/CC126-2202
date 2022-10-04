#include <iostream>
using namespace std;

int ingresarNumero();
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

void imprimirFigura(int n) {
    for (int fila = 1; fila <= n; ++fila) {
        for (int columna = 1; columna <= fila; ++columna) {
            if ( columna == 1 || fila == n || fila == columna ) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}