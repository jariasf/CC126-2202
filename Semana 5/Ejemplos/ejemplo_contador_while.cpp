#include <iostream>
using namespace std;
/*
Escribir un programa que permita imprimir los cinco primeros numeros positivos
*/

void imprimirCincoPrimerosNumeros() {
    int* n1 = new int, * n2 = new int, * n3 = new int, * n4 = new int, * n5 = new int;
    *n1 = 1; *n2 = 2; *n3 = 3; *n4 = 4; *n5 = 5;

    cout << *n1 << endl;
    cout << *n2 << endl;
    cout << *n3 << endl;
    cout << *n4 << endl;
    cout << *n5 << endl;

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
}

void imprimirPrimerosNumeros(int *n) {
    int* contador = new int;
    *contador = 1;
    while (*contador <= *n) {
        // Mientras la expresion logica sea verdadera
        // Se ejecuta este bloque de instrucciones
        cout << *contador << endl;
        (*contador)++; //*contador = *contador + 1;
    }
    //cout << "Fin de ciclo\n";
    delete contador;
}

int main() {
    //imprimirCincoPrimerosNumeros();
    int* n = new int;
    cout << "Ingrese el numero N: ";
    cin >> *n;
    imprimirPrimerosNumeros(n);
    delete n;
    return 0;
}