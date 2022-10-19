#include <iostream>
#include <cstdlib>
using namespace std;

int nextInt(int, int);
int nextInt(int);
int ingresarNumeroAlumnos();

int main() {
    srand(time(NULL));
    //srand(10);
    int numero_alumnos;
    int* edades;

    // Ingreso de datos
    numero_alumnos = ingresarNumeroAlumnos();
    edades = new int[numero_alumnos];

    for (int i = 0; i < numero_alumnos; ++i) {
        edades[i] = nextInt(1, 100);
    }

    // Mostrar elementos del arreglo
    cout << "Edades de alumnos" << endl;
    for (int i = 0; i < numero_alumnos; ++i) {
        cout << "Edad[" << i << "] = " << edades[i] << endl;
    }

    // Sumar los elementos del arreglo
    int suma{0};
    for (int i = 0; i < numero_alumnos; ++i) {
        suma = suma + edades[i];
    }
    cout << "\nLa suma de edades es: " << suma << endl;


    // Hallar el mayor elemento
    int maximo = edades[0];
    for (int i = 1; i < numero_alumnos; ++i) {
        if (edades[i] > maximo) {
            maximo = edades[i];
        }
    }
    cout << "\nLa edad mayor es: " << maximo << endl;
    
    // Busqueda de la edad de un alumno
    int edad;
    bool encontrado{false};
    cout << "\nIngrese edad a buscar: ";
    cin >> edad;
    for (int i = 0; i < numero_alumnos; ++i) {
        if (edad == edades[i]) {
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        cout << "Alumno con edad " << edad << " fue encontrado" << endl;
    }
    else {
        cout << "Alumno con edad " << edad << " no fue encontrado" << endl;
    }


    delete[]edades;

    return 0;
}

int nextInt(int max) { // Entre 0 y max inclusive
    return rand() % (max + 1);
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

int ingresarNumeroAlumnos() {
    int numero_alumnos;
    do {
        cout << "Ingrese el número de alumnos: ";
        cin >> numero_alumnos;
    } while (numero_alumnos <= 0);
    return numero_alumnos;
}