#include <iostream>
using namespace std;

/*
Dado un numero n, mostrar los n primeros numeros pares
Entrada:
Ingrese el numero N: 4
Salida:
2 4 6 8

Entrada:
Ingrese el numero N: 10
Salida:
2 4 6 8 10 12 14 16 18 20
*/

//1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , ..., N
bool esPar(int *n) {
    return *n % 2 == 0;
}
void mostrarNumerosPares(int *n) {
    int* numero = new int;
    *numero = 1;
    *n = *n * 2;
    //n=4
    //1, 2, 3, 4, 5, 6, 7, 8
    while (*numero <= *n ) {
        if (esPar(numero)) {
            cout << *numero<<" ";
        }
        (*numero)++;
    }
    cout << endl;
    delete numero;
}

void mostrarNumerosPares2(int* n) {
    int* numero = new int;
    int* contador = new int;
    *numero = 2;
    *contador = 1;
    //n=8
    //2, 4, 6, 8, 10, 12, 14
    while (*contador <= *n) {
        cout << *numero << " ";
        *numero = *numero + 2;
        (*contador)++;
    }
    cout << endl;
    delete contador;
    delete numero;
}

int main() {
    int* n = new int;
    cout << "Ingrese el numero N: ";
    cin >> *n;
    mostrarNumerosPares2(n);
    delete n;
    return 0;
}