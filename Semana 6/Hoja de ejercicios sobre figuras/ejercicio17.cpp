#include <iostream>
using namespace std;

int ingresarNumero() {
    int n;
    do {
        cout << "Ingrese un numero: ";
        cin >> n;
    } while (n < 1 || n > 9);
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
        imprimirFila(i, n);

    for (int i = n - 1; i >= 1; --i)
        imprimirFila(i, n);
}

/*
j=1 -> A=65 = j+64
j=2 -> B=66 = j+64
j=3 -> C=67 = j+64
j=4 -> D=68 = j+64
*/

void imprimirFigura(int n) {
    // Parte Superior
    /*
    n=3
      1
     123
    12345
    */
    int ancho_figura = 2 * n - 1;
    int espacios_centrar = 40 - ancho_figura/2;
    //char letra;
    //'A' = 65
    for (int i = 1; i <= n; ++i) {
        imprimirEspacios(espacios_centrar);
        imprimirEspacios(n - i);
        //letra = 'A';
        for (int j = 1; j <= 2 * i - 1; ++j) {
            //cout << char(j + 64);
            cout << char(j + 'A' - 1);
            //letra++;
        }
        cout << endl;
    }

    /*
     123
      1
    */
    for (int i = n - 1; i >= 1; --i) {
        imprimirEspacios(espacios_centrar);
        imprimirEspacios(n - i);
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << char(j + 'A' - 1);
        }
        cout << endl;
    }
}

int main() {
    //cout << (int)'A' << endl;
    int n = ingresarNumero();
    imprimirFigura(n);

    return 0;
}