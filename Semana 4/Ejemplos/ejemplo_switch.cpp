#include <iostream>
using namespace std;

/*
Solicite un numero entero y devuelva el dia de la semana 
1 -> Lunes, 2 -> Martes ..., 7 -> Domingo
*/

int main() {
    short* num_dia = new short;
    cout << "Ingrese un numero: ";
    cin >> *num_dia;

    switch (*num_dia) {
        case 1: cout << "Lunes\n";
                break;
        case 2: cout << "Martes\n";
                break;
        case 3: cout << "Miercoles\n";
                break;
        case 4: cout << "Jueves\n";
                break;
        case 5: cout << "Viernes\n";
                break;
        case 6: cout << "Sabado\n";
                break;
        case 7: cout << "Domingo\n";
                break;
        default: cout << "El numero ingresado es invalido\n";                
    }

    delete num_dia;
	return 0;
}