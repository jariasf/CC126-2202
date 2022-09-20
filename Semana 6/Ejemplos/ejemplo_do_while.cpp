#include <iostream>
using namespace std;

/*
Ingresar un numero y validar que sea positivo y menor a 100, debe permitir el ingreso mientras
la expresion no sea verdadera
Ejemplo:
Ingrese un numero: 123
Ingreso invalido, intente nuevamente
Ingrese un numero: -5
Ingreso invalido, intente nuevamente
Ingrese un numero: 45
El numero ingresado es 45
*/

int ingresarNumero() {
    int numero;
    do {
        cout << "Ingrese un numero: ";
        cin >> numero;
        if (numero <= 0 || numero >= 100) {
            cout << "Ingreso invalido, intente nuevamente\n";
        }
    } while (numero <= 0 || numero >= 100);
    return numero;
}

bool esNumeroInvalido(int numero) {
    return numero <= 0 || numero >= 100;
}

int ingresarNumeroUsandoFunciones() {
    int numero;
    do {
        cout << "Ingrese un numero: ";
        cin >> numero;
        if (esNumeroInvalido(numero)) {
            cout << "Ingreso invalido, intente nuevamente\n";
        }
    } while (esNumeroInvalido(numero));
    return numero;
}

int ingresarNumeroNegarVerdad() {
    int numero;
    do {
        cout << "Ingrese un numero: ";
        cin >> numero;
        if (!(numero > 0 && numero < 100)) {
            cout << "Ingreso invalido, intente nuevamente\n";
        }
    } while (!(numero > 0 && numero < 100));
    return numero;
}

int main() {
    int numero = ingresarNumeroNegarVerdad();
    cout << "El numero ingresado es " << numero << endl;
    return 0;
}