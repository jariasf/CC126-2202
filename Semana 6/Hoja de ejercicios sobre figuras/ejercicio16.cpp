#include <iostream>
using namespace std;

int ingresarNumero() {
    int n;
    do {
        cout << "Ingrese un numero: ";
        cin >> n;
    } while (n < 1 || n > 5);
    return n;
}

void imprimirEspacios(int num_espacios) {
    for (int i = 1; i <= num_espacios; ++i)
        cout << " ";
}

void imprimirFila(int fila, int n) {
    int num_columnas = 2 * fila - 1;
    imprimirEspacios(n - fila);
    for (int columna = 1; columna <= num_columnas; ++columna) {
        cout << columna;
    }
    cout << endl;
}

void imprimirFiguraFunciones(int n) {
    for (int i = 1; i <= n; ++i)
        imprimirFila(i,n);

    for (int i = n - 1; i >= 1; --i) 
        imprimirFila(i, n);
}

void imprimirFigura(int n) {
    // Parte Superior
    /*
    n=3
      1
     123
    12345
    */
    for (int i = 1; i <= n; ++i) {
        imprimirEspacios(n - i);
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << j;
        }
        cout << endl;
    }

    /*
     123
      1
    */
    for (int i = n - 1; i >= 1; --i) {
        imprimirEspacios(n - i);
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << j;
        }
        cout << endl;
    }
}

int main() {

    int n = ingresarNumero();
    imprimirFigura(n);

    return 0;
}