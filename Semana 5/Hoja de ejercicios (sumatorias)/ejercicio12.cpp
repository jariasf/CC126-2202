#include <iostream>
using namespace std;

/*
S = 1! + 2! + 3! + 4! + 5! + ...
t = 1! , 2!,  3!,  4!,  5!
i = 1 ,  2,   3,   4
S = sum_{i=1}^{n} i!
*/
int factorial(int n) {
    int prod = 1;
    int i = 1;
    while (i <= n) {
        prod = prod * i;
        ++i;
    }
    return prod;
}

int calcularSumatoria(int n) {
    int i = 1, suma = 0, termino;
    cout << "Los terminos son: ";
    while (i <= n) {
        termino = factorial(i);
        cout << termino << " ";
        suma = suma + termino;
        ++i;
    }
    cout << endl;
    return suma;
}

int calcularSumatoria2(int n) {
    int i = 1, suma = 0;
    int fact = 1;
    cout << "Los terminos son: ";
    while (i <= n) {
        fact = fact * i;
        cout << fact << " ";
        suma = suma + fact;
        ++i;
    }
    cout << endl;
    return suma;
}

int main() {
    int n;
    cout << "Cantidad de terminos: ";
    cin >> n;
    // Debe validar que n sea un número positivo y menor a 13.
    if (n > 0 && n < 13) {
        cout << "La suma es: " << calcularSumatoria(n)<<endl;
    }
    else {
        cout << "Ingreso invalido\n";
    }
    return 0;
}