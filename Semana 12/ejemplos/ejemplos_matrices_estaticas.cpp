#include <iostream>
using namespace std;

#define FILAS 3
#define COLUMNAS 4

void modificarMatriz(int [FILAS][COLUMNAS]);

int main() {
    srand(time(NULL));
    //const int filas{3}, columnas{4};
    // Inicialización estática
    int matriz[FILAS][COLUMNAS] = {
        {1,23,-4,45},
        {67,23,12,1},
        {-23,1,32,99}
    };
    
    // Modificar valor
    matriz[1][0] = 100;

    // Inicialización con valores aletorios
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            matriz[i][j] = rand() % 101;
        }
    }

    // Recorrido por filas
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout<<"Fila: "<<i<<", Columna: "<<j<<" = " << matriz[i][j]<<endl;
        }
        cout << endl;
    }

    modificarMatriz(matriz);
    cout << "\nMatriz luego de la modificacion\n";
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << "Fila: " << i << ", Columna: " << j << " = " << matriz[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}

void modificarMatriz(int matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            matriz[i][j] += 5;
        }
    }
}