#include <iostream>
using namespace std;

int main() {
    int* numero = new int;
    bool* es_positivo = new bool;

    cout << "Ingrese un numero: ";
    cin >> *numero;

    // Operadores de relaciones: <, >, ==, >=, <=, !=
    *es_positivo = (*numero > 0);
    cout << "El numero ingresado es " << *es_positivo << endl;

    delete numero;
    delete es_positivo;
    return 0;
}