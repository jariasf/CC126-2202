#include <iostream>
using namespace std;

void ejemploArregloDinamico() {
    // Arreglos en una dimensión
    int n{3};
    // Declaración
    int* arreglo = new int[n];

    // Asignación
    arreglo[0] = 34;
    arreglo[1] = -12;
    arreglo[2] = 100;

    // Limpiar la memoria
    delete[] arreglo;
}

int main() {
    srand(time(NULL));

    int num_filas{4}, num_columnas{3};
    // Declaración
    int** matriz = new int*[num_filas];
    for (int i = 0; i < num_filas; ++i) {
        matriz[i] = new int[num_columnas];
    }
    //matriz[0] = new int[num_columnas];
    //matriz[1] = new int[num_columnas];
    //matriz[2] = new int[num_columnas];
    //matriz[3] = new int[num_columnas];

    // Inicialización con valores de forma manual en la matriz
    matriz[0][0] = 23;
    matriz[0][1] = 45;
    matriz[0][2] = 67;
    matriz[1][0] = -12;
    matriz[2][0] = 122;
    matriz[3][0] = 130;

    /*
    int** matriz2 = new int* [num_filas];
    matriz2[0] = new int[num_columnas] {2, 3, 4};
    matriz2[1] = new int[num_columnas] {2, 23, 34};
    matriz2[2] = new int[num_columnas] {2, -12, -34};*/

    /*
    // Inicialización por consola
    for (int i = 0; i < num_filas; ++i) {
        for (int j = 0; j < num_columnas; ++j) {
            cout << "Ingrese un valor en la fila " << i << " columna " << j<<": ";
            cin >> matriz[i][j];
        }
    }*/

    // Inicialización aleatoria
    for (int i = 0; i < num_filas; ++i) {
        for (int j = 0; j < num_columnas; ++j) {
            matriz[i][j] = rand() % 101;
        }
    }

    // Mostrar valores de la matriz por filas
    cout << "\nValores de la matriz por filas\n";
    for (int i = 0; i < num_filas; ++i) {
        cout << "Fila " << i << " -> ";
        for (int j = 0; j < num_columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Mostrar valores de la matriz por columnas
    cout << "\nValores de la matriz por columnas\n";
    for (int j = 0; j < num_columnas; ++j) {
        cout << "Columna " << j << " -> ";
        for (int i = 0; i < num_filas; ++i) {
            cout << matriz[i][j] << " ";
            // matriz[0][0] -> matriz[1][0] -> matriz[2][0] -> matriz[3][0]
            // matriz[0][1] -> matriz[1][1] -> matriz[2][1] -> matriz[3][1]
            // matriz[0][2] -> matriz[1][2] -> matriz[2][2] -> matriz[3][2]
        }
        cout << endl;
    }


    // Liberar memoria
    for (int i = 0; i < num_filas; ++i) {
        delete[] matriz[i];
    }
    //delete[] matriz[0];
    //delete[] matriz[1];
    //delete[] matriz[2];
    //delete[] matriz[3];
    delete[] matriz;

    return 0;
}