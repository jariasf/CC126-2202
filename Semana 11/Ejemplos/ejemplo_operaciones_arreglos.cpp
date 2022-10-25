#include <iostream>
using namespace std;

void listarElementos(int*, int);
int* insertarAlFinal(int*, int&, int);
int* insertarAlInicio(int*, int&, int);
int* insertarEnPosicion(int*, int&, int, int);

int main() {
    int n{0}, elemento;
    int* arreglo = nullptr;
    
    for (int i = 0; i < 3; ++i) {
        cout << "\nIngrese elemento a insertar: ";
        cin >> elemento;
        arreglo = insertarAlFinal(arreglo, n, elemento);
        arreglo = insertarAlInicio(arreglo, n, elemento);
        listarElementos(arreglo, n);
    }

    if (arreglo != nullptr) {
        delete[] arreglo;
        arreglo = nullptr;
    }
    return 0;
}

void listarElementos(int* arreglo, int n) {
    if (arreglo == nullptr) {
        cout << "Arreglo vacio" << endl;
        return;
    }
    cout << "Lista de elementos\n";
    cout << "------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << "Arreglo[" << i << "] = " << arreglo[i] << endl;
    }
}

int* insertarAlFinal(int* arreglo, int& n, int elemento) {
    // Crear arreglo auxiliar de tamaño n+1
    int* auxiliar = new int[n + 1];

    // Copiamos valores del arreglo original en el auxiliar
    for (int i = 0; i < n; ++i) {
        auxiliar[i] = arreglo[i];
    }

    // Aumentar el valor de la variable tamaño (paso por referencia)
    n++;

    // Insertar el nuevo elemento
    auxiliar[n - 1] = elemento;

    // Liberar memoria de arreglo
    delete[] arreglo;
    arreglo = nullptr;

    return auxiliar;
}

int* insertarAlInicio(int* arreglo, int &n, int elemento) {
    // Crear arreglo auxiliar de tamaño n+1
    int* auxiliar = new int[n + 1];

    // Copiamos valores del arreglo original en el auxiliar
    for (int i = 0; i < n; ++i) {
        auxiliar[i+1] = arreglo[i];
    }

    // Insertar el nuevo elemento
    auxiliar[0] = elemento;

    // Aumentar el valor de la variable tamaño (paso por referencia)
    n++;

    // Liberar memoria de arreglo
    delete[] arreglo;
    arreglo = nullptr;

    return auxiliar;
}

int* insertarEnPosicion(int *arreglo, int &n, int posicion, int elemento) {
    //TODO: Implementar método que permita insertar un nuevo elemento
    //      en una determinada posición
    return nullptr;
}