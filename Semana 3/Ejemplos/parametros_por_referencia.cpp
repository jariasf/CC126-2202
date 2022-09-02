#include <iostream>
using namespace std;

// Variable de referencia int &a = x;
void incrementar(int &x) {
    cout << "La direccion de memoria de x dentro de la funcion es " << &x << endl;
    x = x + 1;
    cout << "El valor de x dentro de la funcion es " << x << endl;
}

int main() {
    //int variable_normal{ 45 };
    //int& variable_referencia = variable_normal;
    int x;
    cout << "Ingrese el valor de x: ";
    cin >> x;
    cout << "La direccion de memoria de x es " << &x << endl;
    cout << "El valor de x antes de llamar a la funcion es " << x << endl;
    incrementar(x);
    cout << "El valor de x despues de llamar a la funcion es " << x << endl;
    return 0;
}