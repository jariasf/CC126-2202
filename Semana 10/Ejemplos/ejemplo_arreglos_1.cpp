#include <iostream>
using namespace std;

/*
Ejemplo
-------
1. Crear un arreglo de enteros de tama�o 100 usando memoria din�mica
2. Inicializar el arreglo con valores entre 0 y 99 inclusive
3. Mostrar los elementos por consola
*/

int main() {
    
    // Declaraci�n
    int n = 100;
    int* arreglo = new int[n];
    
    // Inicializaci�n
    for (int i = 0; i < n; ++i) {
        arreglo[i] = i;
        // i = 0 -> arreglo[0] = 0
        // i = 1 -> arreglo[1] = 1
        // i = 2 -> arreglo[2] = 2
        //...
        // i = k -> arreglo[k] = k
        // i = 99 -> arreglo[99] = 99
    }

    // Mostrar elementos del arreglo
    for (int i = 0; i < n; ++i) {
        cout << "Elemento en la posicion " << i << ": " << arreglo[i] << endl;
    }

    // Liberar
    delete[]arreglo;

    return 0;
}