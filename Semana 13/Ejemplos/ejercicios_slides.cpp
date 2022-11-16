#include <iostream>
using namespace std;
struct Coord {
    int x, y;
    bool encontrado;
};

void generarValores(int**, int ,int);
void mostrarValores(int**, int ,int);
void mostrarValores2(int**, int, int);
void buscarNumeroEnMatriz(int**, int, int, int);
Coord buscarNumeroEnMatrizUsandoEstructura(int**, int, int , int);
Coord encontrarMayorEnMatriz(int**, int, int);

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
    } while (num_columnas <= 0);


    // Declaración
    int** matriz = new int* [num_filas];
    for (int i = 0; i < num_filas; ++i) {
        matriz[i] = new int[num_columnas];
    }

    generarValores(matriz, num_filas, num_columnas);
    cout << "\nValores de la matriz\n";
    mostrarValores2(matriz, num_filas, num_columnas);

    int valor;
    cout << "\nIngrese valor a buscar: ";
    cin >> valor;

    //buscarNumeroEnMatriz(matriz, num_filas, num_columnas, valor);

    Coord pos = buscarNumeroEnMatrizUsandoEstructura(matriz, num_filas, num_columnas, valor);
    if (pos.encontrado) {
        cout << "El valor se encuentra en la fila " << pos.x << " y columna " << pos.y << endl;
    }
    else {
        cout << "El valor no fue encontrado" << endl;
    }

    Coord mayor = encontrarMayorEnMatriz(matriz, num_filas, num_columnas);
    cout << "\nEl mayor valor es " << matriz[mayor.x][mayor.y];
    cout << " y esta ubicado en la fila " << mayor.x << " y columna " << mayor.y << endl;

    // Liberar memoria
    for (int i = 0; i < num_filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

void generarValores(int** matriz, int num_filas, int num_columnas) {
    // Inicialización aleatoria
    for (int i = 0; i < num_filas; ++i) {
        for (int j = 0; j < num_columnas; ++j) {
            matriz[i][j] = rand() % 101;
        }
    }
}

void mostrarValores(int **matriz, int filas, int columnas) {    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Matriz[" << i << "][" << j << "] = " << matriz[i][j] << endl;
        }
    }
}

void mostrarValores2(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void buscarNumeroEnMatriz(int** matriz, int filas, int columnas, int valor) {
    /*
    matriz
    1 2 3 4   10 1
    5 3 1 100 23 1
    4 7 3 1   43 4

    valor=2
    */
    bool encontrado{false};
    int posf, posc;
    for (int i = 0; i < filas && !encontrado; ++i) {
        for (int j = 0; j < columnas && !encontrado; ++j) {
            if (matriz[i][j] == valor) {
                posf = i;
                posc = j;
                encontrado = true;
                //break;
            }
        }
        //if (encontrado) break;
    }
    if (encontrado) {
        cout << "El valor se encuentra en la fila " << posf << " y columna " << posc << endl;
    }
    else {
        cout << "El valor no se encuentra en la matriz" << endl;
    }
}

void buscarNumeroEnMatriz(int** matriz, int filas, int columnas, int valor, int& posf, int& posc) {
    bool encontrado{false};
    posf = posc = -1;
    for (int i = 0; i < filas && !encontrado; ++i) {
        for (int j = 0; j < columnas && !encontrado; ++j) {
            if (matriz[i][j] == valor) {
                posf = i;
                posc = j;
                encontrado = true;
            }
        }
    }
}

Coord buscarNumeroEnMatrizUsandoEstructura(int** matriz, int filas, int columnas, int valor) {
    Coord pos;
    bool encontrado{ false };
    int posf, posc;
    for (int i = 0; i < filas && !encontrado; ++i) {
        for (int j = 0; j < columnas && !encontrado; ++j) {
            if (matriz[i][j] == valor) {
                posf = i;
                posc = j;
                encontrado = true;
            }
        }
    }

    pos.x = posf;
    pos.y = posc;
    pos.encontrado = encontrado;
    return pos;
}


Coord encontrarMayorEnMatriz(int** matriz, int num_filas, int num_columnas) {
    /*
    matriz
    1 2 3 4   10 1
    5 3 1 100 23 1
    4 7 3 1   43 4
    */
    int mayor = matriz[0][0], posf{0}, posc{0};
    for (int i = 0; i < num_filas; ++i) {
        for (int j = 0; j < num_columnas; ++j) {
            if (matriz[i][j] > mayor) {
                mayor = matriz[i][j];
                posf = i;
                posc = j;
            }
        }
    }

    Coord pos;
    pos.x = posf;
    pos.y = posc;
    return pos;
}