#include <iostream>
using namespace std;

int main() {
	
    // Lectura basica
    int* numero = new int;
    cout << "Ingrese un numero: "; //pseint_ escribir sin salto
    cin >> *numero; //pseint: leer numero
    cout << "El numero ingresado es: " << *numero << endl;

    // Lectura continua
    int* numero1 = new int, * numero2 = new int;

    cout << "\n\nIngrese dos numeros: ";
    cin >> *numero1 >> *numero2;
    cout << "Los numeros ingresados son: " << *numero1 << " " << *numero2 << endl;

    cout << "\n\nIngrese el primero numero: ";
    cin >> *numero1;
    cout << "Ingrese el segundo numero: ";
    cin >> *numero2;
    cout << "Los numeros ingresados son: " << *numero1 << " " << *numero2 << endl;

    delete numero;
    delete numero1;
    delete numero2;

    return 0;
}