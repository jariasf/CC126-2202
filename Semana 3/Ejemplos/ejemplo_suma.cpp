#include <iostream>
using namespace std;

int sumar(int x1, int x2) {
    int suma = x1 + x2;
    return suma;
    //return x1 + x2; //Tambi�n es v�lido
}

int main() {
    int numero1, numero2, resultado;
    cout << "Ingrese el primer numero: ";
    cin >> numero1;
    cout << "Ingrese el segundo numero: ";
    cin >> numero2;
    resultado = sumar(numero1, numero2);
    cout << "La suma de los numeros es " << resultado << endl;
    return 0;
}