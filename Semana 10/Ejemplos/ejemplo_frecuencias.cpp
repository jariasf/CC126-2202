#include <iostream>
#include <cstdlib>
using namespace std;
/*
Entrada:
Ingresar el numero de notas: 8

Salida:
Nota de alumno 1: 10
Nota de alumno 2: 20
Nota de alumno 3: 15
Nota de alumno 4: 3
Nota de alumno 5: 3
Nota de alumno 6: 15
Nota de alumno 7: 15
Nota de alumno 8: 5

Nota 0: 0
Nota 1: 0
Nota 2: 0
Nota 3: 2
Nota 4: 0
Nota 5: 1
..
Nota 15: 3
..
Nota 20: 1

*/
#define FREQ_SIZE 21
int ingresarNumeroAlumnos();
void generarNotas(int *, int);
void calcularFrecuencias(int *, int);
int* calcularFrecuencias2(int*, int);
void mostrarNotas(int*, int);

int main() {
    srand(time(NULL));
    int n, *notas;
    n = ingresarNumeroAlumnos();
    notas = new int[n];
    
    generarNotas(notas, n);
    mostrarNotas(notas, n);

    cout << "\nFrecuencia de notas\n";
    //calcularFrecuencias(notas, n);    
    int* frecuencias = calcularFrecuencias2(notas, n);
    for (int i = 0; i < FREQ_SIZE; ++i) {
        cout << "Nota " << i << ": " << frecuencias[i] << endl;
    }

    delete[] frecuencias;
    delete[] notas;
    return 0;
}

int ingresarNumeroAlumnos() {
    int n;
    do {
        cout << "Ingresar numero de alumnos: ";
        cin >> n;
    } while ( n <= 0 || n > 40 );
    return n;
}

void generarNotas(int *notas, int n) {
    for (int i = 0; i < n; ++i) {
        notas[i] = rand() % FREQ_SIZE;
    }
}

void mostrarNotas(int *notas, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nota del alumno " << i + 1 << ": " << notas[i] << endl;
    }
}

void calcularFrecuencias(int *notas, int n) {
    int* frecuencias = new int[FREQ_SIZE]{};
    for (int i = 0; i < n; ++i) {
        frecuencias[notas[i]]++;
    }

    for (int i = 0; i < FREQ_SIZE; ++i) {
        cout << "Nota " << i << ": " << frecuencias[i] << endl;
    }

    delete[] frecuencias;
}

int* calcularFrecuencias2(int* notas, int n) {
    int* frecuencias = new int[FREQ_SIZE] {};
    for (int i = 0; i < n; ++i) {
        frecuencias[notas[i]]++;
    }
    return frecuencias;
}
