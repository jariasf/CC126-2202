#include <iostream>
using namespace std;

// 6 5 4
// 4 5 6
// 5 6 2
int calcularMayorDe3(int num1, int num2, int num3) {
    bool es_mayor1, es_mayor2, es_mayor3;
    int mayor;
    es_mayor1 = (num1 > num2 && num1 > num3);
    es_mayor2 = (num2 > num1 && num2 > num3);
    es_mayor3 = !es_mayor1 && !es_mayor2; // (num3 > num2 && num3 > num1);
    mayor = es_mayor1 * num1 + es_mayor2 * num2 + es_mayor3 * num3;
    return mayor;
}

int main() {
    int num1, num2, num3, mayor;
    cout << "Ingrese tres números: ";
    cin >> num1 >> num2 >> num3;
    mayor = calcularMayorDe3(num1, num2, num3);
    cout << "El mayor es " << mayor << endl;
    return 0;
}