#include <iostream>
using namespace std;
/*
Dibujar una figura
—-----------------
[1] Cuadrado
[2] Triangulo
Elija una opcion: 1
Ingrese un numero n (4<=n<=6): 4
*/

int ingresarNumero();
void imprimirEspacios(int);
void imprimirCuadrado(int, int);
void imprimirCuadrados(int);


int main() {
    int opcion, n;
    cout << "Dibujar una figura";
    cout << "\n—-----------------";
    cout << "\n[1] Cuadrado";
    cout << "\n[2] Triangulo";
    cout << "\nElija una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: n = ingresarNumero();
                imprimirCuadrados(n);
                break;
        case 2: //TODO: Implementar el caso de triangulos
                break;
        default: cout << "Ingreso invalido, posibles valores son 1 y 2\n";
    }
    return 0;
}

int ingresarNumero() {
    int n;
    do {
        cout << "Ingrese un numero n (4<=n<=6): ";
        cin >> n;
    } while ( n < 4 || n > 6 );
    return n;
}

void imprimirEspacios(int num_espacios) {
    for (int i = 0; i < num_espacios; ++i) {
        cout << " ";
    }
}

/*
****
*X *
*  *
****
*/
void imprimirCuadrado(int n, int id) {
    for (int fila = 1; fila <= n; ++fila) {
        imprimirEspacios(n * id);
        for (int columna = 1; columna <= n; ++columna) {
            if (fila == 1 || fila == n || columna == 1 || columna == n) {
                cout << "*";
            }
            else if (fila == 2 && columna == 2) {
                cout << id;
            }else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
/*
****
*1 *
*  *
****
****
*2 *
*  *
****
****
*3 *
*  *
****
****
*4 *
*  *
****
*/
void imprimirCuadrados(int n) {  
    for (int cuadrado = 1; cuadrado <= n; ++cuadrado) {
        imprimirCuadrado(n, cuadrado);
    }
}