#include <iostream>
using namespace std;


void ingresarValores(int**, int, int);
void generarValores(int**, int, int);
void mostrarValoresPorFila(int**, int, int);
void mostrarValoresPorColumna(int**, int, int);

int main() {
    srand(time(NULL));

    int num_filas, num_columnas;

    // Ingreso de filas y columnas
    do {
        cout << "Ingresar el numero de filas: ";
        cin >> num_filas;
    } while (num_filas <= 0);

    do {
        cout << "Ingresar el numero de columnas: ";
        cin >> num_columnas;
    } while (num_columnas <=0);


    // Declaración
    int** matriz = new int* [num_filas];
    for (int i = 0; i < num_filas; ++i) {
        matriz[i] = new int[num_columnas];
    }

    // Inicialización por consola
    //ingresarValores(matriz, num_filas, num_columnas);

    // Inicialización aleatoria
    generarValores(matriz, num_filas, num_columnas);

    // Mostrar valores de la matriz por filas
    mostrarValoresPorFila(matriz, num_filas, num_columnas);

    // Mostrar valores de la matriz por columnas
    mostrarValoresPorColumna(matriz, num_filas, num_columnas);

    // Liberar memoria
    for (int i = 0; i < num_filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

void ingresarValores(int** matriz, int num_filas, int num_columnas) {
    // Inicialización por consola
    for (int i = 0; i < num_filas; ++i) {
        for (int j = 0; j < num_columnas; ++j) {
            cout << "Ingrese un valor en la fila " << i << " columna " << j << ": ";
            cin >> matriz[i][j];
        }
    }
}

void generarValores(int** matriz, int num_filas, int num_columnas) {
    // Inicialización aleatoria
    for (int i = 0; i < num_filas; ++i) {
        for (int j = 0; j < num_columnas; ++j) {
            matriz[i][j] = rand() % 101;
        }
    }
}

void mostrarValoresPorFila(int** matriz, int num_filas, int num_columnas) {
    // Mostrar valores de la matriz por filas
    cout << "\nValores de la matriz por filas\n";
    for (int i = 0; i < num_filas; ++i) {
        cout << "Fila " << i << " -> ";
        for (int j = 0; j < num_columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void mostrarValoresPorColumna(int** matriz, int num_filas, int num_columnas) {
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
}