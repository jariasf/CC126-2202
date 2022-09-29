#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
using namespace System;

#define ANCHO 40
#define ALTO 20

void simularMovimientos();
void mostrarCaracter(int ,int ,char);
void borrarCaracter(int, int);
void moverCaracter(int &, int &, int &, int &);
bool colisionan(int, int, int ,int, int, int);
void invertirDireccion(int &, int&, int &, int &);

int main() {
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
    simularMovimientos();
    char c = _getch();
    return 0;
}

void simularMovimientos() {
    int x, y, dx, dy;
    int x2, y2, dx2, dy2;

    // Punto de inicio
    x = 5;  y = 5;
    // Direccion de inicio (diagonal superior izquierda)
    dx = 0; dy = 1;

    // Objeto 2
    x2 = 5; y2 = 11;
    dx2 = 0; dy2 = -1;

    while (1) {
        mostrarCaracter(x, y, '*');
        mostrarCaracter(x2, y2, '+');
        Sleep(100);
        borrarCaracter(x, y);
        borrarCaracter(x2,y2);

        if (colisionan(x, y, dx, dy, x2, y2)) {
            invertirDireccion(dx, dy, dx2, dy2);
        }

        moverCaracter(x, y, dx, dy);
        moverCaracter(x2,y2,dx2,dy2);
    }
}

void mostrarCaracter(int x, int y, char c) {
    Console::SetCursorPosition(y, x);
    cout << c;
}

void borrarCaracter(int x, int y) {
    mostrarCaracter(x, y, ' ');
}

void moverCaracter(int &x, int &y, int &dx, int &dy) {
    // (x,y) -> (x+dx, y+dy)
    x += dx;
    y += dy;

    // Cambio de dirección cuando colisiona en los limites superior o inferior
    if (x == 0 || x == ALTO - 1) {
        dx = -dx;
    }

    // Cambio de dirección cuando colisiona en los limites izquierdo o derecho
    if (y == 0 || y == ANCHO - 1) {
        dy = -dy;
    }
}

bool colisionan(int x1, int y1, int dx1, int dy1, int x2, int y2) {
    if (x1 == x2 && y1 == y2)
        return true;
    x1 += dx1;
    y1 += dy1;
    if (x1 == x2 && y1 == y2)
        return true;

    return false;
}

void invertirDireccion(int &dx1, int &dy1, int &dx2, int &dy2) {
    dx1 = -dx1; dy1 = -dy1;
    dx2 = -dx2; dy2 = -dy2;
}