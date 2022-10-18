#include <iostream>
using namespace std;

void ejemploInicializacionManual();

int main() {
    int n = 5; //[0,4]
    // Inicializacion con valores fijos
    //int* arreglo = new int[n]{12, 5, -123, 56, 86};

    // Inicializacion con ceros
    //int* arreglo = new int[n]{};

    // Inicialización usando cin
    int* arreglo = new int[n];
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese el elemento de la posicion " << i << ": ";
        cin >> arreglo[i];
    }

    // Mostrar los elementos del arreglo
    for (int i = 0; i < n; ++i) {
        cout << "Elemento en posicion " << i << ": " << arreglo[i] << endl;
    }

    cout << "\nAcceso usando operador de indirección\n";
    for (int i = 0; i < n; ++i) {
        cout << "Elemento en posicion " << i << ": " << *(arreglo + i) << endl;
    }

    // Liberar memoria
    delete[]arreglo;

    return 0;
}

void ejemploInicializacionManual() {
    // Declaración
    int n = 5; //[0,4]
    int* arreglo = new int[n];

    // Inicialización
    arreglo[0] = 12; // *(arreglo + 0) = 12
    arreglo[1] = 5;
    arreglo[2] = -123;
    arreglo[3] = 56;
    arreglo[4] = 86;
    //arreglo[5] = 90; // Mal acceso a memoria


    // Mostrar elementos
    //cout << "Elemento en posicion 2: " << arreglo[2] << endl;
    //cout << "Elemento en posicion 4: " << arreglo[4] << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Elemento en posicion " << i << ": " << arreglo[i] << endl;
    }

    // Liberar memoria
    delete[]arreglo;
}