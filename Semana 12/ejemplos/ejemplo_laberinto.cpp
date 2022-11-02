#include <iostream>
using namespace std;
using namespace System;

#define ANCHO_CONSOLA 50
#define ALTO_CONSOLA 30
#define FILAS 14
#define COLUMNAS 21

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
void mostrarLaberinto(int laberinto[FILAS][COLUMNAS]);
void gotoxy(int, int);
void colorear(int);

int main() {
    configurar();

    /*int laberinto[FILAS][COLUMNAS] = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 0, 2, 0, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1}
    };*/
    int laberinto[FILAS][COLUMNAS] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1},
        {1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
        {1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
        {1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
        {1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
        {1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    mostrarLaberinto(laberinto);

    system("pause>0");

    return 0;
}


void mostrarLaberinto(int laberinto[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            gotoxy(i, j);
            if (laberinto[i][j] == 1) colorear(RED);
            else if (laberinto[i][j] == 0) colorear(BLACK);
            else if (laberinto[i][j] == 2) colorear(GREEN);
            cout << (char)219;
        }
    }
}

void gotoxy(int x, int y) {
    Console::SetCursorPosition(y, x);
}

void colorear(int color) {
    Console::ForegroundColor = (ConsoleColor)color;
}

void configurar() {
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}