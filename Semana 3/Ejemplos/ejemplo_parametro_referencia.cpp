#include <iostream>
using namespace std;

void calcularOperacionesBasicas(int num1, int num2, int &suma, int &resta) {
    // Hallar la suma
    suma = num1 + num2;
    // Hallar la resta
    resta = num1 - num2;
}

int main() {
    int num1, num2, suma, resta;
    cout << "Ingrese 2 numeros: ";
    cin >> num1 >> num2;
    calcularOperacionesBasicas(num1, num2, suma, resta);
    cout << "La suma es " << suma << endl;
    cout << "La resta es " << resta << endl;
    return 0;
}