#include <iostream>
using namespace std;

int nextInt(int, int);
void generarMensaje(int*, int);
void imprimirMensaje(int*, int, int);
bool existeCapicua(int*, int);

int main() {
    srand(time(0));
    int n, num_capicuas{0}, mensaje{1};
    int* arreglo;
    do {
        n = nextInt(10, 15);
        arreglo = new int[n];
        generarMensaje(arreglo, n);
        imprimirMensaje(arreglo, n, mensaje);

        if (existeCapicua(arreglo, n))
            num_capicuas++;

        mensaje++;
        delete[] arreglo;
        cout << endl;
        system("pause");
    } while (num_capicuas < 5);
    
    cout << "CONTACTO!!" << endl;

    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarMensaje(int* arreglo, int n) {
    for (int i = 0; i < n; ++i) {
        arreglo[i] = rand() % 10;
    }
}

void imprimirMensaje(int* arreglo, int n, int mensaje) {
    cout << "\nMensaje: "<<mensaje<<endl;
    for (int i = 0; i < n; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

bool existeCapicua(int* arreglo, int n) {
    /*
    Entrada:
               0 1 2 3 4 5 6 7 8
    arreglo = [1 4 2 5 4 1 9 4 9], n = 9

    Salida:
    verdadero    
    */
    int d4 = arreglo[n - 1], d3 = arreglo[n - 2], d2 = arreglo[n - 3], d1 = arreglo[n - 4];
    // Validacion de capicua de longitud 4
    /*
    d1 = 1, d2 = 9, d3 = 4, d4 = 9
    */
    if (d1 == d4 && d2 == d3) return true; // 1 9 9 1

    // Validacion de capicua de longitud 3
    /*
    d2 = 9, d3 = 4, d4 = 9
    */
    if (d2 == d4) return true;

    // Validacion de capicua de longitud 2
    /*
    d3 = 4, d4 = 9
    */
    if (d3 == d4) return true;

    return false;
}