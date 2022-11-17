#include <iostream>
using namespace std;

#define MAX_VALUE 5
void generarValores(int**, int, int);
void mostrarValores(int**, int, int);
int nextInt(int, int);
int* determinarFrecuenciaCultivos(int**, int, int);
int calcularMayorCultivo(int*, int);
bool esGuaridaDeTopo(int**, int, int);
void determinarGuaridasDeTopos(int**, int, int);
bool esGuaridaDeTopo(int**, int, int, int, int);
void determinarGuaridasDeTopos2(int**, int, int);

int main() {
    srand(time(NULL));
    int filas{10}, columnas{15};
    int** matriz = new int* [filas];
    for (int i = 0; i < filas; ++i)
        matriz[i] = new int[columnas];

    // Generar una matriz de 10 x 15, donde contenga de forma aleatoria los tres tipos de cultivos
    generarValores(matriz, filas, columnas);
    mostrarValores(matriz, filas, columnas);

    // Determinar que cultivo tiene la mayor y menor frecuencia
    int* frecuencias = determinarFrecuenciaCultivos(matriz, filas, columnas);
    int mayor_cultivo = calcularMayorCultivo(frecuencias, MAX_VALUE);
    // TODO: Calcular cultivo de menor frecuencia
    cout << "\nEl cultivo con mayor frecuencia es " << mayor_cultivo << ", y con menor frecuencia es el " << endl;

    // Determinar los puntos(fila, columna), donde pueda existir una guarida de topo
    determinarGuaridasDeTopos2(matriz, filas, columnas);

    delete[] frecuencias;
    for (int i = 0; i < filas; ++i)
        delete[] matriz [i];
    delete[] matriz;
    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarValores(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = nextInt(1, 3);
        }
    }
}

void mostrarValores(int**matriz, int filas, int columnas) {
    cout << "\nValores de matriz\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}


void determinarFrecuenciaCultivosUsandoContadores(int** matriz, int filas, int columnas) {
    /*
    Entrada:
    1 1 2 3 1 2 3 2 1
    2 2 1 3 1 2 3 1 2
    2 3 2 1 2 3 2 1 2

    Proceso:
    1 -> 9
    2 -> 11
    3 -> 6
    */
    int cont1{0}, cont2{0}, cont3{0};
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] == 1) cont1++;
            else if (matriz[i][j] == 2) cont2++;
            else cont3++;
        }
    }
}

int* determinarFrecuenciaCultivos(int** matriz, int filas, int columnas) {
    /*
    Entrada:
    1 1 2 3 1 2 3 2 1
    2 2 1 3 1 2 3 1 2
    2 3 2 1 2 3 2 1 2

    Salida:
    1 -> 9
    2 -> 11
    3 -> 6
    */
    int* frecuencias = new int[MAX_VALUE]{0};
    // frecuencias[1] = cont1
    // frecuencias[2] = cont2
    // frecuencias[3] = cont3
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            frecuencias[matriz[i][j]]++;
        }
    }
    return frecuencias;
}

int calcularMayorCultivo(int* arreglo, int n) {
    int mayor = arreglo[1];
    int pos_mayor = 1;

    for (int i = 2; i < n; ++i) {
        if (arreglo[i] > mayor) {
            mayor = arreglo[i];
            pos_mayor = i;
        }
    }
    return pos_mayor;
}

bool esGuaridaDeTopo(int** matriz, int x, int y) {
    if (matriz[x - 1][y] == 3 && matriz[x + 1][y] == 1 &&
        matriz[x][y - 1] == 2 && matriz[x][y + 1] == 2)
        return true;
    return false;
}


void determinarGuaridasDeTopos(int** matriz, int alto, int ancho) {
    cout << "\nLos puntos donde puede existir una guarida de topo son: \n";
    for (int x = 1; x <= alto - 2; ++x) {
        for (int y = 1; y <= ancho - 2; ++y) {
            if (esGuaridaDeTopo(matriz, x, y)) {
                cout << "Fila: " << x + 1 << " , Columna: " << y + 1 << endl;
            }
        }
    }
}

bool esGuaridaDeTopo(int** matriz, int x, int y, int alto, int ancho) {
    if ( x - 1 >= 0    && matriz[x - 1][y] == 3 && 
         x + 1 < alto  && matriz[x + 1][y] == 1 &&
         y - 1 >= 0    && matriz[x][y - 1] == 2 && 
         y + 1 < ancho && matriz[x][y + 1] == 2)
        return true;
    return false;
}

void determinarGuaridasDeTopos2(int** matriz, int alto, int ancho) {
    cout << "\nLos puntos donde puede existir una guarida de topo son: \n";
    for (int x = 0; x < alto; ++x) {
        for (int y = 0; y < ancho; ++y) {
            if (esGuaridaDeTopo(matriz, x, y, alto, ancho)) {
                cout << "Fila: " << x + 1 << " , Columna: " << y + 1 << endl;
            }
        }
    }
}