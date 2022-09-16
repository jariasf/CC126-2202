#include <iostream>
using namespace std;

int* calcularSumatoria(int *n) {
    // Declaraci�n de variables y asignaci�n memoria din�mica
    int* suma = new int;
    int* i = new int;
    int* termino = new int;
    int* signo = new int;
    
    // Inicializaci�n
    *suma = 0;
    *i = 1;
    *signo = 1;
    
    // Proceso
    cout << "Los terminos son: ";
    while (*i <= *n) {
        *termino = *signo * *i;
        cout << *termino << " ";
        *suma = *suma + *termino;
        *signo = *signo * -1;
        (*i)++;
    }
    cout << endl;

    // Liberaci�n de memoria
    delete i;
    delete termino;
    delete signo;
    return suma;
}

int main() {
    int* n = new int;
    int* suma;
    cout << "Cantidad de terminos: ";
    cin >> *n;
    if (*n > 0) {
        suma = calcularSumatoria(n);
        cout << "La suma es: " << *suma << endl;
        delete suma;
    }
    else {
        cout << "Ingreso invalido\n";
    }
    delete n;
    return 0;
}