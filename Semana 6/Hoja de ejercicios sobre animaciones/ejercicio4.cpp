#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace System;
using namespace std;

#define ANCHO 50
#define ALTO 10
#define BARRA_ESPACIADORA 32
#define FLECHA_IZQUIERDA 75
#define FLECHA_DERECHA 77

const char TANQUE = 220;
const char BALA = '*';

void mostrarCaracter(int, int , char);
void borrarCaracter(int, int);
void simularJuego();

int main() {
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
    simularJuego();
    system("pause");
    return 0;
}

void mostrarCaracter(int x, int y, char caracter) {
    Console::SetCursorPosition(y, x);
    cout << caracter;
}

void borrarCaracter(int x, int y) {
    mostrarCaracter(x, y, ' ');
}

void simularJuego() {
    int x, y;
    x = ALTO - 1; y = ANCHO / 2;
    mostrarCaracter(x, y, TANQUE);

    while (1) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == BARRA_ESPACIADORA) {
                for (int fila = x - 1; fila >= 0; --fila) {
                    mostrarCaracter(fila, y, BALA);
                    Sleep(300);
                    borrarCaracter(fila, y);
                }
            }
            else if (tecla == FLECHA_IZQUIERDA) {
                borrarCaracter(x, y);
                if(y > 0) y--;
                mostrarCaracter(x, y, TANQUE);
            }
            else if (tecla == FLECHA_DERECHA) {
                // Ejercicio: Completar movimiento a la derecha
            }
        }
    }
}
