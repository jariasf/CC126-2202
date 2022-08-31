#include <iostream>
using namespace std;

double calcularPromedio(int numero1, int numero2, int numero3) {
    // entero/entero -> entero
    // double/entero -> double
    // entero/double -> double
    // double/double -> double
    double promedio = numero1 + numero2 + numero3 / 3.0;
    return promedio;
}

int main() {
    int numero1, numero2, numero3;
    double promedio;
    cout << "Ingrese tres números: ";
    cin >> numero1 >> numero2 >> numero3;
    promedio = calcularPromedio(numero1, numero2, numero3);
    cout << "El promedio es " << promedio << endl;
    return 0;
}