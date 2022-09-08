#include <iostream>
using namespace std;
/*
Ingrese un numero y verifique si el numero ingresado es positivo, negativo o neutro
*/

int main() {
    int* numero = new int;
    cout << "Ingrese un numero: ";
    cin >> *numero;

    if (*numero > 0) {
        cout << "El numero es positivo\n";
    }
    else if (*numero < 0) {
        cout << "El numero es negativo\n";
    }
    else {
        cout << "El numero es cero\n";
    }
    delete numero;
    return 0;
}