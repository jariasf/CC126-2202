#include <iostream>
using namespace std;

int main() {
    /*
    Ingresar el sexo de una persona en forma de caracter y su edad, verificar si se trata 
    de una persona del sexo masculino con una edad menor o igual a 18 años
    */
    char* sexo = new char;
    short* edad = new short;
    bool* es_valido = new bool;

    cout << "Ingrese el sexo (M:masculino, F:femenino): ";
    cin >> *sexo;
    cout << "Ingrese la edad: ";
    cin >> *edad;

    *es_valido = (*sexo == 'M' && *edad <= 18);

    cout << "La persona es de sexo masculino con edad menor o igual a 18 años: " << *es_valido << endl;

    delete sexo;
    delete edad;
    delete es_valido;
    return 0;
}