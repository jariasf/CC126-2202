#include <iostream>
using namespace std;

int ingresarNumeroAlumnos();
int nextInt(int,int);
void generarEdadesAleatorias(int*, int);
void mostrarEdades(int*, int);
int calcularSumaEdades(int*, int);
int hallarMayorEdad(int*, int);
bool buscarElemento(int*, int, int);

int main() {
    srand(time(NULL));
    int numero_alumnos, suma, mayor_edad, edad;
    int* edades;

    // Ingreso de datos
    numero_alumnos = ingresarNumeroAlumnos();
    edades = new int[numero_alumnos];

    generarEdadesAleatorias(edades, numero_alumnos);
    mostrarEdades(edades, numero_alumnos);

    // Sumar los elementos del arreglo
    suma = calcularSumaEdades(edades, numero_alumnos);
    cout << "\nLa suma de edades es: " << suma << endl;

    // Hallar el mayor elemento
    mayor_edad = hallarMayorEdad(edades, numero_alumnos);
    cout << "\nLa edad mayor es: " << mayor_edad << endl;

    // Busqueda de la edad de un alumno
    cout << "\nIngrese edad a buscar: ";
    cin >> edad;
    if (buscarElemento(edades, numero_alumnos, edad)) {
        cout << "Alumno con edad " << edad << " fue encontrado" << endl;
    }
    else {
        cout << "Alumno con edad " << edad << " no fue encontrado" << endl;
    }
    delete[] edades;
    return 0;
}

int ingresarNumeroAlumnos() {
    int numero_alumnos;
    do {
        cout << "Ingrese el número de alumnos: ";
        cin >> numero_alumnos;
    } while (numero_alumnos <= 0);
    return numero_alumnos;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarEdadesAleatorias(int *edades, int n) {
    for (int i = 0; i < n; ++i) {
        edades[i] = nextInt(1, 100);
        //*(edades + i) = nextInt(1, 100);
    }
}

void mostrarEdades(int *edades, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Edad[" << i << "] = " << edades[i] << endl;
    }
}

int calcularSumaEdades(int *edades, int n) {
    int suma{0};
    for (int i = 0; i < n; ++i) {
        suma = suma + edades[i];
    }
    return suma;
}

int hallarMayorEdad(int* edades, int n) {
    int maximo = edades[0];
    for (int i = 1; i < n; ++i) {
        if (edades[i] > maximo) {
            maximo = edades[i];
        }
    }
    return maximo;
}

bool buscarElemento(int*edades, int n, int edad) {
    for (int i = 0; i < n; ++i) {
        if (edad == edades[i]) {
            return true;
        }
    }
    return false;
}