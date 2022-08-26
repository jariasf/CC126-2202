#include <iostream>
using namespace std;

int main() {

    char* modelo = new char;
    char* color = new char;
    short* edad = new short;
    bool* cond1 = new bool, * cond2 = new bool, * cond3 = new bool;
    bool* cond4 = new bool, * cond5 = new bool, * cond6 = new bool;
    double* precio = new double, * porcentaje = new double, *incremento = new double;

    cout << "Ingrese el modelo: ";
    cin >> *modelo;
    cout << "Color (B: blanco; M: metalizado; O: otros): ";
    cin >> *color;
    cout << "Edad: ";
    cin >> *edad;

    // 1. Hallar el precio usando el modelo y color
    *cond1 = (*modelo == 'A' && *color == 'B');
    *cond2 = (*modelo == 'A' && *color == 'M');
    *cond3 = (*modelo == 'A' && *color == 'O');
    *cond4 = (*modelo == 'B' && *color == 'B');
    *cond5 = (*modelo == 'B' && *color == 'M');
    *cond6 = (*modelo == 'B' && *color == 'O');
    *precio = *cond1 * 240.5 + *cond2 * 330 + *cond3 * 270.5 + *cond4 * 300 + *cond5 * 360.5 + *cond6 * 330;

    // 2. Hallar el porcentaje usando la edad
    *cond1 = (*edad < 31);
    *cond2 = (*edad >= 31 && *edad <= 65);
    *cond3 = (*edad > 65);
    *porcentaje = *cond1 * 0.25 + *cond2 * 0 + *cond3 * 0.1;

    // 3. Hallar el incremento usando el precio y porcentaje
    *incremento = *precio * *porcentaje;

    // 4. Hallar el precio total usando el precio inicial y el incremento
    *precio = *precio + *incremento;

    cout << "Precio del seguro: " << *precio << endl;

    delete modelo;
    delete color;
    delete edad;
    delete cond1;
    delete cond2;
    delete cond3;
    delete cond4;
    delete cond5;
    delete cond6;
    delete precio;
    delete incremento;
    return 0;
}