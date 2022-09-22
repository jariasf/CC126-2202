#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
using namespace System;

#define ANCHO 40
#define ALTO 15

void mostrarCaracter(int, int, char);
void borrarCaracter(int, int);
void mostrarCaracteresEnDiferentesPosiciones();
void simularMovimiento();
void mostrarAnimacionMovimientoDerecha();

int main() {
    //cout << Console::WindowHeight << " " << Console::WindowWidth << endl;
    Console::SetWindowSize(ANCHO, ALTO); // (ANCHO, ALTO) - (WIDTH, HEIGHT)
    Console::CursorVisible = false;
    mostrarAnimacionMovimientoDerecha();
    char c = _getch();
    return 0;
}

void mostrarCaracter(int x, int y, char caracter) {
    Console::SetCursorPosition(y, x);
    cout << caracter;
}

void borrarCaracter(int x, int y) {
    mostrarCaracter(x, y, ' ');
}

void mostrarCaracteresEnDiferentesPosiciones() {
    Console::SetCursorPosition(10, 5);  // (COLUMNA, FILA)
    cout << "+";
    // Usando funciones
    mostrarCaracter(5, 10, '+');
    mostrarCaracter(7, 12, '-');
}

void simularMovimiento() {
    int x, y;
    x = 5; y = 5;
    // Posicion (5,5)
    mostrarCaracter(x, y, '*');
    Sleep(300);
    borrarCaracter(x, y);
    // Cambiar posicion (5, 6)
    y++;
    mostrarCaracter(x, y, '*');
    Sleep(500);
    borrarCaracter(x, y);
    // Cambiar posicion (5, 7)
    y++;
    mostrarCaracter(x, y, '*');
}

void mostrarAnimacionMovimientoDerecha() {
    int x, y;
    x = 5; y = 5;
    mostrarCaracter(x, y, '*');
    Sleep(300);

    while (1) {
        borrarCaracter(x, y);
        if (y < ANCHO) y++;
        mostrarCaracter(x, y, '*');
        Sleep(300);
        //if (y == ANCHO - 1) break; // Criterio de parada
    }

    /*
    // Simular movimieno usando for
    // Sin modificar la posicion actual (x,y)
    // El caracter no desaparece al final
    // Izquierda a derecha
    for (int columna = y + 1; columna < ANCHO; ++columna) {
        // Borramos caracter de columna anterior
        borrarCaracter(x, columna - 1);
        // Mostramos caracter en columna actual
        mostrarCaracter(x, columna, '*');
        Sleep(300);
    }
    // Derecha a izquierda
    // Empezamos desde ANCHO - 2 debido a que anteriormente
    // nos ubicamos en la posicion (fila, ANCHO-1)
    for (int columna = ANCHO - 2; columna >= 0; --columna) {
        // Borramos caracter de columna anterior, en este caso
        // es + 1 debido a que nos movemos de derecha a izquierda
        borrarCaracter(x, columna + 1);
        // Mostramos caracter en columna actual
        mostrarCaracter(x, columna, '*');
        Sleep(300);
    }*/
}
