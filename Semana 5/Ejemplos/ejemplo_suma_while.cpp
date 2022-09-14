#include <iostream>
using namespace std;
/*
Escribir un programa que permita calcular la suma de los n primeros numeros positivos
Entrada 1:
Ingrese el numero de N: 3
Salida 1:
La suma de los 3 primeros numeros es 6 
Explicacion: 1,2,3 -> 1 + 2 + 3 = 6

Entrada 2:
Ingrese el numero de N: 5
Salida 2:
La suma de los 5 primeros numeros es 15
Explicacion: 1,2,3,4,5 -> 1 + 2 + 3 + 4 + 5 = 15

*/

int* calcularSumaDePrimerosNumeros(int *n) {
    // Declaracion
    int* contador = new int;
    int* suma = new int;
    // Inicializacion
    *contador = 1;
    *suma = 0;

    while (*contador <= *n) {
        *suma = *suma + *contador;
        //cout << "Contador = " << *contador << ", Suma = " << *suma << endl;
        (*contador)++;
    }
    delete contador;
    return suma;
}

int main() {
    int* n = new int;
    cout << "Ingrese el numero N: ";
    cin >> *n;
    int* suma = calcularSumaDePrimerosNumeros(n);
    cout << "La suma es " << *suma << endl;
    delete suma;
    return 0;
}