#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
using namespace System;

// Ancho y alto de toda la consola
#define ANCHO_CONSOLA 60
#define ALTO_CONSOLA 30

void configurar();
void simularMovimientoEnRegion();
void mostrarCaracter(int, int, char);
void borrarCaracter(int, int);
void moverCaracter(int&, int&, int, int, char);
bool esPosicionValida(int, int, int, int, int, int);
void mostrarMarco(int, int, int, int);

int main() {
    configurar();
    simularMovimientoEnRegion();
    char c = _getch();
    return 0;
}

void configurar() {
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

bool esPosicionValida(int x,int y, int X1, int Y1, int X2, int Y2) {
    /*
        Validar posiciones en base a una región que inicia en (x1,y1)
        y termina en (x2, y2). Recordar que se incluyen ambas coordenadas
    */
    return x >= X1 && y >= Y1 && x <= X2 && y <= Y2;
}

void mostrarCaracter(int x, int y, char c) {
    Console::SetCursorPosition(y, x);
    cout << c;
}

void borrarCaracter(int x, int y) {
    mostrarCaracter(x, y, ' ');
}

void moverCaracter(int& x, int& y, int dx, int dy, char c) {
    borrarCaracter(x, y);
    x += dx; y += dy;
    mostrarCaracter(x, y, c);
}

void simularMovimientoEnRegion() {
    /*
        Cuando se quiere simular en una región de la consola,
        se tienen que especificar coordenadas de la región, esto
        puede variar dependiendo de la implementación. Por ejemplo
        se puede definir una región en base a dos coordenadas:
        El extremo superior izquierdo (x1, y1) y el extremo inferior 
        derecho (x2, y2). Por ejemplo:

        (x1, y1)
             -------------------
            |                   |
            |                   |
            |                   |
            |                   |
             -------------------
                                (x2, y2)

        Se consideran ambas coordenadas como válidas. Ahora hay que
        realizar la simulación dentro de esta región de forma similar
        a usar toda la consola.

        Cuando se usa toda la consola (x1=0,y1=0) y (x2=ALTO-1, y2=ANCHO-1)
        Ahora podemos tener un mayor control sobre la ubicación de la
        simulación
    */
    // Coordenadas de la región (se incluyen en la simulación)
    int X1{5}, Y1{5}, X2{20}, Y2{ANCHO_CONSOLA-6}; 

    // Coordenadas del objeto inicial
    // Ahora deben de estar dentro de la región
    int x{7}, y{6}, dx{1}, dy{1};

    // Mostramos caracter
    mostrarCaracter(x, y, '*');

    // Mostramos marco fuera de los límites válidos de la región
    mostrarMarco(X1 - 1, Y1 - 1, X2 + 1, Y2 + 1);

    while (1) {
        if (esPosicionValida(x, y, X1, Y1, X2, Y2)) {
            moverCaracter(x, y, dx, dy, '*');
            // Cambiar dirección cuando el caracter
            // colisione con los límites de la región
            if (x == X1 || x == X2) dx *= -1;
            if (y == Y1 || y == Y2) dy *= -1;
        }
        // Mostramos marco fuera de los límites de la región
        mostrarMarco(X1-1,Y1-1,X2+1,Y2+1);
        Sleep(100);
    }
}

void mostrarMarco(int x1, int y1, int x2, int y2) {
    /*
        Mostrar marco dados el extremo superior izquierdo (x1, y1) y
        el extremo inferior derecho (x2, y2).
    */
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (i == x1 || i == x2 || j == y1 || j == y2) {
                // Si usa SetCursorPosition, recuerde que
                // primero van las columnas, luego las filas
                Console::SetCursorPosition(j, i);
                Console::ForegroundColor = ConsoleColor::White;
                
                // Extremos del marco
                if( i == x1 && j == y1) cout << (char)201;
                else if( i == x1 && j == y2) cout << (char)187;
                else if (i == x2 && j == y1) cout << (char)200;
                else if (i == x2 && j == y2) cout << (char)188;
                // Filas y columnas
                else if (i == x1) cout << (char)205;
                else if (i == x2) cout << (char)205;
                else if (j == y1) cout << (char)186;
                else if (j == y2) cout << (char)186;
            }
        }
    }
}