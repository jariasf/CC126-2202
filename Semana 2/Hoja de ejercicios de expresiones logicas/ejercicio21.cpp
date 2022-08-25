#include <iostream>
using namespace std;

int main() {

    int* numero = new int;
    bool* es_positivo = new bool, * es_negativo = new bool, * es_neutro = new bool;

    cout << "Ingrese un numero entero: ";
    cin >> *numero;

    *es_positivo = (*numero > 0);
    *es_negativo = (*numero < 0);
    *es_neutro = !*es_positivo && !*es_negativo;
    //*es_neutro = (*numero == 0);

    cout << "Es positivo: " << *es_positivo << endl;
    cout << "Es negativo: " << *es_negativo << endl;
    cout << "Es neutro: " << *es_neutro << endl;

    delete numero;
    delete es_positivo;
    delete es_negativo;
    delete es_neutro;
    return 0;
}