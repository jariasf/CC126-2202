#include <iostream>
using namespace std;

int elevarAlCuadrado(int numero) {
    return numero * numero;
}

void imprimirLinea() {
    cout << "------------------------\n";
}

int main() {
    int numero, numero_al_cuadrado, numero_cuarta;
    cout << "Ingrese un numero: ";
    cin >> numero; // 10
    numero_al_cuadrado = elevarAlCuadrado(numero);	// 100
    cout << "El numero al cuadrado es " << numero_al_cuadrado << endl;

    numero_cuarta = elevarAlCuadrado(numero_al_cuadrado); //10000
    cout << "El numero a la cuarta es " << numero_cuarta << endl;

    imprimirLinea();
    return 0;
}