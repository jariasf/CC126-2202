#include <iostream>
#include "mazegen.hpp"

using namespace std;
using namespace System;

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

#define ANCHO_CONSOLA 91
#define ALTO_CONSOLA 45

void configurar();
void colorear(int);
void gotoxy(int, int);
void graficarLaberinto(int**, int, int);

int main() {
    configurar();
    srand(time(NULL));

    // Establecer alto y ancho (predeterminado: alto y ancho de la consola)
    int alto{ALTO_CONSOLA}, ancho{ANCHO_CONSOLA};
    int alto_celda{3}, ancho_celda{5};

    // Tamaños recomendados para generar. Puede establecer cualquier alto y ancho
    // pero en algunos casos los espacios vacíos en el laberinto generado pueden 
    // ser más grandes. Por lo tanto, se recomienda utilizar los tamaños sugeridos
    //MazeGenerator::recommendSizes(alto_celda, ancho_celda, 20);

    // Generar laberinto
    int** laberinto = MazeGenerator::generateMaze(alto, ancho, alto_celda, ancho_celda);

    // Exportar el laberinto generado a un archivo .csv o .txt
    //MazeGenerator::exportMaze(laberinto, alto, ancho, MazeGenerator::Format::CSV, "maze");
    
    // Mostrar laberinto generado usando proyecto CLR
    graficarLaberinto(laberinto, alto, ancho);

    // Liberar memoria de laberinto generado
    for (int i = 0; i < alto; ++i) {
        delete[] laberinto[i];
    }
    delete[] laberinto;
    system("pause>0");
    return 0;
}

void configurar() {
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

void gotoxy(int x, int y) {
    Console::SetCursorPosition(y, x);
}

void colorear(int color) {
    Console::ForegroundColor = (ConsoleColor)color;
}

void graficarLaberinto(int** laberinto, int height, int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            gotoxy(i, j);
            if (laberinto[i][j] == 1) colorear(RED);
            else if (laberinto[i][j] == 0) colorear(BLACK);
            cout << (char)219;
        }
    }
}