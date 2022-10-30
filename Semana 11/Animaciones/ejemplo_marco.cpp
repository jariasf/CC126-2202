#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
using namespace System;

#define ANCHO_CONSOLA 50
#define ALTO_CONSOLA 30

enum {
    BLACK,
    DARKBLUE,
    DARKGREEN,
    DARKCYAN,
    DARKRED,
    DARKMAGENTA,
    DARKYELLOW,
    GRAY,
    DARKGRAY,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    YELLOW,
    WHITE
};

void configurar();
void colorear(int);
void mostrarMarco(int, int, int ,int, int);
void gotoxy(int, int);
void mostrarPrimeraPantalla();
void mostrarSegundaPantalla();

int main() {
    configurar();
    mostrarPrimeraPantalla();
    mostrarSegundaPantalla();
    char c = _getch();
    return 0;
}

void configurar() {
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

void gotoxy(int x, int y) {
    /*
        Función que encapsula el uso de SetCursorPosition
        - Posiciones: x->fila, y->columna
    */
    Console::SetCursorPosition(y, x);
}

void colorear(int color) {
    Console::ForegroundColor = (ConsoleColor)color;
}

void mostrarMarco(int x1, int y1, int x2, int y2, int color=WHITE) {
    /*
        Mostrar marco dados el extremo superior izquierdo (x1, y1) y
        el extremo inferior derecho (x2, y2). Se muestra incluyendo
        las coordenadas específicadas

        (x1, y1)  
             -------------------
            |                   |
            |                   |
            |                   |
            |                   |
             -------------------
                                (x2, y2)   

        También se puede cambiar el color. Puede modificarlo para
        usar otros caracteres
    */
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (i == x1 || i == x2 || j == y1 || j == y2) {
                // Si usa SetCursorPosition, recuerde que
                // primero van las columnas, luego las filas
                Console::SetCursorPosition(j, i);
                colorear(color);
                if (i == x1) cout << (char)220;
                else if (i == x2) cout << (char)223;
                else if (j == y1) cout << (char)219;
                else if (j == y2) cout << (char)219;
            }
        }
    }
}

void mostrarPrimeraPantalla() {
    Console::Clear();
    // Mostramos mensajes
    gotoxy(8, 10);
    colorear(RED);
    cout << "Primera Pantalla" << endl;

    gotoxy(15, 20);
    colorear(GREEN);
    cout << "Prueba de impresion" << endl;

    // Mostramos marco
    mostrarMarco(4, 4, ALTO_CONSOLA-5, ANCHO_CONSOLA-5);
    _sleep(3000);
}

void mostrarSegundaPantalla() {
    Console::Clear();
    
    // Mostramos mensajes
    gotoxy(8, 10);
    colorear(GRAY);
    cout << "Segunda Pantalla" << endl;

    // Mostramos marco
    mostrarMarco(5, 2, ALTO_CONSOLA/2, ANCHO_CONSOLA-5, BLUE);
}