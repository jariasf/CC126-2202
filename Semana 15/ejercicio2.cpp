#include <iostream>

using namespace std;

void generarValores(int**, int);
void mostrarMatriz(int**, int);
int contarPatron(int**, int, int);

int main() {
    srand(time(0));
    int n;
    int** matriz;
    do {
        cout << "Ingrese tamaño de la matriz: ";
        cin >> n;
    } while ( n <= 0 || n > 30);

    matriz = new int* [n];
    for (int i = 0; i < n; ++i)
        matriz[i] = new int[n];

    generarValores(matriz, n);
    mostrarMatriz(matriz, n);

    cout << endl;
    int patron;
    do {
        cout << "Ingrese patrón numérico: ";
        cin >> patron;
    } while (patron < 100 || patron > 999);

    int num_patrones = contarPatron(matriz, n, patron);
    cout << "\nEl numero de veces que se repite el patron es: " << num_patrones<<endl;

    for (int i = 0; i < n; ++i)
        delete[] matriz[i];
    delete[] matriz;
    return 0;
}

void generarValores(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void mostrarMatriz(int** matriz, int n) {
    cout << "\nMatriz generada\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

bool existePatron(int** matriz, int i, int j, int patron) {
    /*
       j
     i|1|3|4|

    135
    */
    int d1, d2, d3;

    d3 = patron % 10; patron /= 10;
    d2 = patron % 10; patron /= 10;
    d1 = patron;

    if (d1 == matriz[i][j] && d2 == matriz[i][j + 1] && d3 == matriz[i][j + 2])
        return true;

    return false;
}

int contarPatron(int** matriz, int n, int patron) {
    /*
    Entrada
    matriz
    1 3 4 2 0
    1 3 3 2 1
    4 3 2 1 5
    3 2 0 1 2
    3 2 3 2 1

    n = 5
    patron = 321

    Salida
    3
    */

    /*
    for(int i = ...; i <= ... ; ++i){
        for(int j = ...; j <= ... ; ++j){

        }
    }
    */
    int contador{0};
    for (int i = 0; i <= n - 1; ++i) {
        for (int j = 0; j <= n - 3; ++j) {
            if (existePatron(matriz, i, j, patron)) {
                contador++;
            }
        }
    }
    return contador;
}