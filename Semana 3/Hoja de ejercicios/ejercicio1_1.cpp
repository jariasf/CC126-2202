#include <iostream>
using namespace std;

int calcularMayorDe2(int numero1, int numero2) {
	bool es_mayor1, es_mayor2;
	int mayor;
	es_mayor1 = (numero1 > numero2);
	es_mayor2 = !es_mayor1;
	mayor = es_mayor1 * numero1 + es_mayor2 * numero2;
	return mayor;
}

int calcularMayorDe3(int num1, int num2, int num3) {
	int mayor2 = calcularMayorDe2(num1, num2);
	return calcularMayorDe2(mayor2, num3);
}

int main() {
	int num1, num2, num3, mayor;
	cout << "Ingrese tres números: ";
	cin >> num1 >> num2 >> num3;
	mayor = calcularMayorDe3(num1, num2, num3);
	cout << "El mayor es " << mayor << endl;
	return 0;
}