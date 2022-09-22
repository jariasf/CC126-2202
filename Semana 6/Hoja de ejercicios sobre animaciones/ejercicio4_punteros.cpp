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

void mostrarCaracter(int*, int*, char);
void borrarCaracter(int*, int*);
void simularJuego();

int main() {
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
    simularJuego();
    system("pause");
    return 0;
}

// caracter no será puntero debido a que usualmente le pasaremos valores
// de forma directa como constantes, en ese caso no es recomendable usar
// punteros
void mostrarCaracter(int* x, int* y, char caracter) {
    Console::SetCursorPosition(*y, *x);
    cout << caracter;
}

void borrarCaracter(int* x, int* y) {
    mostrarCaracter(x, y, ' ');
}

void simularJuego() {
    int *x = new int, *y = new int;
    char* tecla = new char;
    int* fila = new int;

    *x = ALTO - 1; *y = ANCHO / 2;
    mostrarCaracter(x, y, TANQUE);

    while (1) {
        if (_kbhit()) {
            *tecla = _getch();
            if (*tecla == BARRA_ESPACIADORA) {
                for (*fila = *x - 1; *fila >= 0; --(*fila)) {
                    mostrarCaracter(fila, y, BALA);
                    Sleep(300);
                    borrarCaracter(fila, y);
                }
            }
            else if (*tecla == FLECHA_IZQUIERDA) {
                borrarCaracter(x, y);
                if (*y > 0) (*y)--;
                mostrarCaracter(x, y, TANQUE);
            }
            else if (*tecla == FLECHA_DERECHA) {
                // Ejercicio: Completar movimiento a la derecha
            }
        }
    }
    delete x;
    delete y;
    delete tecla;
    delete fila;
}
