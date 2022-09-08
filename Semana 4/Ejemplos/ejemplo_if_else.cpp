#include <iostream>
using namespace std;
/*
Ingrese un numero y verifique si el numero ingresado es positivo o negativo
*/

int main() {
    int* numero = new int;
    cout << "Ingrese un numero: ";
    cin >> *numero;

    if (*numero > 0) {
        // Si se cumple la condición ejecutamos este bloque
        cout << "El numero es positivo\n";
    } else {
        // Si no se cumple la condición ejecutamos este bloque
        cout << "El numero es negativo\n";
    }

    delete numero;
    return 0;
}