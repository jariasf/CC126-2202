#include <iostream>
using namespace std;

int main() {
    short* edad = new short;
    bool* esta_en_rango = new bool;
    bool* no_esta_en_rango = new bool;

    cout << "Ingrese la edad: ";
    cin >> *edad;

    *esta_en_rango = (*edad >= 1 && *edad <= 18);
    *no_esta_en_rango = !*esta_en_rango;

    cout << "Esta en el rango entre 1 y 18: " << *esta_en_rango << endl;
    cout << "No esta en el rango entre 1 y 18: " << *no_esta_en_rango << endl;

    delete edad;
    delete esta_en_rango;
    delete no_esta_en_rango;
    return 0;
}