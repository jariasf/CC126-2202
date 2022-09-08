#include <iostream>
using namespace std;

bool esPar(int* numero) {
    return *numero % 2 == 0;
}

int main() {
    int* numero = new int;
    cout << "Ingrese un numero: ";
    cin >> *numero;

    if (esPar(numero)) {
        cout << "El numero es par\n";
    }
    else {
        cout << "El numero es impar\n";
    }
    delete numero;
    return 0;
}