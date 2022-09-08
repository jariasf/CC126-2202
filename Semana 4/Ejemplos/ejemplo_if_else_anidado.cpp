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
        // Si se cumple la condición ejecutamos este bloque
        cout << "El numero es positivo\n";
    }
    else {
        // Si no se cumple la condición ejecutamos este bloque
        if (*numero < 0) {
            cout << "El numero es negativo\n";
        }
        else {
            cout << "El numero es cero\n";
        }
    }
    delete numero;
    return 0;
}