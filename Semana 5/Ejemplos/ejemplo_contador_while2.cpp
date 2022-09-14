#include <iostream>
using namespace std;
/*
 Dado un numero n, generar los valores desde n hasta 1 (orden decreciente)
 n = 7 -> mostrar 7,6,5,4,3,2,1
 Entrada:
 Ingrese un numero N: 7
 Salida:
 7
 6
 5
 4
 3
 2
 1
*/

void imprimirNumerosDecreciente(int *n) {
    while ( *n >= 1 ) {
        cout << *n << endl;
        //*n = *n - 1;
        (*n)--;
    }
}

int main() {
    int* n = new int;
    cout << "Ingrese el numero N: ";
    cin >> *n;
    imprimirNumerosDecreciente(n);
    delete n;
    return 0;
}