#include <iostream>
using namespace std;
// TODO: Calcular el producto y division usando parametros por referencia
void calcularOperacionesBasicas(int num1, int num2, int& multiplicacion, double &division) {
    multiplicacion = num1 * num2;
    division = (double)num1 / num2;
}

int main() {
    int num1, num2, multiplicacion;
    double division;
    cout << "Ingrese 2 numeros: ";
    cin >> num1 >> num2;
    calcularOperacionesBasicas(num1, num2, multiplicacion, division);
    cout << "El producto es " << multiplicacion << endl;
    cout << "La division es " << division << endl;
    return 0;
}