#include <iostream>
#include <cstdlib>
using namespace std;

int nextInt(int, int);
void generarValores(int*, int);
void mostrarArreglo(int*, int);
void intercambiar(int&, int&);
void ordenar(int*, int);
void ordenar2(int*, int);
void ordenarPorIntercambios(int*, int);
void ordenarDescendente(int*, int);

int main() {
    srand(time(NULL));
    int n = 20;
    int* arreglo = new int[n];
    generarValores(arreglo, n);
    cout << "Arreglo inicial" << endl;
    mostrarArreglo(arreglo, n);
    
    // Ordenamos de forma ascendente el arreglo
    ordenar2(arreglo, n);

    cout << "\nArreglo ordenado de forma ascendente" << endl;
    mostrarArreglo(arreglo, n);

    // Ordenamos de forma descendente el arreglo
    ordenarDescendente(arreglo, n);

    cout << "\nArreglo ordenado de forma descendente" << endl;
    mostrarArreglo(arreglo, n);

    delete[] arreglo;
    arreglo = nullptr;
    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarValores(int *arreglo, int n) {
    for (int i = 0; i < n; ++i) {
        arreglo[i] = nextInt(1, 100);
    }
}

void mostrarArreglo(int* arreglo, int n) {
    for (int i = 0; i < n; ++i) {
        cout<<"Arreglo["<<i<<"] = " << arreglo[i] <<endl;
    }
}

void intercambiar(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void ordenar(int* arreglo, int n) {
    int menor, posicion_menor;
    for (int i = 0; i < n; ++i) {
        // Encontrar la posicion del menor desde i hasta el final
        menor = arreglo[i];
        posicion_menor = i;
        for (int j = i + 1; j < n; ++j) {
            if (arreglo[j] < menor) {
                menor = arreglo[j];
                posicion_menor = j;
            }
        }
        // Intercambiar la posición donde se ubica el menor con la
        // posición actual i
        intercambiar(arreglo[i], arreglo[posicion_menor]);
    }
}

void ordenar2(int* arreglo, int n) {
    int posicion_menor;
    for (int i = 0; i < n; ++i) {
        // Encontrar la posicion del menor desde i hasta el final
        posicion_menor = i;
        for (int j = i + 1; j < n; ++j) {
            if (arreglo[j] < arreglo[posicion_menor]) {
                posicion_menor = j;
            }
        }
        // Intercambiar la posición donde se ubica el menor con la
        // posición actual i
        intercambiar(arreglo[i], arreglo[posicion_menor]);
    }
}

void ordenarPorIntercambios(int* arreglo, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arreglo[j] < arreglo[i]) {
                intercambiar(arreglo[i], arreglo[j]);
            }
        }
    }
}

void ordenarDescendente(int *arreglo, int n) {
    //TODO: Ordenar el arreglo de forma descendente
    // Entrada
    //arreglo = [5,2,3,4,1]
    //
    // Salida
    //arreglo = [5,4,3,2,1]
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arreglo[j] > arreglo[i]) {
                intercambiar(arreglo[i], arreglo[j]);
            }
        }
    }
}