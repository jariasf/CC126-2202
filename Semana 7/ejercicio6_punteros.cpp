#include <iostream>
using namespace std;

/*
Realice una aplicación en C++ que solicite el ingreso de un número entero, positivo y menor
a 10 (N) y muestre un cuadrado completo de lado N.
*/

int* ingresarNumero();
void imprimirCuadrado(int*);
void imprimirEspacios(int*);
void imprimirGrafica(int*);

int main() {
    int* n = ingresarNumero();
    imprimirGrafica(n);
    delete n;
    return 0;
}

int* ingresarNumero() {
    int* numero = new int;
    do {
        cout << "Ingresar un numero: ";
        cin >> *numero;
    } while (!(*numero >= 1 && *numero < 15));
    return numero;
}

void imprimirEspacios(int *num_espacios) {
    int* i = new int;
    for (*i = 1; *i <= *num_espacios; ++(*i)) {
        cout << " ";
    }
    delete i;
}

void imprimirCuadrado(int* n) {
    int* num_espacios = new int{ 40 };
    // Inicializamos fuera de los for para luego poder usar delete
    int* i = new int, *j = new int;
    for (*i = 1; *i <= *n; ++(*i) ) {
        imprimirEspacios(num_espacios);
        for (*j = 1; *j <= *n; ++(*j)) {
            if (*i == 1 || *i == *n || *j == 1 || *j == *n) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    delete i;
    delete j;
    delete num_espacios;
}

void imprimirGrafica(int* n) {
    int* i = new int;
    for (*i = 1; *i <= *n; ++(*i)) {
        imprimirCuadrado(i);
    }
    delete i;
}