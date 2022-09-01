#include <iostream>
using namespace std;

// Dado un monto calcular el descuento considerando que por encima de 10000 
// el descuento es el 20 % y menor o igual que 10000 el descuento es el 10 % .
double calcularDescuento(double monto) {
    double descuento;
    bool es_mayor10000, es_menor10000;
    es_mayor10000 = (monto > 10000);
    es_menor10000 = !es_mayor10000;
    descuento = es_mayor10000 * (monto * 0.2) + es_menor10000 * (monto * 0.1);
    return descuento;
}

int main() {
    double monto, descuento;
    cout << "Ingresar el monto: ";
    cin >> monto;
    descuento = calcularDescuento(monto);
    cout << "El descuento es " << descuento << endl;
    return 0;
}