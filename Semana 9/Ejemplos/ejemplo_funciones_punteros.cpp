#include <iostream>
using namespace std;

int ingresarValor() {
    int numero;
    do {
        cout << "Ingrese un numero: ";
        cin >> numero;
    } while (numero <= 0);
    return numero;
}

int* ingresarValorPuntero() {
    /*
    numero es un puntero a un entero y almacena direcciones
    *numero es un entero, es el bloque de memoria al que numero apunta
    */
    int* numero = new int;
    do {
        cout << "Ingrese un numero: ";
        cin >> *numero;
    } while (*numero <= 0);
    return numero;
}

int eliminarMemoriaDentroDeFuncion() {
    int* ptr1 = new int;
    char* ptr2 = new char;
    int suma{ 0 };

    delete ptr1;
    delete ptr2;
    return suma;
}


int main() {    
    // int* = int*
    int *numero = ingresarValorPuntero();
    cout << "El numero es: " << *numero << endl;
    // Memoria se elimina fuera de la función
    delete numero;
    numero = nullptr;
    return 0;
}