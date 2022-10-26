#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
#define ANCHO 50 //[0,49]
#define ALTO 30  //[0,29]
#define CARACTER '*'
#define ROJO 12

void configurar();
void simularDescensoDeCaracter();
void mostrarCaracter(int, int, char, int);
void borrarCaracter(int, int);
void colorear(int);

int main() {
    configurar();
    simularDescensoDeCaracter();
    return 0;
}

void configurar() {
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
}

void colorear(int color) {
    Console::ForegroundColor = (ConsoleColor)color;
}

void mostrarCaracter(int x, int y, char c, int color) {
    if (x < 0 || y < 0 || x >= ALTO || y >= ANCHO) return;
    Console::SetCursorPosition(y, x);
    colorear(color);
    cout << c;
}

void borrarCaracter(int x, int y) {
    if (x < 0 || y < 0 || x >= ALTO || y >= ANCHO) return;
    Console::SetCursorPosition(y, x);
    cout << " ";
}

/*
 0 1 2 3 4 5 6 7 -> y
0
1            o
2      x       x
3
|
v
x

*/

void simularDescensoDeCaracter() {
    int x{1}, y{10}, dx{1}, dy{0};
    mostrarCaracter(x, y, CARACTER, ROJO);
    
    char tecla;
    bool mover_caracter{true};
    while (x < ALTO) {
        if (_kbhit()) {
            tecla = _getch();
            if (tecla == 'P') {
                mover_caracter = false;
            }
            else if (tecla == 'A') {
                mover_caracter = true;
            }
        }
        
        if (mover_caracter) {
            borrarCaracter(x, y);
            x += dx; y += dy;
            mostrarCaracter(x, y, CARACTER, ROJO);
        }
        _sleep(200);
    }
    char c = _getch();
}