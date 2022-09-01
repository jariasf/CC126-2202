#include<iostream>
using namespace std;

// TODO: Implementar función que retorne el mayor de dos números enteros
// 23 5 -> 23
// 5 23 -> 23
int calcularMayor(int numero1, int numero2) {
    bool es_mayor1, es_mayor2;
    int mayor;
    es_mayor1 = (numero1 > numero2);
    es_mayor2 = !es_mayor1; // (numero2 >= numero1);
    // R = C1 * R1 + C2 * R2 + C3 * R3
    // numero1 = 23, numero2 = 5
    // R = 1 * 23 + 0 * 5 = 23
    mayor = es_mayor1 * numero1 + es_mayor2 * numero2;
    return mayor;
}

int main() {
    int numero1, numero2, mayor;
    cout << "Ingrese el primer numero: ";
    cin >> numero1;
    cout << "Ingrese el segundo numero: ";
    cin >> numero2;
    mayor = calcularMayor(numero1, numero2);
    cout << "El mayor es " << mayor;
    return 0;
}