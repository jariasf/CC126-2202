#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
using namespace System;

#define ALTO 20
#define ANCHO 40

void mostrarFigura(int);
void mostrarCaracter(int, int, int);
int ingresarNumero();

int main() {

    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;

    // Pantalla de ingreso
    cout << "Ejemplo de animacion de figura\n";
    cout << "------------------------------\n";
    int n = ingresarNumero();    
    Console::Clear();
    // Pantalla de grafica
    mostrarFigura(n);
    Console::Clear();
    // Pantalla de fin
    cout << "Figura terminada!!\n";
    char c = _getch();    
    return 0;
}

int ingresarNumero() {
    int n;
    do {
        cout << "Ingrese un numero: ";
        cin >> n;
    } while (n <= 0 || n > 9);
    return n;
}

void mostrarCaracter(int x, int y, int val) {
    Console::SetCursorPosition(y, x);
    cout << val;
    Sleep(300);
}

void mostrarFigura(int n) {
    int x, y, contador;
    bool subida;

    x = y = n;
    contador = 1;
    subida = true;
    /*
     (6,7) 
     (7,7) 
     (8,7)  |  (8,8) <- (8,9)  ^
     (9,7)  v  (9,8)    (9,9)  | 
               (10,8) 
    */
    while (x >= 1 && y >= 1) {
        if (subida) {
            /*
            (8,9)                         
            (9,9)  <- inicial             9
            */
            for (int i = 1; i <= contador; ++i) {
                // Imprimir numero
                mostrarCaracter(x, y, y);
                // Subir
                x--;
            }
            // Cambio de columna
            y--;
        }
        else {
            for (int i = 1; i <= contador; ++i) {
                // Imprimir numero
                mostrarCaracter(x, y, y);
                // Bajar
                x++;
            }
            // Cambio de columna
            x--; y--;
        }
        subida = !subida;
        contador++;
    }

}
