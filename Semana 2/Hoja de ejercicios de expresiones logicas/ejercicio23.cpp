#include <iostream>
using namespace std;

int main() {
    /*
    Ingresar un caracter e imprima si este es un dígito o una letra mayúscula o letra
    minúscula u otro carácter. Recuerde que los dígitos se encuentran en el rango de 48 a
    57, las letras mayúsculas están en el rango de 65 a 90 y las letras minúsculas están en
    el rango de 97 a 122. Puede usar varias variables booleanas para almacenar los
    resultados y luego mostrarlos.
	*/

    char* caracter = new char;
    bool* es_digito = new bool;
    bool* es_mayuscula = new bool;
    bool* es_minuscula = new bool;
    bool* es_otro_caracter = new bool;

    cout << "Ingrese un caracter: ";
    cin >> *caracter;
    /*
    caracter = '0'; // 48
    caracter = '1'; // 49
    caracter = '2'; // 50
    ...
    caracter = '9'; // 57
    */
    *es_digito = (*caracter >= '0' && *caracter <= '9');
    *es_minuscula = (*caracter >= 'a' && *caracter <= 'z');
    *es_mayuscula = (*caracter >= 'A' && *caracter <= 'Z');
    *es_otro_caracter = !*es_digito && !*es_minuscula && !*es_mayuscula;

    cout << "Es digito: " << *es_digito << endl;
    cout << "Es mayuscula: " << *es_mayuscula << endl;
    cout << "Es minuscula: " << *es_minuscula << endl;
    cout << "Es otro caracter: " << *es_otro_caracter << endl;

    delete caracter;
    delete es_digito;
    delete es_mayuscula;
    delete es_minuscula;
    delete es_otro_caracter;
    return 0;
}