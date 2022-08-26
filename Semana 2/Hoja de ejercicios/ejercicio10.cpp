#include <iostream>
using namespace std;

int main() {

    short* anhos = new short;
    char* estudios = new char;
    bool* es_menor5 = new bool;
    bool* es_mayor5 = new bool;
    short* puntaje_antiguedad = new short;
    bool* primario = new bool, * secundario = new bool, * universitario = new bool, * posgrado = new bool;
    short* puntaje_estudios = new short;
    short* puntaje_total = new short;

    cout << "Ingrese la cantidad de años que labora: ";
    cin >> *anhos;
    cout << "Estudios (P: primaria; S: secundaria; U: universitario; G: posgrado): ";
    cin >> *estudios;

    // Hallar puntaje por cantidad años que labora
    *es_menor5 = (*anhos < 5);
    *es_mayor5 = (*anhos >= 5);
    // R = C1 * R1 + C2 * R2
    *puntaje_antiguedad = *es_menor5 * 5 + *es_mayor5 * 10;

    // Hallar puntaje por el tipo de estudios
    *primario = (*estudios == 'P');
    *secundario = (*estudios == 'S');
    *universitario = (*estudios == 'U');
    *posgrado = (*estudios == 'G');
    // R = C1 * R1 + C2 * R2 + C3 * R3 + C4 * R4
    *puntaje_estudios = *primario * 5 + *secundario * 10 + *universitario * 20 + *posgrado * 30;

    // Hallar el puntaje total
    *puntaje_total = *puntaje_antiguedad + *puntaje_estudios;

    cout << "Puntaje Obtenido: " << *puntaje_total << endl;

    // Liberar memoria
    delete anhos;
    delete estudios;
    delete es_menor5;
    delete es_mayor5;
    delete puntaje_antiguedad;
    delete primario;
    delete secundario;
    delete universitario;
    delete posgrado;
    delete puntaje_estudios;
    delete puntaje_total;
	return 0;
}