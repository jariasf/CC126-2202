#include <iostream>
using namespace std;

/*

TODO: Edades estarán entre 16 y 50
 
Entrada:
Ingrese el numero de alumnos: -1
Ingrese el numero de alumnos: 3
Ingrese la edad del alumno 1: 12
Ingrese la edad del alumno 2: 1
Ingrese la edad del alumno 3: 25

Salida:
Edad del alumno 1: 12
Edad del alumno 2: -1
Edad del alumno 2: 1
Edad del alumno 3: 25

*/

int ingresarNumeroAlumnos();

int main() {
     
    int numero_alumnos;
    int* edades;

    // Ingreso de datos
    numero_alumnos = ingresarNumeroAlumnos();
    edades = new int[numero_alumnos];

    for (int i = 0; i < numero_alumnos; ++i) {
        cout << "Ingrese la edad del alumno "<<i+1<<": ";
        cin >> edades[i];
    }

    // Mostrar elementos del arreglo
    for (int i = 0; i < numero_alumnos; ++i) {
        cout << "Edad del alumno "<<i+1<<": " << edades[i] << endl;
    }

    // Liberar memoria
    delete[]edades;
    return 0;
}

int ingresarNumeroAlumnos() {
    int numero_alumnos;
    do {
        cout << "Ingrese el número de alumnos: ";
        cin >> numero_alumnos;
    } while ( numero_alumnos <= 0);
    return numero_alumnos;
}